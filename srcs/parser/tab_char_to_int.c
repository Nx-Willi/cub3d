/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_char_to_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:58:38 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/10 13:08:05 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_tab_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		printf("%s\n", tab[i++]);
	return (i);
}

void	tab_char_to_int(t_info *infos)
{
	int	i;
	int	n;
	int	z;
	int	**i_map;

	i_map = (int **)malloc(sizeof(int *) * (get_tab_size(infos->map) + 1));
	if (i_map == NULL)
		return (NULL);
	i = 0;
	while (infos->map[i] != NULL)
	{
		n = 0;
		z = 0;
		while (infos->map[i][n] != '\0')
		{

		}
	}
}