/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:55:13 by xle-baux          #+#    #+#             */
/*   Updated: 2022/08/10 16:54:54 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	fill_map(t_info *info, t_check_info *sizes, char **line);
// static int map_to_int(t_info *info, t_check_info *sizes, char **char_map);

int	get_map(t_info *info, char **line)
{
	t_check_info	sizes;

	init_sizes_struct(&sizes);
	get_first_last_line(&sizes, line);
	sizes.len_y = (sizes.last_map_line - sizes.first_map_line + 1);
	get_largest_map_line(&sizes, line);
	if (fill_map(info, &sizes, line) == FALSE)
		return (FALSE);
	printf("len_x: %d\nlen_y: %d\n", sizes.len_x, sizes.len_y);
	printf("First: %d\nLast: %d\n", sizes.first_map_line, sizes.last_map_line);
	return (TRUE);
}

static void	print_int_tab(int **tab)
{
	int	i;
	int	n;

	printf("\n");
	i = -1;
	while (tab[++i] != NULL)
	{
		n = -1;
		while (tab[i][++n] != TAB_NULL)
			printf("%i ", tab[i][n]);
		printf("\n");
	}
	printf("\n");
}

static int	fill_map(t_info *info, t_check_info *sizes, char **line)
{
	int		i;
	int		j;

	i = sizes->first_map_line;
	j = 0;
	info->map = (char **)malloc(sizeof(char *) * (sizes->len_y + 1));
	if (info->map == NULL)
		return (FALSE);
	while (i <= sizes->last_map_line)
	{
		info->map[j] = ft_strdup(line[i]);
		j++;
		i++;
	}
	info->map[j] = NULL;
	info->i_map = tab_char_to_int(info, sizes);
	if (info->i_map == NULL)
		return (FALSE);
	print_int_tab(info->i_map);
	// if (map_to_int(info, sizes ,char_map) == FALSE)
	// 	return (FALSE);
	return (TRUE);
}

// static int	map_to_int(t_info *info, t_check_info *sizes, char **char_map)
// {
// 	int	i;
// 	int	j;

// 	j = 0;
// 	info->map = (int **)malloc(sizeof(int *) * (sizes->len_y + 1));
// 	if (info->map == NULL)
// 		return (FALSE);
// 	while(char_map[j] != NULL)
// 	{
// 		i = 0;
// 		info->map[j] = malloc(sizeof(int) * (sizes->len_x + 1));
// 		if (info->map[j] == NULL)
// 			return (FALSE);
// 		while (i <= sizes->len_x)
// 		{
// 			if (!char_map[j][i])
// 				info->map[j][i] = 3;
// 			else if (ft_isspace(char_map[j][i]) != FALSE)
// 				info->map[j][i] = 3;
// 			else if (char_map[j][i] && char_map[j][i] == '0')
// 				info->map[j][i] = 8;
// 			else if (char_map[j][i] && char_map[j][i] == '1')
// 				info->map[j][i] = WALL;
// 			else
// 				info->map[j][i] = 9;
// 			i++;
// 		}
// 		j++;
// 	}
// 	return (TRUE);
// }