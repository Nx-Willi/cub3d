/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_char_to_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:58:38 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/10 17:04:26 by wdebotte         ###   ########.fr       */
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

static void	fill_tab_line(t_info *infos, t_check_info *t_infos, int i,
	int **i_map)
{
	int	n;

	n = 0;
	while (n < t_infos->len_x - 1)
	{
		if (n >= (int)ft_strlen(infos->map[i]))
			i_map[i][n] = -1;
		else
			i_map[i][n] = get_tab_info(infos->map[i][n]);
		n++;
	}
	i_map[i][n] = TAB_NULL;
}

int	**tab_char_to_int(t_info *infos, t_check_info *t_infos)
{
	int	i;
	int	**i_map;

	i_map = (int **)malloc(sizeof(int *) * (t_infos->len_y + 1));
	if (i_map == NULL)
		return (NULL);
	i = -1;
	while (infos->map[++i] != NULL)
	{
		i_map[i] = (int *)malloc(sizeof(int) * (t_infos->len_x));
		if (i_map[i] == NULL)
			return (free_int_tab(i_map, &i), NULL);
		fill_tab_line(infos, t_infos, i, i_map);
	}
	i_map[i] = NULL;
	return (i_map);
}
