/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_char_to_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:58:38 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/22 16:42:16 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_tab_info(char c)
{
	if (c == '1')
		return (1);
	else if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (0);
	else
		return (-1);
}

static void	fill_tab_line(t_check_info *t_infos, int i,
	int **i_map, char **char_map)
{
	int	n;

	n = 0;
	while (n < t_infos->len_x - 1)
	{
		if (n >= (int)ft_strlen(char_map[i]))
			i_map[i][n] = -1;
		else
			i_map[i][n] = get_tab_info(char_map[i][n]);
		n++;
	}
	i_map[i][n] = TAB_NULL;
}

static int	check_in_walls(t_check_info *check_info, int **map)
{
	int	i;
	int	j;

	i = 0;
	while (++i < check_info->len_y - 1)
	{
		j = 0;
		while (++j < check_info->len_x - 2)
		{
			if (map[i][j] == 0)
			{
				if (map[i - 1][j - 1] == -1 || map[i - 1][j] == -1
					|| map[i - 1][j + 1] == -1
					|| map[i][j - 1] == -1 || map[i][j + 1] == -1
					|| map[i + 1][j - 1] == -1 || map[i + 1][j] == -1
					|| map[i + 1][j + 1] == -1)
					return (FALSE);
			}
		}
	}
	return (TRUE);
}

static int	check_out_walls(t_check_info *check_info, int **map)
{
	int	i;

	i = -1;
	while (map[0][++i] != TAB_NULL)
		if (map[0][i] == 0)
			return (FALSE);
	i = -1;
	while (map[check_info->len_y - 1][++i] != TAB_NULL)
		if (map[check_info->len_y - 1][i] == 0)
			return (FALSE);
	i = -1;
	while (map[++i] != NULL)
		if (map[i][0] == 0)
			return (FALSE);
	i = -1;
	while (map[++i] != NULL)
		if (map[i][check_info->len_x - 2] == 0)
			return (FALSE);
	if (check_in_walls(check_info, map) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	**tab_char_to_int(t_check_info *t_infos, char **char_map)
{
	int	i;
	int	**i_map;

	i_map = (int **)malloc(sizeof(int *) * (t_infos->len_y + 1));
	if (i_map == NULL)
		return (NULL);
	i = -1;
	while (char_map[++i] != NULL)
	{
		i_map[i] = (int *)malloc(sizeof(int) * (t_infos->len_x));
		if (i_map[i] == NULL)
			return (free_int_tab(i_map, &i), NULL);
		fill_tab_line(t_infos, i, i_map, char_map);
	}
	i_map[i] = NULL;
	if (check_out_walls(t_infos, i_map) == FALSE)
		return (printf("Error\nThe map must be surrounded by walls.\n"), NULL);
	return (i_map);
}
