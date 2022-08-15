/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 13:41:43 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/15 15:31:01 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_handler(int keycode, t_info *info)
{
	if (keycode == KEY_ESC)
		exit_program(info, NULL, EXIT_SUCCESS);
//TMP, have to be in key_press | release when it'll be faster
	t_game	*game;

	game = &info->game;
	if (keycode == KEY_W)
	{
		double	speed = 0.8;
		if (info->i_map[(int)game->ray.init_pos_y]
			[(int)(game->ray.init_pos_x + game->ray.vecdir_x * speed)] == 0)
			game->ray.init_pos_x += game->ray.vecdir_x * speed;
		if (info->i_map[(int)(game->ray.init_pos_y +
			game->ray.vecdir_y * speed)][(int)game->ray.init_pos_x] == 0)
			game->ray.init_pos_y += game->ray.vecdir_y * speed;
		do_raycasting(info);
	}
//--
	return (0);
}

static int	close_window(t_info *info)
{
	exit_program(info, NULL, EXIT_SUCCESS);
	return (0);
}

// static int	handler_keypress(int keycode, t_info *info)
// {
// 	(void)info;
// 	printf("pressed key: %i\n", keycode);
// 	return (0);
// }

// static int	handler_keyrelease(int keycode, t_info *info)
// {
// 	(void)info;
// 	printf("release key: %i\n", keycode);
// 	return (0);
// }

void	handler_events(t_info *info)
{
	// mlx_hook(info->mlx.window, KeyPress, KeyPressMask, handler_keypress, info);
	// mlx_hook(info->mlx.window, KeyRelease, KeyReleaseMask, handler_keyrelease,
	// 	info);
	mlx_hook(info->mlx.window, DestroyNotify, StructureNotifyMask,
		close_window, info);
	mlx_key_hook(info->mlx.window, key_handler, info);
	// mlx_look_hook(info.mlx.mlx, do_raycasting, &info);
}
