/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:09:24 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/06 14:21:07 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int args, char **argv)
{
	t_info	info;

	if (args != 2)
		return (ft_putstr_fd("Error\n", 1), 1);
	info = parser(argv[1]);
	if (info.test == 1)
		return (1);
	return (0);
}
