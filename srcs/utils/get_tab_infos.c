/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tab_infos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 04:33:27 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/20 05:09:57 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_map_width(int **map)
{
	int	y;
	int	x;
	int	tmp;

	if (map == NULL)
		return (-1);
	tmp = -1;
	y = -1;
	while (map[++y] != NULL)
	{
		x = 0;
		while (map[y][x] != TAB_NULL)
			x++;
		if (tmp < x)
			tmp = x;
	}
	return (tmp);
}

int	get_map_height(int **map)
{
	int	y;

	if (map == NULL)
		return (-1);
	y = -1;
	while (map[++y] != NULL)
		continue ;
	return (y);
}
