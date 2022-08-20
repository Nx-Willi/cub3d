/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:11:50 by xle-baux          #+#    #+#             */
/*   Updated: 2022/08/20 05:30:37 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	r_and_f(int exit_value, char **split_line, char *msg)
{
	if (msg)
	{
		printf("Error\nMore than one type ID \"%s\"\n", msg);
	}
	free_char_char(split_line);
	return (exit_value);
}

int	is_info(t_check_info *check_info, char *line)
{
	int		len;
	char	**split_line;

	len = 0;
	split_line = ft_split_piscine(line, " \n");
	while (split_line[len])
		len++;
	if (len != 2)
		return (free_char_char(split_line), FALSE);
	if (ft_strncmp(split_line[0], "NO", 3) == 0)
		return (check_info->no = TRUE, r_and_f(TRUE, split_line, NULL));
	else if (ft_strncmp(split_line[0], "SO", 3) == 0)
		return (check_info->so = TRUE, r_and_f(TRUE, split_line, NULL));
	else if (ft_strncmp(split_line[0], "WE", 3) == 0)
		return (check_info->we = TRUE, r_and_f(TRUE, split_line, NULL));
	else if (ft_strncmp(split_line[0], "EA", 3) == 0)
		return (check_info->ea = TRUE, r_and_f(TRUE, split_line, NULL));
	else if (ft_strncmp(split_line[0], "F", 2) == 0
		&& check_rgb_color(split_line[1]) == TRUE)
		return (check_info->f_color = TRUE, r_and_f(TRUE, split_line, NULL));
	else if (ft_strncmp(split_line[0], "C", 2) == 0
		&& check_rgb_color(split_line[1]) == TRUE)
		return (check_info->c_color = TRUE, r_and_f(TRUE, split_line, NULL));
	free_char_char(split_line);
	return (FALSE);
}

int	is_dup_info(t_check_info *check_info, char *line)
{
	char	**split_line;

	split_line = ft_split(line, ' ');
	if (ft_strncmp(split_line[0], "NO", 3) == 0 && check_info->no == TRUE)
		return (r_and_f(FALSE, split_line, "NO"));
	else if (ft_strncmp(split_line[0], "SO", 3) == 0 && check_info->so == TRUE)
		return (r_and_f(FALSE, split_line, "SO"));
	else if (ft_strncmp(split_line[0], "WE", 3) == 0 && check_info->we == TRUE)
		return (r_and_f(FALSE, split_line, "WE"));
	else if (ft_strncmp(split_line[0], "EA", 3) == 0 && check_info->ea == TRUE)
		return (r_and_f(FALSE, split_line, "EA"));
	else if (ft_strncmp(split_line[0], "F", 2) == 0
		&& check_info->f_color == TRUE)
		return (r_and_f(FALSE, split_line, "F"));
	else if (ft_strncmp(split_line[0], "C", 2) == 0
		&& check_info->c_color == TRUE)
		return (r_and_f(FALSE, split_line, "C"));
	free_char_char(split_line);
	return (TRUE);
}
