/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:36:48 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/06 18:26:30 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_file_exist(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror(path);
		return (FALSE);
	}
	if (read(fd, "", 1) == 0)
	{
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": The file is empty!\n", 2);
		return (FALSE);
	}
	return (TRUE);
}

int	check_file(char *path)
{
	if (!is_file_exist(path))
		return (FALSE);
	if (ft_strncmp(path + ft_strlen(path) - 4, ".cub", 4) != 0)
	{
		ft_putstr_fd("File's extension isn't correct!\n", 2);
		return (FALSE);
	}
	return (TRUE);
}
