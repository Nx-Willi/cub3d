/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:09:24 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/15 12:12:24 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_mlx(t_info *infos)
{
	t_mlx	*mlx;

	mlx = &infos->mlx;
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		exit_program(infos, "Unable to init mlx!\n", EXIT_FAILURE);
	mlx_get_screen_size(mlx->mlx, &mlx->win_width, &mlx->win_heigth);
	// mlx->win_width -= 800;
	// mlx->win_heigth -= 500;
	mlx->win_width = 1920;
	mlx->win_heigth = 1080;
	mlx->window = mlx_new_window(mlx->mlx, mlx->win_width, mlx->win_heigth,
			"cub3D");
	mlx->img.img = mlx_new_image(mlx->mlx, mlx->win_width, mlx->win_heigth);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel,
			&mlx->img.line_length, &mlx->img.endian);
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
	handler_events(&info);
	info.game.infos = &info;
	initalize_variables(&info.game);
	do_raycasting(&info);
	mlx_loop(info.mlx.mlx);
	return (0);
}
