/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:09:24 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/06 16:59:04 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_mlx(t_info *infos)
{
	t_mlx	*mlx;

	mlx = &infos->mlx;
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		exit_program("Unable to find environment!\n", EXIT_FAILURE);
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
	return (0);
}
