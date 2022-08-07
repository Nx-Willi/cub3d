/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:09:24 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/07 14:00:16 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static void draw_point(t_info *infos)
{
    t_mlx	*mlx;

	mlx = &infos->mlx;
    mlx->img.img = mlx_new_image(mlx->mlx, 1920, 1080);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, &mlx->img.line_length,
								&mlx->img.endian);
	my_mlx_pixel_put(&mlx->img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.img, 0, 0);
}
//‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾

static void	init_mlx(t_info *infos)
{
	t_mlx	*mlx;

	mlx = &infos->mlx;
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		exit_program(infos, "Unable to init mlx!\n", EXIT_FAILURE);
    mlx->window = mlx_new_window(mlx->mlx, 1920, 1080, "cub3D");
}

int	main(int args, char **argv)
{
	t_info	info;

	if (args != 2)
		return (ft_putstr_fd("Error\nUsage: ./cub3D \'maps.cub\'\n", 1), 1);
	if (!check_file(argv[1]))
		return (1);
	if (parser(&info, argv[1]) == FALSE)
		return (2);
	init_mlx(&info);
    draw_point(&info);
    mlx_loop(info.mlx.mlx);
	return (0);
}
