/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_coordinate_in_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 04:38:40 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/20 05:36:03 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_coordinate_in_map(t_info *infos, int x, int y)
{
	if (x < 0 || x >= infos->map_width)
		return (FALSE);
	if (y < 0 || y >= infos->map_height)
		return (FALSE);
	return (TRUE);
}
