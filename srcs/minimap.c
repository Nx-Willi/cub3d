/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:19:58 by xle-baux          #+#    #+#             */
/*   Updated: 2022/08/12 11:47:41 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
 */
static void	draw_cube(t_mlx *mlx, int start_x, int start_y)
{
	int	x;
	int	y;

	x = start_x;
	y = start_y;
	while (y >= start_y - 10)
	{
		printf("toto");
		x = start_x;
		while (x <= start_x + 10)
			my_mlx_pixel_put(mlx, x++, y, 0x00FFFFFF);
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
	start_y = infos->mlx.win_heigth - 100;
	x = 0;
	y = -1;
	mlx = &infos->mlx;
	mlx->img.img = mlx_new_image(mlx->mlx, mlx->win_width, mlx->win_heigth);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel,
			&mlx->img.line_length, &mlx->img.endian);
	while (infos->i_map[++y])
	{
		while (infos->i_map[y][x++])
			draw_cube(mlx, start_x + (x * 10), start_y - (y * 10));
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.img, 0, 0);
}
