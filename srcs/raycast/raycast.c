/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:56:20 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/12 15:32:07 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	initalize_variables(t_game *game)
{
	game->player.posX = game->infos->start_x;
	game->player.posY = game->infos->start_y;
	printf("%i, %i\n", game->player.posX, game->player.posY);
	get_initial_vector_direction(game);
	game->planePosX = 0;
	game->planePosY = 0.66;
}

static void	draw_vertical_line(t_info *infos, int x, t_draw *draw, int color)
{
	int	y;

	y = draw->startDraw;
	while (y < draw->endDraw)
	{
		my_mlx_pixel_put(&infos->mlx, x, y, color);
		y++;
	}
}

void	do_raycasting(t_info *infos)
{
	int		color;
	int		x;
	int		width;
	t_game	*game;

	infos->i_map[4][6] = 2;
	infos->game.infos = infos;
	game = &infos->game;
	initalize_variables(game);
	width = infos->mlx.win_width;
	x = -1;
	while (++x < width)
	{
		ray_calculs(game, x);
		get_step_for_ray(game);
		get_next_hitten_wall(game);
		get_wall_and_draw_distance(game);
		if (infos->i_map[game->mapY][game->mapX] == -1 || infos->i_map[game->mapY][game->mapX] == 2)
		{
			printf("red\n");
			color = 0x00FF0000;
		}
		else if (infos->i_map[game->mapY][game->mapX] == 1)
			color = 0x0000FF00;
		draw_vertical_line(infos, x, &game->draw, color);
	}
	mlx_put_image_to_window(infos->mlx.mlx, infos->mlx.window,
		infos->mlx.img.img, 0, 0);
}