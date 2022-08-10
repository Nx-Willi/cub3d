/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:11:31 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/10 17:00:41 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_info_struct(t_info *info)
{
	int	i;

	i = 0;
	free(info->textures[T_NO]);
	free(info->textures[T_SO]);
	free(info->textures[T_WE]);
	free(info->textures[T_EA]);
	while (info->map[i])
	{
		free(info->map[i]);
		i++;
	}
	free(info->map);
}

void	free_mlx(t_mlx *mlx)
{
	mlx_loop_end(mlx->mlx);
	mlx_destroy_window(mlx->mlx, mlx->window);
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
}

void	free_int_tab(int **tab, int *limit)
{
	int	i;

	i = -1;
	if (limit != NULL)
	{
		while (tab[++i] != NULL && i < *limit)
			free(tab[i]);
	}
	else
		while (tab[++i] != NULL)
			free(tab[i]);
	free(tab);
}
