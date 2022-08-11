/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:37:33 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/11 17:12:29 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_ray_values(t_game *game, int x)
{
	game->camX = 2 * x / game->infos->mlx.win_width - 1;
	game->ray.rayDirX = game->ray.vecDirX + game->plane.posX
		* game->camX;
	game->ray.rayDirY = game->ray.vecDirY + game->plane.posY
		* game->camX;
	game->player.posX = game->player.initX;
	game->player.posY = game->player.initY;
	game->ray.deltaDistX = fabs(1 / game->ray.rayDirX);
	game->ray.deltaDistY = fabs(1 / game->ray.rayDirY);
}

// Check what wall direction we hit, the step refers to it
// NO => x + 1, SU => x - 1, WE => y - 1, ES => y + 1
static void	get_step(t_game	*game)
{
	if (game->ray.rayDirX < 0)
	{
		game->ray.stepX = -1;
		game->ray.sideDistX = (game->player.posX - game->player.initX)
			* game->ray.deltaDistX;
	}
	else
	{
		game->ray.stepX = 1;
		game->ray.sideDistX = (game->player.initX + 1.0 - game->player.posX)
			* game->ray.deltaDistX;
	}
	if (game->ray.rayDirY < 0)
	{
		game->ray.stepY = -1;
		game->ray.sideDistY = (game->player.posY - game->player.initY)
			* game->ray.deltaDistY;
	}
	else
	{
		game->ray.stepY = 1;
		game->ray.sideDistY = (game->player.initY + 1.0 - game->player.posY)
			* game->ray.deltaDistY;
	}
}

static void	get_distance_from_wall(t_game *game)
{
	int	hit;

	game->map_posX = (int)game->player.posX;
	game->map_posY = (int)game->player.posY;
	hit = FALSE;
	while (hit == FALSE)
	{
		if (game->ray.sideDistX < game->ray.sideDistY)
		{
			game->ray.sideDistX += game->ray.deltaDistX;
			game->map_posX += game->ray.stepX;
			game->ray.side = FALSE;
		}
		else
		{
			game->ray.sideDistY += game->ray.deltaDistY;
			game->map_posY += game->ray.stepY;
			game->ray.side = TRUE;
		}
		if (game->infos->i_map[game->map_posX][game->map_posY] > 0)
			break;
	}
}

static void	get_line_coordinates(t_game *game)
{
	int	lineHeight;
	int	height = game->infos->mlx.win_heigth;

	lineHeight = game->infos->mlx.win_heigth / game->ray.perpWallDist;
	game->draw.Xstart = -lineHeight / 2 + height / 2;
	if (game->draw.Xstart < 0)
		game->draw.Xstart = 0;
	game->draw.Xend = lineHeight / 2 + height / 2;
	if (game->draw.Xend >= height)
		game->draw.Xend = height - 1;
}

static void	print_line(t_game *game, int y)
{
	(void)y;
	int		x;
	t_draw	*draw;

	draw = &(game->draw);
	x = draw->Xstart;
	while (x >= draw->Xend)
	{
		my_mlx_pixel_put(&game->infos->mlx, x, x, 0x00FFFFFF);
		x--;
	}
}

void	do_raycasting(t_info *infos)
{
	int			x;
	t_game		*game;

	init_player(infos);
	init_plane(infos);
	game = &(infos->game);
	// May mlx_loop doesn't reach
	int y = 0;
	while (y < 50)
	{
		x = -1;
		while (++x < infos->mlx.win_width)
		{
			init_ray_values(game, x);
			get_step(game);
			get_distance_from_wall(game);
			if (game->ray.side == FALSE)
				game->ray.perpWallDist = game->ray.sideDistX - game->ray.deltaDistX;
			else
				game->ray.perpWallDist = game->ray.sideDistY - game->ray.deltaDistY;
			get_line_coordinates(game);
			print_line(game, x);
		}
		mlx_put_image_to_window(infos->mlx.mlx, infos->mlx.window, infos->mlx.img.img, 0, 0);
	}
}
