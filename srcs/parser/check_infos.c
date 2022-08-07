/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 10:56:16 by xle-baux          #+#    #+#             */
/*   Updated: 2022/08/07 16:28:32 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int			is_info(t_check_info *check_info_struct, char *line);
static int			is_dup_info(t_check_info *check_info_struct, char *line);
static int			missing_info(t_check_info *check_info_struct);
static t_check_info	init_check_info_struct(void);

int	check_info(char **map)
{
	int				i;
	t_check_info	check_info_struct;

	i = 0;
	check_info_struct = init_check_info_struct();
	while (map[i])
	{
		while (map[i] && is_empty_line(map[i]) == TRUE)
			i++;
		if (is_dup_info(&check_info_struct, map[i]) == FALSE)
			return (FALSE);
		else if (is_info(&check_info_struct, map[i]) == FALSE
			&& is_map(map[i]) == FALSE)
		{
			printf("Error\nCould't get info from line %i: %s", i + 1, map[i]);
			return (FALSE);
		}
		i++;
	}
	if (missing_info(&check_info_struct) == TRUE)
		return (FALSE);
	return (TRUE);
}

static int	is_info(t_check_info *check_info_struct, char *line)
{
	int		len;
	char	**split_line;

	len = 0;
	split_line = ft_split(line, ' ');
	while (split_line[len])
		len++;
	if (len != 2)
		return (free_split_char(split_line), FALSE);
	if (ft_strncmp(split_line[0], "NO", 3) == 0)
	{
		free_split_char(split_line);
		return (check_info_struct->no = TRUE, TRUE);
	}
	else if (ft_strncmp(split_line[0], "SO", 3) == 0)
	{
		free_split_char(split_line);
		return (check_info_struct->so = TRUE, TRUE);
	}
	else if (ft_strncmp(split_line[0], "WE", 3) == 0)
	{
		free_split_char(split_line);
		return (check_info_struct->we = TRUE, TRUE);
	}
	else if (ft_strncmp(split_line[0], "EA", 3) == 0)
	{
		free_split_char(split_line);
		return (check_info_struct->ea = TRUE, TRUE);
	}
	else if (ft_strncmp(split_line[0], "F", 2) == 0 && check_rgb_color(split_line[1]) == TRUE)
	{
		free_split_char(split_line);
		return (check_info_struct->f_color = TRUE, TRUE);
	}
	else if (ft_strncmp(split_line[0], "C", 2) == 0 && check_rgb_color(split_line[1]) == TRUE)
	{
		free_split_char(split_line);
		return (check_info_struct->c_color = TRUE, TRUE);
	}
	free_split_char(split_line);
	return (FALSE);
}

static int	is_dup_info(t_check_info *check_info_struct, char *line)
{
	char	**split_line;

	split_line = ft_split(line, ' ');
	if (ft_strncmp(split_line[0], "NO", 3) == 0 && check_info_struct->no == TRUE)
	{
		free_split_char(split_line);
		return (printf("Error\nMore than one type ID \"NO\"\n"), FALSE);
	}
	else if (ft_strncmp(split_line[0], "SO", 3) == 0 && check_info_struct->so == TRUE)
	{
		free_split_char(split_line);
		return (printf("Error\nMore than one type ID \"SO\"\n"), FALSE);
	}
	else if (ft_strncmp(split_line[0], "WE", 3) == 0 && check_info_struct->we == TRUE)
	{
		free_split_char(split_line);
		return (printf("Error\nMore than one type ID \"WE\"\n"), FALSE);
	}
	else if (ft_strncmp(split_line[0], "EA", 3) == 0 && check_info_struct->ea == TRUE)
	{
		free_split_char(split_line);
		return (printf("Error\nMore than one type ID \"EA\"\n"), FALSE);
	}
	else if (ft_strncmp(split_line[0], "F", 2) == 0 && check_info_struct->f_color == TRUE)
	{
		free_split_char(split_line);
		return (printf("Error\nMore than one type ID \"F\"\n"), FALSE);
	}
	else if (ft_strncmp(split_line[0], "C", 2) == 0 && check_info_struct->c_color == TRUE)
	{
		free_split_char(split_line);
		return (printf("Error\nMore than one type ID \"C\"\n"), FALSE);
	}
	free_split_char(split_line);
	return (TRUE);
}

static t_check_info	init_check_info_struct(void)
{
	t_check_info	check_info_struct;

	check_info_struct.no = FALSE;
	check_info_struct.so = FALSE;
	check_info_struct.we = FALSE;
	check_info_struct.ea = FALSE;
	check_info_struct.f_color = FALSE;
	check_info_struct.c_color = FALSE;
	return (check_info_struct);
}

static int	missing_info(t_check_info *check_info_struct)
{
	if (check_info_struct->no == FALSE)
		return (printf("Error\nInfo id \"NO\" is missing\n"), TRUE);
	if (check_info_struct->so == FALSE)
		return (printf("Error\nInfo id \"SO\" is missing\n"), TRUE);
	if (check_info_struct->we == FALSE)
		return (printf("Error\nInfo id \"WE\" is missing\n"), TRUE);
	if (check_info_struct->ea == FALSE)
		return (printf("Error\nInfo id \"EA\" is missing\n"), TRUE);
	if (check_info_struct->f_color == FALSE)
		return (printf("Error\nInfo id \"F\" is missing\n"), TRUE);
	if (check_info_struct->c_color == FALSE)
		return (printf("Error\nInfo id \"C\" is missing\n"), TRUE);
	return (FALSE);
}
