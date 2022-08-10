/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:55:13 by xle-baux          #+#    #+#             */
/*   Updated: 2022/08/10 18:27:44 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	fill_map(t_info *info, t_check_info *sizes, char **line);

int	get_map(t_info *info, char **line)
{
	t_check_info	sizes;

	init_sizes_struct(&sizes);
	get_first_last_line(&sizes, line);
	sizes.len_y = (sizes.last_map_line - sizes.first_map_line + 1);
	get_largest_map_line(&sizes, line);
	if (fill_map(info, &sizes, line) == FALSE)
		return (FALSE);
	return (TRUE);
}

static int	fill_map(t_info *info, t_check_info *sizes, char **line)
{
	int		i;
	int		j;
	char	**char_map;

	i = sizes->first_map_line;
	j = 0;
	char_map = (char **)malloc(sizeof(char *) * (sizes->len_y + 1));
	if (char_map == NULL)
		return (FALSE);
	while (i <= sizes->last_map_line)
	{
		char_map[j] = ft_strdup(line[i]);
		j++;
		i++;
	}
	char_map[j] = NULL;
	if (check_map(info, sizes, char_map) == FALSE)
		return (free_char_char(char_map), FALSE);
	info->i_map = tab_char_to_int(info, sizes, char_map);
	if (info->i_map == NULL)
		return (FALSE);
	free_char_char(char_map);
	return (TRUE);
}
