/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:42:45 by william           #+#    #+#             */
/*   Updated: 2022/08/16 19:53:08 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mlx(t_info *infos)
{
	t_mlx	*mlx;

	mlx = &infos->mlx;
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		exit_program(infos, "Unable to init mlx!\n", EXIT_FAILURE);
	mlx_get_screen_size(mlx->mlx, &mlx->win_width, &mlx->win_heigth);
	// mlx->win_width -= 800;
	// mlx->win_heigth -= 500;
	mlx->win_width = 640;
	mlx->win_heigth = 360;
	mlx->window = mlx_new_window(mlx->mlx, mlx->win_width, mlx->win_heigth,
			"cub3D");
	mlx->img.img = mlx_new_image(mlx->mlx, mlx->win_width, mlx->win_heigth);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel,
			&mlx->img.line_length, &mlx->img.endian);
	mlx->img.img_tmp = mlx_new_image(mlx->mlx, mlx->win_width, mlx->win_heigth);
	mlx->img.addr_tmp = mlx_get_data_addr(mlx->img.img_tmp,
			&mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
}

void	init_moves_variables(t_move *move)
{
	move->rot_right = FALSE;
	move->rot_left = FALSE;
	move->forward = FALSE;
	move->backward = FALSE;
	move->left = FALSE;
	move->right = FALSE;
}

void	init_ray_variables(t_game *game)
{
	game->ray.init_pos_x = game->infos->start_x + 0.5;
	game->ray.init_pos_y = game->infos->start_y + 0.5;
	game->ray.vecdir_x = 0;
	game->ray.vecdir_y = 0;
	game->planepos_x = 0;
	game->planepos_y = 0;
	if (game->infos->start_orientation == NO)
		game->planepos_x = 0.66;
	else if (game->infos->start_orientation == SO)
		game->planepos_x = -0.66;
	else if (game->infos->start_orientation == EA)
		game->planepos_y = 0.66;
	else if (game->infos->start_orientation == WE)
		game->planepos_y = -0.66;
	get_initial_vector_direction(game);
	init_moves_variables(&game->move);
}
