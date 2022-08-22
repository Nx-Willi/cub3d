/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 13:41:43 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/20 01:39:33 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	close_window(t_info *info)
{
	exit_program(info, NULL, EXIT_SUCCESS);
	return (0);
}

static int	handler_keypress(int keycode, t_info *info)
{
	t_move	*move;

	move = &info->game.move;
	if (keycode == KEY_ESC)
		exit_program(info, NULL, EXIT_SUCCESS);
	else if (keycode == KEY_LEFT)
		move->rot_left = TRUE;
	else if (keycode == KEY_RIGHT)
		move->rot_right = TRUE;
	else if (keycode == KEY_W)
		move->forward = TRUE;
	else if (keycode == KEY_A)
		move->left = TRUE;
	else if (keycode == KEY_S)
		move->backward = TRUE;
	else if (keycode == KEY_D)
		move->right = TRUE;
	return (0);
}

static int	handler_keyrelease(int keycode, t_info *info)
{
	t_move	*move;

	move = &info->game.move;
	if (keycode == KEY_LEFT)
		move->rot_left = FALSE;
	else if (keycode == KEY_RIGHT)
		move->rot_right = FALSE;
	else if (keycode == KEY_W)
		move->forward = FALSE;
	else if (keycode == KEY_A)
		move->left = FALSE;
	else if (keycode == KEY_S)
		move->backward = FALSE;
	else if (keycode == KEY_D)
		move->right = FALSE;
	return (0);
}

void	handler_events(t_info *info)
{
	mlx_hook(info->mlx.window, DestroyNotify, StructureNotifyMask,
		close_window, info);
	mlx_hook(info->mlx.window, KeyPress, KeyPressMask, handler_keypress, info);
	mlx_hook(info->mlx.window, KeyRelease, KeyReleaseMask, handler_keyrelease,
		info);
	mlx_loop_hook(info->mlx.mlx, do_raycasting, &info->game);
}
