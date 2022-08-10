/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:35:23 by xlb               #+#    #+#             */
/*   Updated: 2022/08/10 11:01:23 by xle-baux         ###   ########.fr       */
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
	close(fd);
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

void	free_split_char(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
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
	free_split_char(split_color);
	return (TRUE);
}

int	is_map(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1'
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W' && line[i] != '\n' && line[i] != '\0')
			return (FALSE);
	}
	return (TRUE);
}
