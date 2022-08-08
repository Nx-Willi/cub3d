/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:11:20 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/08 11:49:43 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "structures.h"
# include "mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <X11/Xlib.h>

enum	e_keys
{
	KEY_LEFT	= 65361,
	KEY_RIGHT	= 65363,
	KEY_W		= 119,
	KEY_A		= 97,
	KEY_S		= 115,
	KEY_D		= 100,
	KEY_ESC		= 65307
};

//__>PARSING____________________________________________________________________
int		parser(t_info *info, char *map);
int		check_info(char **map);
int		count_map_lines(char *map);
int		is_empty_line(char *line);
int		check_rgb_color(char *color);
int		is_map(char *line);
int		get_map(t_info *info, char **line);
int		is_info(t_check_info *check_info_struct, char *line);
int		is_dup_info(t_check_info *check_info_struct, char *line);

void	get_infos(t_info *info, char **line);
void	free_split_char(char **str);
void	init_info_struct(t_info *info);
//__>TMP_TOOLS__________________________________________________________________
void	print_info_struct(t_info info);
//‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾

//__>HOOKS______________________________________________________________________
void	handler_events(t_info *info);
//‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾

//__>UTILS______________________________________________________________________
int		check_file(char *path);

void	exit_program(t_info *info, char *error, int status);
void	free_info_struct(t_info *info);
//‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾

#endif
