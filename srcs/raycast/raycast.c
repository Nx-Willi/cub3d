/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:56:20 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/19 22:29:00 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	prepare_new_img(t_info *infos)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	while (y < infos->mlx.win_heigth)
// 	{
// 		x = 0;
// 		while (x < infos->mlx.win_width)
// 			my_mlx_pixel_put(&infos->mlx, x++, y, 0x00000000);
// 		y++;
// 	}
// }

int	do_raycasting(t_game *game)
{
	int	x;

	x = -1;
	while (++x < game->infos->mlx.win_width)
	{
		ray_calculs(game, x);
		get_step_for_ray(game);
		get_next_hitten_wall(game);
		get_wall_and_draw_distance(game);
		draw_wall_line(game->infos, x);
	}
	mlx_put_image_to_window(game->infos->mlx.mlx, game->infos->mlx.window,
		game->infos->mlx.img.img, 0, 0);
	check_for_moves(game->infos);
	// prepare_new_img(infos);
	return (0);
}
