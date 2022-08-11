/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:49:02 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/11 16:46:17 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// a vector shows the direction in a plane with coordinates x and y as,
// if a vector goes to North, the y will increase of one, in south it'll
// decrease.
// same thing for the direction East and West with the x coordinate.
static void	get_initial_vector_direction(t_info *infos)
{
	int		orientation;
	t_ray	*ray;

	ray = &(infos->game.ray);
	//orientation = infos->start_orientation;
	orientation = NO;
	if (orientation == NO || orientation == SO)
	{
		ray->vecDirX = 0;
		if (orientation == NO)
			ray->vecDirY = 1;
		else
			ray->vecDirY = -1;
	}
	else if (orientation == WE || orientation == EA)
	{
		if (orientation == WE)
			ray->vecDirX = -1;
		else
			ray->vecDirX = 1;
		ray->vecDirY = 0;
	}
}

void	init_player(t_info *infos)
{
	t_player	*player;

	player = &(infos->game.player);
	// player->initX = infos->start_x;
	// player->initY = infos->start_y;
	player->initX = 16;
	player->initY = 5;
	get_initial_vector_direction(infos);
}

// 2d raycast for the camera
void	init_plane(t_info *infos)
{
	t_plane	*plane;

	plane = &(infos->game.plane);
	plane->posX = 0;
	plane->posY = 0.66;
}