/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:14:10 by xle-baux          #+#    #+#             */
/*   Updated: 2022/09/07 12:27:05 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_cube_size(t_mlx *mlx, t_info *infos)
{
	int	max_map_size;
	int	cube_size;

	max_map_size = mlx->win_width / 5;
	cube_size = 1;
	while (((infos->map_width * cube_size) < max_map_size)
		&& ((infos->map_height * cube_size) < max_map_size))
		cube_size++;
	return (cube_size);
}

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
	int	cube_size;

	x = start_x;
	y = start_y;
	cube_size = get_cube_size(mlx, mlx->infos);
	while (y >= start_y - cube_size)
	{
		x = start_x;
		while (x <= start_x + cube_size)
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

void	init_minimap(t_info *infos)
{
	int		cube_size;
	t_mlx	*mlx;

	mlx = &infos->mlx;
	cube_size = get_cube_size(&infos->mlx, infos);
	mlx->img_minimap.img = mlx_new_image(mlx->mlx, infos->map_width
			* cube_size, infos->map_height * cube_size);
	mlx->img_minimap.addr = mlx_get_data_addr(mlx->img_minimap.img,
			&mlx->img_minimap.bits_per_pixel,
			&mlx->img_minimap.line_length,
			&mlx->img_minimap.endian);
}

void	minimap(t_info *infos)
{
	int		x;
	int		y;
	int		cube_size;
	t_mlx	*mlx;

	cube_size = get_cube_size(&infos->mlx, infos);
	mlx = &infos->mlx;
	y = -1;
	while (infos->i_map[++y] != NULL)
	{
		x = -1;
		while (infos->i_map[y][++x] != TAB_NULL)
		{
			if (x == (int)infos->game.ray.map_x
				&& y == (int)infos->game.ray.map_y)
				draw_cube(mlx, (x * cube_size), cube_size + (y * cube_size), 3);
			else
				draw_cube(mlx, (x * cube_size), cube_size + (y * cube_size),
					infos->i_map[y][x]);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img_minimap.img,
		10, mlx->win_heigth
		- (infos->map_height * cube_size) - 10);
}
