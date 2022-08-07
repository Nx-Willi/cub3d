/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:31:27 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/07 15:27:28 by xle-baux         ###   ########.fr       */
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

void	free_info_struct(t_info *info)
{
	free(info->no_texture);
	free(info->so_texture);
	free(info->we_texture);
	free(info->ea_texture);
}
