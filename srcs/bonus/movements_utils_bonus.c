/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 02:06:19 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/22 19:02:55 by william          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define MARGIN	0.05

void	check_player_side_wall(t_game *game)
{
	t_info	*info;

	info = game->infos;
	if (game->move.left == TRUE)
	{
		if (info->i_map[(int)game->ray.map_y]
			[(int)(game->ray.map_x + MARGIN)] == 1)
			game->ray.map_x -= MARGIN;
		if (info->i_map[(int)(game->ray.map_y - MARGIN)]
			[(int)game->ray.map_x] == 1)
			game->ray.map_y += MARGIN;
	}
	if (game->move.right == TRUE)
	{
		if (info->i_map[(int)game->ray.map_y][(int)(game->ray.map_x
			- MARGIN)] == 1)
			game->ray.map_x += MARGIN;
		if (info->i_map[(int)(game->ray.map_y + MARGIN)]
			[(int)game->ray.map_x] == 1)
			game->ray.map_y -= MARGIN;
	}
}

int	is_coordinate_walkable(t_info *infos, double x, double y)
{
	if (is_coordinate_in_map(infos, x, y) == FALSE)
		return (FALSE);
	if (infos->i_map[(int)y][(int)x] != 0)
		return (FALSE);
	return (TRUE);
}
