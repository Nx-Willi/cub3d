/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:56:20 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/15 12:32:25 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initalize_variables(t_game *game)
{
	game->ray.init_pos_x = game->infos->start_x + 0.5;
	game->ray.init_pos_y = game->infos->start_y + 0.5;
	game->ray.vecdir_x = 0;
	game->ray.vecdir_y = 0;
	game->planepos_x = 0;
	game->planepos_y = 0;
	if (game->infos->start_orientation == NO)
		game->planepos_x = 0.66;
	else if (game->infos->start_orientation == SO)
		game->planepos_x = -0.66;
	else if (game->infos->start_orientation == EA)
		game->planepos_y = 0.66;
	else if (game->infos->start_orientation == WE)
		game->planepos_y = -0.66;
	get_initial_vector_direction(game);
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

	game = &infos->game;
	x = -1;
	while (++x < infos->mlx.win_width)
	{
		ray_calculs(game, x);
		get_step_for_ray(game);
		get_next_hitten_wall(game);
		get_wall_and_draw_distance(game);
		if (infos->i_map[game->ray.pos_y][game->ray.pos_x] == -1)
			color = 0x00FFCC66;
		else if (infos->i_map[game->ray.pos_y][game->ray.pos_x] == 1)
			color = 0x00FFB31A;
		draw_vertical_line(infos, x, &game->draw, color);
		mlx_put_image_to_window(infos->mlx.mlx, infos->mlx.window,
			infos->mlx.img.img, 0, 0);
	}
}
