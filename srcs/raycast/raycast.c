/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:56:20 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/16 19:52:50 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static void	prepare_new_img(t_info *infos)
{
	int	y;
	int	x;

	y = 0;
	while (y < infos->mlx.win_heigth)
	{
		x = 0;
		while (x < infos->mlx.win_width)
			my_mlx_pixel_put(&infos->mlx, x++, y, 0x00000000);
		y++;
	}
}

int	do_raycasting(t_info *infos)
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
	//check_for_moves(infos);
	prepare_new_img(infos);
	return (0);
}
