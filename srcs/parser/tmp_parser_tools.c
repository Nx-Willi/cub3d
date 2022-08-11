/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_parser_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 10:18:54 by xle-baux          #+#    #+#             */
/*   Updated: 2022/08/11 14:08:50 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_int_tab(int **tab);

void	print_info_struct(t_info info)
{
	int	i;

	i = 0;
	printf("NO:\t\t%s", info.textures[T_NO]);
	printf("SO:\t\t%s", info.textures[T_SO]);
	printf("WE:\t\t%s", info.textures[T_WE]);
	printf("EA:\t\t%s\n", info.textures[T_EA]);
	printf("Floor Color:\tr=%i g=%i b=%i\n",
		info.floor_color.r, info.floor_color.g, info.floor_color.b);
	printf("Ceilling Color:\tr=%i g=%i b=%i\n\n", info.ceilling_color.r,
		info.ceilling_color.g, info.ceilling_color.b);
	printf("Start X = %d\n", info.start_x);
	printf("Start y = %d\n", info.start_y);
	printf("Orientation = %d\n", info.start_orientation);
	print_int_tab(info.i_map);
}

static void	print_int_tab(int **tab)
{
	int	i;
	int	n;

	printf("\n");
	i = -1;
	while (tab[++i] != NULL)
	{
		n = -1;
		while (tab[i][++n] != TAB_NULL)
			printf("%i\t|", tab[i][n]);
		printf("\n");
	}
	printf("\n");
}
