/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_coordinate_in_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 04:38:40 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/21 18:44:33 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_coordinate_in_map(t_info *infos, double x, double y)
{
	if (x < 0.1 || x > infos->map_width - 0.1)
		return (FALSE);
	if (y < 0.1 || y > infos->map_height - 0.1)
		return (FALSE);
	return (TRUE);
}
