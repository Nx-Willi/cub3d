/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:31:27 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/07 14:04:49 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_mlx(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx);
	mlx_destroy_window(mlx->mlx, mlx->window);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
}

void	exit_program(t_info *info, char *error, int status)
{
	if (info->mlx.mlx != NULL)
		free_mlx(&info->mlx);
	if (error != NULL)
		ft_putstr_fd(error, 2);
	exit(status);
}
