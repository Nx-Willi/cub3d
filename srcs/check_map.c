/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 10:56:16 by xle-baux          #+#    #+#             */
/*   Updated: 2022/08/06 14:20:47 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int			is_info(t_check_map *check_map_struct, char *line);
static int			is_dup_info(t_check_map *check_map_struct, char *line);
static int			is_map(char *line);
static t_check_map	init_check_map_struct(void);

int	check_map(char **map)
{
	int			i;
	t_check_map	check_map_struct;

	i = 0;
	check_map_struct = init_check_map_struct();
	while (map[i])
	{
		while (map[i] && is_empty_line(map[i]) == TRUE)
			i++;
		if (is_dup_info(&check_map_struct, map[i]) == FALSE)
			return (FALSE);
		else if (is_info(&check_map_struct, map[i]) == FALSE
			&& is_map(map[i]) == FALSE)
		{
			printf("Error\nCould't get info from line %i: %s", i + 1, map[i]);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

static int	is_info(t_check_map *check_map_struct, char *line)
{
	int		len;
	char	**split_line;

	len = 0;
	split_line = ft_split(line, ' ');
	while (split_line[len])
		len++;
	if (len != 2)
		return (FALSE);
	if (ft_strncmp(split_line[0], "NO", 3) == 0 && check_map_struct->no == FALSE)
	{
		free_split_char(split_line);
		return (check_map_struct->no = TRUE, TRUE);
	}
	else if (ft_strncmp(split_line[0], "SO", 3) == 0 && check_map_struct->so == FALSE)
	{
		free_split_char(split_line);
		return (check_map_struct->so = TRUE, TRUE);
	}
	else if (ft_strncmp(split_line[0], "WE", 3) == 0 && check_map_struct->we == FALSE)
	{
		free_split_char(split_line);
		return (check_map_struct->we = TRUE, TRUE);
	}
	else if (ft_strncmp(split_line[0], "EA", 3) == 0 && check_map_struct->ea == FALSE)
	{
		free_split_char(split_line);
		return (check_map_struct->ea = TRUE, TRUE);
	}
	else if (ft_strncmp(split_line[0], "F", 2) == 0 && check_map_struct->f_color == FALSE)
	{
		free_split_char(split_line);
		return (check_map_struct->f_color = TRUE, TRUE);
	}
	else if (ft_strncmp(split_line[0], "C", 2) == 0 && check_map_struct->c_color == FALSE)
	{
		free_split_char(split_line);
		return (check_map_struct->c_color = TRUE, TRUE);
	}
	free_split_char(split_line);
	return (FALSE);
}

static int	is_dup_info(t_check_map *check_map_struct, char *line)
{
	char	**split_line;

	split_line = ft_split(line, ' ');
	if (ft_strncmp(split_line[0], "NO", 3) == 0 && check_map_struct->no == TRUE)
	{
		free_split_char(split_line);
		return (printf("Error\nMore than one type ID \"NO\"\n"), FALSE);
	}
	else if (ft_strncmp(split_line[0], "SO", 3) == 0 && check_map_struct->so == TRUE)
	{
		free_split_char(split_line);
		return (printf("Error\nMore than one type ID \"SO\"\n"), FALSE);
	}
	else if (ft_strncmp(split_line[0], "EA", 3) == 0 && check_map_struct->ea == TRUE)
	{
		free_split_char(split_line);
		return (printf("Error\nMore than one type ID \"EA\"\n"), FALSE);
	}
	else if (ft_strncmp(split_line[0], "EA", 3) == 0 && check_map_struct->ea == TRUE)
	{
		free_split_char(split_line);
		return (printf("Error\nMore than one type ID \"EA\"\n"), FALSE);
	}
	else if (ft_strncmp(split_line[0], "F", 2) == 0 && check_map_struct->f_color == TRUE)
	{
		free_split_char(split_line);
		return (printf("Error\nMore than one type ID \"F\"\n"), FALSE);
	}
	else if (ft_strncmp(split_line[0], "C", 2) == 0 && check_map_struct->c_color == TRUE)
	{
		free_split_char(split_line);
		return (printf("Error\nMore than one type ID \"C\"\n"), FALSE);
	}
	return (TRUE);
}

static int	is_map(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != ' ' || line[i] != '0' || line[i] != '1'
			|| line[i] != 'N' || line[i] != 'S' || line[i] != 'E'
			|| line[i] != 'W')
			return (FALSE);
	}
	return (TRUE);
}

static t_check_map	init_check_map_struct(void)
{
	t_check_map	check_map_struct;

	check_map_struct.no = FALSE;
	check_map_struct.so = FALSE;
	check_map_struct.we = FALSE;
	check_map_struct.ea = FALSE;
	check_map_struct.f_color = FALSE;
	check_map_struct.c_color = FALSE;
	return (check_map_struct);
}
