/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 13:41:43 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/07 15:37:32 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_handler(int keycode, t_info *info)
{
	if (keycode == KEY_ESC)
		exit_program(info, NULL, EXIT_SUCCESS);
	return (0);
}

static int	close_window(t_info *info)
{
	exit_program(info, NULL, EXIT_SUCCESS);
	return (0);
}

void	handler_events(t_info *info)
{
	mlx_key_hook(info->mlx.window, key_handler, info);
	mlx_hook(info->mlx.window, DESTROYNOTIFY, STRUCTNOTIFYMASK,
		close_window, info);
}
