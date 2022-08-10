/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:00:17 by xle-baux          #+#    #+#             */
/*   Updated: 2022/08/10 13:05:01 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_first_last_line(t_check_info *sizes, char **line)
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

void	get_largest_map_line(t_check_info *sizes, char **line)
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

void	init_info_struct(t_info *info)
{
	info->map = NULL;
	info->textures[T_NO] = NULL;
	info->textures[T_SO] = NULL;
	info->textures[T_WE] = NULL;
	info->textures[T_EA] = NULL;
	info->floor_color.r = -1;
	info->floor_color.g = -1;
	info->floor_color.b = -1;
	info->ceilling_color.r = -1;
	info->ceilling_color.g = -1;
	info->ceilling_color.b = -1;
}

void	init_sizes_struct(t_check_info *sizes)
{
	sizes->first_map_line = -1;
	sizes->last_map_line = -1;
	sizes->len_x = -1;
	sizes->len_y = -1;
}
