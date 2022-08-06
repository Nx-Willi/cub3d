/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 10:18:54 by xle-baux          #+#    #+#             */
/*   Updated: 2022/08/06 10:21:35 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_info_struct(t_info info)
{
	printf("NO: %s\n", info.no_texture);
	printf("SO: %s\n", info.so_texture);
	printf("WE: %s\n", info.we_texture);
	printf("EA: %s\n", info.ea_texture);
}