/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:35:23 by xlb               #+#    #+#             */
/*   Updated: 2022/08/06 17:40:26 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_map_lines(char *map)
{
	int		fd;
	int		len;
	char	*line;

	len = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		len++;
		free(line);
	}
	return (len + 1);
}

int	is_empty_line(char *line)
{
	int	i;

	i = -1;
	if (!line)
		return (TRUE);
	while (line[++i])
	{
		if (ft_isspace(line[i]) == 0 && line[i] != '\0')
			return (FALSE);
	}
	return (TRUE);
}

void	init_info_struct(t_info *info)
{
	info->no_texture = NULL;
	info->so_texture = NULL;
	info->we_texture = NULL;
	info->ea_texture = NULL;
	// info->floor_color.r = -1;
	// info->floor_color.g = -1;
	// info->floor_color.b = -1;
	// info->ceilling_color.r = -1;
	// info->ceilling_color.g = -1;
	// info->ceilling_color.b = -1;
}

void	free_split_char(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	check_rgb_color(char *color)
{
	int		i;
	char	**split_color;

	i = 0;
	split_color = ft_split(color, ',');
	while (split_color[i])
		i++;
	if (i != 3)
		return (FALSE);
	i = 0;
	while (split_color[i])
	{
		if (ft_is)
	}
	free_split_char(split_color);
	return (TRUE);
}