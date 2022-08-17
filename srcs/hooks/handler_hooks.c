/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 13:41:43 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/17 20:03:14 by william          ###   ########.fr       */
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

//TMP, just to show if the code works, it'll be managed by key_press, release,
//mlx_loop_hook and stuff in movements.c
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
		do_raycasting(game);
	}
	else if (keycode == KEY_S)
	{
		if (info->i_map[(int)game->ray.init_pos_y]
			[(int)(game->ray.init_pos_x - game->ray.vecdir_x * SPEED)] == 0)
			game->ray.init_pos_x -= game->ray.vecdir_x * SPEED;
		if (info->i_map[(int)(game->ray.init_pos_y -
			game->ray.vecdir_y * SPEED)][(int)game->ray.init_pos_x] == 0)
			game->ray.init_pos_y -= game->ray.vecdir_y * SPEED;
		do_raycasting(game);
	}
	else if (keycode == KEY_A)
	{
		if (info->i_map[(int)game->ray.init_pos_y][(int)(game->ray.init_pos_x -
			game->ray.vecdir_y * SPEED)] == 0)
			game->ray.init_pos_x += game->ray.vecdir_y * SPEED;
		if (info->i_map[(int)(game->ray.init_pos_y + game->ray.vecdir_x *
			SPEED)][(int)game->ray.init_pos_x] == 0)
			game->ray.init_pos_y -= game->ray.vecdir_x * SPEED;
		do_raycasting(game);
	}
	else if (keycode == KEY_D)
	{
		if (info->i_map[(int)game->ray.init_pos_y][(int)(game->ray.init_pos_x -
			game->ray.vecdir_y * SPEED)] == 0)
			game->ray.init_pos_x -= game->ray.vecdir_y * SPEED;
		if (info->i_map[(int)(game->ray.init_pos_y + game->ray.vecdir_x *
			SPEED)][(int)game->ray.init_pos_x] == 0)
			game->ray.init_pos_y += game->ray.vecdir_x * SPEED;
		do_raycasting(game);
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
		game->ray.vecdir_x = game->ray.vecdir_x * cos(ROTATE) -
			game->ray.vecdir_y * sin(ROTATE);
		game->ray.vecdir_y = old_vecdir_x * sin(ROTATE) +
			game->ray.vecdir_y + cos(ROTATE);

		game->planepos_x = game->planepos_x * cos(ROTATE) -
			game->planepos_y * sin(ROTATE);
		game->planepos_y = old_plane_x * sin(ROTATE) +
			game->planepos_y * cos(ROTATE);
		do_raycasting(game);
	}
	else if (keycode == KEY_RIGHT)
	{
		game->ray.vecdir_x = game->ray.vecdir_x * cos(-ROTATE) -
			game->ray.vecdir_y * sin(-ROTATE);
		game->ray.vecdir_y = old_vecdir_x * sin(-ROTATE) +
			game->ray.vecdir_y + cos(-ROTATE);

		game->planepos_x = game->planepos_x * cos(-ROTATE) -
			game->planepos_y * sin(-ROTATE);
		game->planepos_y = old_plane_x * sin(-ROTATE) +
			game->planepos_y * cos(-ROTATE);
		do_raycasting(game);
	}
}
//------------------------------------------------------------------------------

// static int	handler_keypress(int keycode, t_info *info)
// {
// 	t_move	*move;

// 	move = &info->game.move;
// 	if (keycode == KEY_LEFT)
// 		move->left = TRUE;
// 	else if (keycode == KEY_RIGHT)
// 		move->right = TRUE;
// 	else if (keycode == KEY_W)
// 		move->forward = TRUE;
// 	else if (keycode == KEY_A)
// 		move->left = TRUE;
// 	else if (keycode == KEY_S)
// 		move->backward = TRUE;
// 	else if (keycode == KEY_D)
// 		move->right = TRUE;
// 	return (0);
// }

// static int	handler_keyrelease(int keycode, t_info *info)
// {
// 	t_move	*move;

// 	move = &info->game.move;
// 	if (keycode == KEY_LEFT)
// 		move->left = FALSE;
// 	else if (keycode == KEY_RIGHT)
// 		move->right = FALSE;
// 	else if (keycode == KEY_W)
// 		move->forward = FALSE;
// 	else if (keycode == KEY_A)
// 		move->left = FALSE;
// 	else if (keycode == KEY_S)
// 		move->backward = FALSE;
// 	else if (keycode == KEY_D)
// 		move->right = FALSE;
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
