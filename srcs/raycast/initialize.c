/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:05:21 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/12 15:25:19 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// a vector shows the direction in a plane with coordinates x and y as,
// if a vector goes to North, the y will increase of one, in south it'll
// decrease.
// same thing for the direction East and West with the x coordinate.
void	get_initial_vector_direction(t_game *game)
{
	int		orientation;

	orientation = game->infos->start_orientation;
	if (orientation == NO || orientation == SO)
	{
		game->ray.vecDirX = 0;
		if (orientation == NO)
			game->ray.vecDirY = 1;	
		else
			game->ray.vecDirY = -1;
	}
	else if (orientation == WE || orientation == EA)
	{
		if (orientation == WE)
			game->ray.vecDirX = -1;
		else
			game->ray.vecDirX = 1;
		game->ray.vecDirY = 0;
	}
}

void	ray_calculs(t_game *game, int x)
{
	game->camX = 2 * x / game->infos->mlx.win_width - 1;
	game->ray.rayDirX = game->ray.vecDirX + game->planePosX
		* game->camX;
	game->ray.rayDirY = game->ray.vecDirY + game->planePosY
		* game->camX;
	game->mapX = (int)game->player.posX;
	game->mapY = (int)game->player.posY;
	game->ray.deltaDistX = sqrt(1 + (game->ray.rayDirY * game->ray.rayDirY)
			/ (game->ray.rayDirX * game->ray.rayDirX));
	game->ray.deltaDistY = sqrt(1 + (game->ray.rayDirX * game->ray.rayDirX)
			/ (game->ray.rayDirY * game->ray.rayDirY));
}

void	get_step_for_ray(t_game *game)
{
	if (game->ray.rayDirX < 0)
	{
		game->ray.stepX = -1;
		game->ray.sideDistX = (game->player.posX - game->mapX)
			* game->ray.deltaDistX;
	}
	else
	{
		game->ray.stepX = 1;
		game->ray.sideDistX = (game->mapX + 1.0 - game->player.posX)
			* game->ray.deltaDistX;
	}
	if (game->ray.rayDirY < 0)
	{
		game->ray.stepY = -1;
		game->ray.sideDistY = (game->player.posY - game->mapY)
			* game->ray.deltaDistY;
	}
	else
	{
		game->ray.stepY = 1;
		game->ray.sideDistY = (game->mapY + 1.0 - game->player.posY)
			* game->ray.deltaDistY;
	}
}

void	get_next_hitten_wall(t_game *game)
{
	int	hit;

	hit = FALSE;
	while (hit == FALSE)
	{
		if (game->ray.sideDistX < game->ray.sideDistY)
		{
			game->ray.sideDistX += game->ray.deltaDistX;
			game->mapX += game->ray.stepX;
			game->ray.side = FALSE;
		}
		else
		{
			game->ray.sideDistY += game->ray.deltaDistY;
			game->mapY += game->ray.stepY;
			game->ray.side = TRUE;
		}
		if (game->infos->i_map[game->mapY][game->mapX] > 0)
			hit	= TRUE;
	}
}

void	get_wall_and_draw_distance(t_game *game)
{
	int	line_height;

	if (game->ray.side == FALSE)
		game->ray.perpWallDist = game->ray.sideDistX - game->ray.deltaDistX;
	else
		game->ray.perpWallDist = game->ray.sideDistY - game->ray.deltaDistY;
	line_height = game->infos->mlx.win_heigth / game->ray.perpWallDist;
	game->draw.startDraw = -line_height / 2 + game->infos->mlx.win_heigth / 2;
	if (game->draw.startDraw < 0)
		game->draw.startDraw = 0;
	game->draw.endDraw = line_height / 2 + game->infos->mlx.win_heigth / 2;
	if (game->draw.endDraw >= game->infos->mlx.win_heigth)
		game->draw.endDraw = game->infos->mlx.win_heigth - 1;
}
