/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:02:00 by xle-baux          #+#    #+#             */
/*   Updated: 2022/08/10 17:02:16 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_player_orientation(char o);

int	check_map(t_info *info, t_check_info *check_info, char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (check_info->spawning_position == FALSE
				&& (map[j][i] == 'N' || map[j][i] == 'S'
				|| map[j][i] == 'W' || map[j][i] == 'E'))
				{
					check_info->spawning_position = TRUE;
					info->start_y = i;
					info->start_x = j;
					info->start_orientation = get_player_orientation(map[j][i]);
				}
			else if (check_info->spawning_position == TRUE
				&& (map[j][i] == 'N' || map[j][i] == 'S'
				|| map[j][i] == 'W' || map[j][i] == 'E'))
				{
					return (FALSE);
				}
			i++;
		}
		j++;
	}
	return (TRUE);
}

static int	get_player_orientation(char o)
{
	if (o == 'N')
		return (NO);
	else if (o == 'S')
		return (SO);
	else if (o == 'W')
		return (WE);
	else
		return (EA);
}
