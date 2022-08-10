/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:55:13 by xle-baux          #+#    #+#             */
/*   Updated: 2022/08/10 17:01:44 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	fill_map(t_info *info, t_check_info *sizes, char **line);
// static int map_to_int(t_info *info, t_check_info *sizes, char **char_map);

int	get_map(t_info *info, char **line)
{
	t_check_info	sizes;

	init_sizes_struct(&sizes);
	get_first_last_line(&sizes, line);
	sizes.len_y = (sizes.last_map_line - sizes.first_map_line + 1);
	get_largest_map_line(&sizes, line);
	if (fill_map(info, &sizes, line) == FALSE)
		return (FALSE);
	// if (check_map(info, &sizes, line) == FALSE)
	// 	return (FALSE);
	printf("len_x: %d\nlen_y: %d\n", sizes.len_x, sizes.len_y);
	printf("First: %d\nLast: %d\n", sizes.first_map_line, sizes.last_map_line);
	return (TRUE);
}

static int	fill_map(t_info *info, t_check_info *sizes, char **line)
{
	int		i;
	int		j;

	i = sizes->first_map_line;
	j = 0;
	info->map = (char **)malloc(sizeof(char *) * (sizes->len_y + 1));
	if (info->map == NULL)
		return (FALSE);
	while (i <= sizes->last_map_line)
	{
		info->map[j] = ft_strdup(line[i]);
		j++;
		i++;
	}
	info->map[j] = NULL;
	if (check_map(info, sizes, info->map) == FALSE)
		return (FALSE);
	return (TRUE);
}
