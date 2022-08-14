/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:56:20 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/14 16:01:44 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	initalize_variables(t_game *game)
{
	game->ray.init_pos_x = game->infos->start_x + 0.5;
	game->ray.init_pos_y = game->infos->start_y + 0.5;
	get_initial_vector_direction(game);
	game->planepos_x = 0;
	game->planepos_y = 0.66;
}

static void	draw_vertical_line(t_info *infos, int x, t_draw *draw, int color)
{
	int	y;

	y = draw->startdraw;
	while (y < draw->enddraw)
	{
		my_mlx_pixel_put(&infos->mlx, x, y, color);
		y++;
	}
}

void	do_raycasting(t_info *infos)
{
	int		color;
	int		x;
	t_game	*game;

	infos->game.infos = infos;
	game = &infos->game;
	initalize_variables(game);
	x = -1;
	while (++x < infos->mlx.win_width)
	{
		ray_calculs(game, x);
		get_step_for_ray(game);
		get_next_hitten_wall(game);
		get_wall_and_draw_distance(game);
		if (infos->i_map[game->ray.pos_y][game->ray.pos_x] == -1)
			color = 0x00FF0000;
		else if (infos->i_map[game->ray.pos_y][game->ray.pos_x] == 1)
			color = 0x000000FF;
		draw_vertical_line(infos, x, &game->draw, color);
		mlx_put_image_to_window(infos->mlx.mlx, infos->mlx.window,
			infos->mlx.img.img, 0, 0);
	}
}
