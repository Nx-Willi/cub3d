/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:02:00 by xle-baux          #+#    #+#             */
/*   Updated: 2022/08/11 14:06:49 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_player_orientation(char o);

int	check_map(t_info *info, t_check_info *check_info, char **map)
{
	int	i;
	int	j;

	j = -1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (check_info->spawning_position == FALSE
				&& (map[j][i] == 'N' || map[j][i] == 'S'
				|| map[j][i] == 'W' || map[j][i] == 'E'))
			{
				check_info->spawning_position = TRUE;
				info->start_y = j;
				info->start_x = i;
				info->start_orientation = get_player_orientation(map[j][i]);
			}
			else if (check_info->spawning_position == TRUE
				&& (map[j][i] == 'N' || map[j][i] == 'S'
				|| map[j][i] == 'W' || map[j][i] == 'E'))
				return (printf("Error\nSpawn point twice\n"), FALSE);
		}
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
