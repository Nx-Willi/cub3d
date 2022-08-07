/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:08:52 by xle-baux          #+#    #+#             */
/*   Updated: 2022/08/07 13:55:09 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char		**read_map(char *map);

int	parser(t_info *info, char *map)
{
	char	**lines;

	init_info_struct(info);
	lines = read_map(map);
	if (check_info(lines) == FALSE)
		return (FALSE);
	get_infos(info, lines);
	return (TRUE);
}

static char	**read_map(char *map)
{
	int		i;
	int		fd;
	char	**line;

	i = -1;
	line = (char **)malloc(sizeof(char *) * (count_map_lines(map) + 1));
	if (!line)
		return (NULL);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (1)
	{
		line[++i] = get_next_line(fd);
		if (!line[i])
			break ;
	}
	line[i] = NULL;
	return (line);
}
