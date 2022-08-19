/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:11:31 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/17 16:25:56 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_info_struct(t_info *info)
{
	int	i;

	i = -1;
	while (++i < 4)
		free(info->textures[i]);
}

void	free_char_char(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_mlx(t_mlx *mlx)
{
	int	i;

	mlx_loop_end(mlx->mlx);
	mlx_destroy_window(mlx->mlx, mlx->window);
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	i = -1;
	while (++i < 4)
		if (mlx->infos->game.textures[i].img != NULL)
			mlx_destroy_image(mlx->mlx, mlx->infos->game.textures[i].img);
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
