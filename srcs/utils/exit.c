/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:31:27 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/07 16:42:42 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// tmp: mlx_destroy_image
static void	free_mlx(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx);
	mlx_destroy_window(mlx->mlx, mlx->window);
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
}

void	free_info_struct(t_info *info)
{
	free(info->no_texture);
	free(info->so_texture);
	free(info->we_texture);
	free(info->ea_texture);
}

void	exit_program(t_info *info, char *error, int status)
{
	if (info->mlx.mlx != NULL)
		free_mlx(&info->mlx);
	free_info_struct(info);
	if (error != NULL)
		ft_putstr_fd(error, 2);
	exit(status);
}
