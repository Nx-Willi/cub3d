/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 13:41:43 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/16 18:11:13 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	do_movement(int keycode, t_info *info);
void	do_rotation(int keycode, t_info *info);

static int	key_handler(int keycode, t_info *info)
{
	if (keycode == KEY_ESC)
		exit_program(info, NULL, EXIT_SUCCESS);
	else
		do_movement(keycode, info);
	return (0);
}

static int	close_window(t_info *info)
{
	exit_program(info, NULL, EXIT_SUCCESS);
	return (0);
}

//TMP, have to be in key_press | release when it'll be faster-------------------
void	do_movement(int keycode, t_info *info)
{
	t_game	*game;

	game = &info->game;
	if (keycode == KEY_W)
	{
		if (info->i_map[(int)game->ray.init_pos_y]
			[(int)(game->ray.init_pos_x + game->ray.vecdir_x * SPEED)] == 0)
			game->ray.init_pos_x += game->ray.vecdir_x * SPEED;
		if (info->i_map[(int)(game->ray.init_pos_y +
			game->ray.vecdir_y * SPEED)][(int)game->ray.init_pos_x] == 0)
			game->ray.init_pos_y += game->ray.vecdir_y * SPEED;
		do_raycasting(info);
	}
	else if (keycode == KEY_S)
	{
		if (info->i_map[(int)game->ray.init_pos_y]
			[(int)(game->ray.init_pos_x - game->ray.vecdir_x * SPEED)] == 0)
			game->ray.init_pos_x -= game->ray.vecdir_x * SPEED;
		if (info->i_map[(int)(game->ray.init_pos_y -
			game->ray.vecdir_y * SPEED)][(int)game->ray.init_pos_x] == 0)
			game->ray.init_pos_y -= game->ray.vecdir_y * SPEED;
		do_raycasting(info);
	}
	else if (keycode == KEY_A)
	{
		if (info->i_map[(int)game->ray.init_pos_y][(int)(game->ray.init_pos_x -
			game->ray.vecdir_y * SPEED)] == 0)
			game->ray.init_pos_x += game->ray.vecdir_y * SPEED;
		if (info->i_map[(int)(game->ray.init_pos_y + game->ray.vecdir_x *
			SPEED)][(int)game->ray.init_pos_x] == 0)
			game->ray.init_pos_y -= game->ray.vecdir_x * SPEED;
		do_raycasting(info);
	}
	else if (keycode == KEY_D)
	{
		if (info->i_map[(int)game->ray.init_pos_y][(int)(game->ray.init_pos_x -
			game->ray.vecdir_y * SPEED)] == 0)
			game->ray.init_pos_x -= game->ray.vecdir_y * SPEED;
		if (info->i_map[(int)(game->ray.init_pos_y + game->ray.vecdir_x *
			SPEED)][(int)game->ray.init_pos_x] == 0)
			game->ray.init_pos_y += game->ray.vecdir_x * SPEED;
		do_raycasting(info);
	}
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		do_rotation(keycode, info);
}

void	do_rotation(int keycode, t_info *info)
{
	double	old_vecdir_x;
	double	old_plane_x;
	t_game	*game;

	game = &info->game;
	old_vecdir_x = game->ray.vecdir_x;
	old_plane_x = game->planepos_x;
	if (keycode == KEY_LEFT)
	{
		game->ray.vecdir_x = game->ray.vecdir_x * cos(ROT_SPEED) -
			game->ray.vecdir_y * sin(ROT_SPEED);
		game->ray.vecdir_y = old_vecdir_x * sin(ROT_SPEED) +
			game->ray.vecdir_y + cos(ROT_SPEED);

		game->planepos_x = game->planepos_x * cos(ROT_SPEED) -
			game->planepos_y * sin(ROT_SPEED);
		game->planepos_y = old_plane_x * sin(ROT_SPEED) +
			game->planepos_y * cos(ROT_SPEED);
		do_raycasting(info);
	}
	else if (keycode == KEY_RIGHT)
	{
		game->ray.vecdir_x = game->ray.vecdir_x * cos(-ROT_SPEED) -
			game->ray.vecdir_y * sin(-ROT_SPEED);
		game->ray.vecdir_y = old_vecdir_x * sin(-ROT_SPEED) +
			game->ray.vecdir_y + cos(-ROT_SPEED);

		game->planepos_x = game->planepos_x * cos(-ROT_SPEED) -
			game->planepos_y * sin(-ROT_SPEED);
		game->planepos_y = old_plane_x * sin(-ROT_SPEED) +
			game->planepos_y * cos(-ROT_SPEED);
		do_raycasting(info);
	}
}
//------------------------------------------------------------------------------

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
