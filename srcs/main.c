/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:09:24 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/12 11:33:00 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//__>TEMPORARY_________________________________________________________________
// static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// static void	draw_shit(t_mlx *mlx)
// {
// 	int	x;
// 	int	y;

// 	x = mlx->win_width / 2 - 250;
// 	y = mlx->win_heigth / 2 - 250;
// 	while (x <= mlx->win_width / 2 + 250)
// 		my_mlx_pixel_put(&mlx->img, x++, y, 0x00FFFFFF);
// 	while (y <= mlx->win_heigth / 2 + 250)
// 		my_mlx_pixel_put(&mlx->img, x, y++, 0x00FFFFFF);
// 	while (x >= mlx->win_width / 2 - 250)
// 		my_mlx_pixel_put(&mlx->img, x--, y, 0x00FFFFFF);
// 	while (y >= mlx->win_heigth / 2 - 250)
// 		my_mlx_pixel_put(&mlx->img, x, y--, 0x00FFFFFF);
// 	x = mlx->win_width / 2;
// 	y = mlx->win_heigth / 2 - 50;
// 	while (y <= mlx->win_heigth / 2 + 50)
// 		my_mlx_pixel_put(&mlx->img, x, y++, 0x00FFFFFF);
// 	x = mlx->win_width / 2 - 50;
// 	y = mlx->win_heigth / 2;
// 	while (x <= mlx->win_width / 2 + 50)
// 		my_mlx_pixel_put(&mlx->img, x++, y, 0x00FFFFFF);
// }

// static void	draw_point(t_info *infos)
// {
// 	t_mlx	*mlx;

// 	mlx = &infos->mlx;
// 	mlx->img.img = mlx_new_image(mlx->mlx, mlx->win_width, mlx->win_heigth);
// 	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel,
// 			&mlx->img.line_length, &mlx->img.endian);
// 	draw_shit(mlx);
// 	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.img, 0, 0);
// }
//‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾

static void	init_mlx(t_info *infos)
{
	t_mlx	*mlx;

	mlx = &infos->mlx;
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		exit_program(infos, "Unable to init mlx!\n", EXIT_FAILURE);
	mlx_get_screen_size(mlx->mlx, &mlx->win_width, &mlx->win_heigth);
	mlx->window = mlx_new_window(mlx->mlx, mlx->win_width, mlx->win_heigth,
			"cub3D");
}

int	main(int args, char **argv)
{
	t_info	info;

	if (args != 2)
		return (ft_putstr_fd("Error\nUsage: ./cub3D \'map_name.cub\'\n",
				1), 1);
	if (!check_file(argv[1]))
		return (1);
	if (parser(&info, argv[1]) == FALSE)
		return (free_info_struct(&info), 2);
	print_info_struct(info);
	init_mlx(&info);
	draw_point(&info);
	handler_events(&info);
	mlx_loop(info.mlx.mlx);
	return (0);
}
