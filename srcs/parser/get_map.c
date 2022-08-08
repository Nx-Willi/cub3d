/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:55:13 by xle-baux          #+#    #+#             */
/*   Updated: 2022/08/08 12:22:03 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_first_last_line(t_check_info *sizes, char **line);
static void	get_largest_map_line(t_check_info *sizes, char **line);
static int	fill_map(t_info *info, t_check_info *sizes, char **line);
static void init_sizes_struct(t_check_info *sizes);

int	get_map(t_info *info, char **line)
{
	(void)info;
	t_check_info sizes;

	init_sizes_struct(&sizes);
	get_first_last_line(&sizes, line);
	sizes.len_y = (sizes.last_map_line - sizes.first_map_line + 1);
	get_largest_map_line(&sizes, line);
	if (fill_map(info, &sizes, line) == FALSE)
		return (FALSE);
	printf("len_x: %d\nlen_y: %d\n", sizes.len_x, sizes.len_y);
	printf("First: %d\nLast: %d\n", sizes.first_map_line, sizes.last_map_line);
	return (TRUE);
}

static int	fill_map(t_info *info, t_check_info *sizes, char **line)
{
	int	i;
	int	j;

	i = sizes->first_map_line;
	j = 0;
	info->map = (char **)ft_calloc(sizeof(char *), sizes->len_y + 1);
	if (info->map == NULL)
		return (FALSE);
	while (i <= sizes->last_map_line)
	{
		info->map[j] = ft_strdup(line[i]);
		j++;
		i++;
	}
	return (TRUE);
}

static void	get_first_last_line(t_check_info *sizes, char **line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (is_empty_line(line[i]) == FALSE && is_map(line[i]) == TRUE)
		{
			sizes->first_map_line = i;
			break ;
		}
		i++;
	}
	while (line[i])
		i++;
	while (i > 0)
	{
		if (is_empty_line(line[i]) == FALSE && is_map(line[i]) == TRUE)
		{
			sizes->last_map_line = i;
			break ;
		}
		i--;
	}
}

static void	get_largest_map_line(t_check_info *sizes, char **line)
{
	int	i;

	i = sizes->first_map_line;
	while (i <= sizes->last_map_line)
	{
		if ((int)ft_strlen(line[i]) > sizes->len_x)
			sizes->len_x = ft_strlen(line[i]);
		i++;
	}

}

static void init_sizes_struct(t_check_info *sizes)
{
	sizes->first_map_line = -1;
	sizes->last_map_line = -1;
	sizes->len_x = -1;
	sizes->len_y = -1;
}
