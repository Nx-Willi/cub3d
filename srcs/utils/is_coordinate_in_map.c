/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_coordinate_in_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 04:38:40 by wdebotte          #+#    #+#             */
/*   Updated: 2022/09/04 11:44:16 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_coordinate_in_map(t_info *infos, double x, double y)
{
	if (x < PLY_WEIGHT || x > infos->map_width - PLY_WEIGHT)
		return (FALSE);
	if (y < PLY_WEIGHT || y > infos->map_height - PLY_WEIGHT)
		return (FALSE);
	return (TRUE);
}
