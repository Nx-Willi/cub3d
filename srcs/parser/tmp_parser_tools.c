/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_parser_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 10:18:54 by xle-baux          #+#    #+#             */
/*   Updated: 2022/08/10 13:03:45 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_info_struct(t_info info)
{
	int	i;

	i = 0;
	printf("NO:\t\t%s", info.textures[T_NO]);
	printf("SO:\t\t%s", info.textures[T_SO]);
	printf("WE:\t\t%s", info.textures[T_WE]);
	printf("EA:\t\t%s\n", info.textures[T_EA]);
	printf("Floor Color:\tr=%i g=%i b=%i\n", info.floor_color.r, info.floor_color.g, info.floor_color.b);
	printf("Ceilling Color:\tr=%i g=%i b=%i\n\n", info.ceilling_color.r, info.ceilling_color.g, info.ceilling_color.b);
	while (info.map[i])
	{
		printf("%s", info.map[i++]);
	}
}
