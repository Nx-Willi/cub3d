/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 10:56:16 by xle-baux          #+#    #+#             */
/*   Updated: 2022/08/10 10:59:01 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static t_check_info	init_check_info_struct(void)
{
	t_check_info	check_info_struct;

	check_info_struct.no = FALSE;
	check_info_struct.so = FALSE;
	check_info_struct.we = FALSE;
	check_info_struct.ea = FALSE;
	check_info_struct.spawning_position = FALSE;
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
