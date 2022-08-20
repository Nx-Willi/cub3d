/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:02:00 by xle-baux          #+#    #+#             */
/*   Updated: 2022/08/20 06:30:23 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_player_orientation(char o);
// static int	check_walls(char **map);

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
	// if (check_walls(map) == FALSE)
	// 	return (printf("Error\nThe map must be surrounded by walls.\n"), FALSE);
	return (TRUE);
}

// static int	check_walls(char **map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while(map[i] != NULL)
// 	{
// 		j = 0;
// 		while(map[i][j] != '\0')
// 		{
// 			if 
// 			if (!map[i - 1][j - 1] || !map[i - 1][j] || !map[i - 1][j + 1] || !map[i][j - 1] || !map[i][j] || !map[i][j + 1] || !map[i + 1][j - 1] || !map[i + 1][j] || !map[i + 1][j + 1])
// 				return (FALSE);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (TRUE);
// }

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
