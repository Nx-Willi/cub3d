/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:19:58 by xle-baux          #+#    #+#             */
/*   Updated: 2022/08/13 12:08:39 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define CUBE_SIZE 20

static void	draw_cube(t_mlx *mlx, int start_x, int start_y, int type)
{
	int	x;
	int	y;

	x = start_x;
	y = start_y;
	while (y >= start_y - CUBE_SIZE)
	{
		x = start_x;
		while (x <= start_x + CUBE_SIZE)
		{
			 if (type == 3)
			 	my_mlx_pixel_put(mlx, x, y, 0x00FF0000);
			else if (type == IN)
				my_mlx_pixel_put(mlx, x, y, 0x00EDEDED);
			else if (type == WALL)
				my_mlx_pixel_put(mlx, x, y, 0x00707070);
			x++;
		}
		y--;
	}
}

void	minimap(t_info *infos)
{
	int		start_x;
	int		start_y;
	int		x;
	int		y;
	t_mlx	*mlx;

	start_x = 0;
	start_y = infos->mlx.win_heigth - (infos->len_y * CUBE_SIZE) - 100;
	y = 0;
	mlx = &infos->mlx;
	mlx->img.img = mlx_new_image(mlx->mlx, mlx->win_width, mlx->win_heigth);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel,
			&mlx->img.line_length, &mlx->img.endian);
	while (infos->i_map[y] != NULL)
	{
		printf("y = %i\n", y);
		x = 0;
		while (infos->i_map[y][x] != TAB_NULL)
		{
			if (x == infos->start_x && y == infos->start_y)
				draw_cube(mlx, start_x + (x * CUBE_SIZE), start_y + (y * CUBE_SIZE), 3);
			else
				draw_cube(mlx, start_x + (x * CUBE_SIZE), start_y + (y * CUBE_SIZE), infos->i_map[y][x]);
			printf(". ");
			x++;
		}
		y++;
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.img, 0, 0);
	}
	
}
