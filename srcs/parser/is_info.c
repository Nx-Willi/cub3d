/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:11:50 by xle-baux          #+#    #+#             */
/*   Updated: 2022/08/10 13:04:19 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_info(t_check_info *check_info_struct, char *line)
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

int	is_dup_info(t_check_info *check_info_struct, char *line)
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
