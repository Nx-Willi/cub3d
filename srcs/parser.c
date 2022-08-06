/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:08:52 by xle-baux          #+#    #+#             */
/*   Updated: 2022/08/06 18:29:09 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		get_infos(t_info *info, char **line);
static int		get_type_id(t_info *info, char **line);
static char		**read_map(char *map);
static void		get_rgb_color(t_color *struct_color, char *color);

int	parser(t_info *info, char *map)
{
	char	**lines;

	init_info_struct(info);
	lines = read_map(map);
	if (check_map(lines) == FALSE)
		return (FALSE);
	get_infos(info, lines);
	return (TRUE);
}

static void	get_infos(t_info *info, char **line)
{
	int		i;
	char	**split_line;

	i = 0;
	while (line[i] && is_empty_line(line[i]) == TRUE)
		i++;
	while (line[i])
	{
		split_line = ft_split(line[i++], ' ');
		if (!line)
			break ;
		get_type_id(info, split_line);
		free_split_char(split_line);
		while (line[i] && is_empty_line(line[i]) == TRUE)
			i++;
	}
}

static int	get_type_id(t_info *info, char **line)
{
	int	len;

	len = 0;
	while (line[len])
		len++;
	if (len != 2)
		return (FALSE);
	if (ft_strncmp(line[0], "NO", 3) == 0)
		info->no_texture = ft_strdup(line[1]);
	else if (ft_strncmp(line[0], "SO", 3) == 0)
		info->so_texture = ft_strdup(line[1]);
	else if (ft_strncmp(line[0], "WE", 3) == 0)
		info->we_texture = ft_strdup(line[1]);
	else if (ft_strncmp(line[0], "EA", 3) == 0)
		info->ea_texture = ft_strdup(line[1]);
	else if (ft_strncmp(line[0], "F", 2) == 0)
		get_rgb_color(&info->floor_color, line[1]);
	else if (ft_strncmp(line[0], "C", 2) == 0)
		get_rgb_color(&info->ceilling_color, line[1]);
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

static void	get_rgb_color(t_color *struct_color, char *color)
{
	char	**split_color;

	split_color = ft_split(color, ',');
	struct_color->r = ft_atoi(split_color[0]);
	struct_color->g = ft_atoi(split_color[1]);
	struct_color->b = ft_atoi(split_color[2]);
	free_split_char(split_color);
}
