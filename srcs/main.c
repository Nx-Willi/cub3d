/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:09:24 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/20 05:08:15 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	tmp(t_info *infos)
// {
// 	int	i;
// //
// 	i = -1;
// 	while (++i < 4)
// 	{
// 		ft_strlcpy(infos->textures[i], infos->textures[i], ft_strlen(infos->textures[i]));
// 	}
// }

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
	info.game.infos = &info;
	init_ray_variables(&info.game);
	// tmp(&info);
	init_mlx(&info);
	do_raycasting(&info.game);
	handler_events(&info);
	mlx_loop(info.mlx.mlx);
	return (0);
}
