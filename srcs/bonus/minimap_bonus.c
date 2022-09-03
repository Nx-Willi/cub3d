/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:14:10 by xle-baux          #+#    #+#             */
/*   Updated: 2022/09/03 12:02:34 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define CUBE_SIZE 5

static void	put_pixel_color(t_mlx *mlx, int x, int y, int trgb)
{
	mlx->img_minimap.addr[y * mlx->img_minimap.line_length
		+ x * mlx->img_minimap.bits_per_pixel / 8 + 2] = (trgb >> 16) & 0xFF;
	mlx->img_minimap.addr[y * mlx->img_minimap.line_length
		+ x * mlx->img_minimap.bits_per_pixel / 8 + 1] = (trgb >> 8) & 0xFF;
	mlx->img_minimap.addr[y * mlx->img_minimap.line_length
		+ x * mlx->img_minimap.bits_per_pixel / 8] = trgb & 0xFF;
}

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
				put_pixel_color(mlx, x, y, 0x00FF0000);
			else if (type == IN)
				put_pixel_color(mlx, x, y, 0x00000000);
			else if (type == WALL)
				put_pixel_color(mlx, x, y, 0x00C0C0C0);
			x++;
		}
		y--;
	}
}

static void	get_minimap_size(t_info *infos, int len_map[2])
{
	int	i;

	i = 0;
	while (infos->i_map[0][i] != TAB_NULL)
		i++;
	len_map[0] = i;
	i = 0;
	while (infos->i_map[i] != NULL)
		i++;
	len_map[1] = i;
}

void	init_minimap(t_info *infos)
{
	int		len_map[2];
	t_mlx	*mlx;

	mlx = &infos->mlx;
	get_minimap_size(infos, len_map);
	mlx->img_minimap.img = mlx_new_image(mlx->mlx, len_map[0]
			* CUBE_SIZE, len_map[1] * CUBE_SIZE);
	mlx->img_minimap.addr = mlx_get_data_addr(mlx->img_minimap.img,
			&mlx->img_minimap.bits_per_pixel,
			&mlx->img_minimap.line_length,
			&mlx->img_minimap.endian);
}

void	minimap(t_info *infos)
{
	int		x;
	int		y;
	int		len_map[2];
	t_mlx	*mlx;

	get_minimap_size(infos, len_map);
	mlx = &infos->mlx;
	y = -1;
	while (infos->i_map[++y] != NULL)
	{
		x = -1;
		while (infos->i_map[y][++x] != TAB_NULL)
		{
			if (x == (int)infos->game.ray.map_x
				&& y == (int)infos->game.ray.map_y)
				draw_cube(mlx, (x * CUBE_SIZE), CUBE_SIZE + (y * CUBE_SIZE), 3);
			else
				draw_cube(mlx, (x * CUBE_SIZE), CUBE_SIZE + (y * CUBE_SIZE),
					infos->i_map[y][x]);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img_minimap.img,
		mlx->win_width - (len_map[0] * CUBE_SIZE) - 10, mlx->win_heigth
		- (len_map[1] * CUBE_SIZE) - 10);
}
