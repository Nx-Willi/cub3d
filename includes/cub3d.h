/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:11:20 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/12 11:33:39 by wdebotte         ###   ########.fr       */
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

# define TAB_NULL	2

//__>ENUMS______________________________________________________________________
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

enum	e_textures
{
	T_NO	= 0,
	T_SO,
	T_WE,
	T_EA
};

enum	e_map
{
	NO		= 100,
	SO,
	WE,
	EA,
	OUT		= -1,
	IN,
	WALL
};
//‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾

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
int		**tab_char_to_int(t_info *infos	, t_check_info *t_infos);

void	get_infos(t_info *info, char **line);
void	get_first_last_line(t_check_info *sizes, char **line);
void	get_largest_map_line(t_check_info *sizes, char **line);
void	free_split_char(char **str);
void	init_info_struct(t_info *info);
void	init_sizes_struct(t_check_info *sizes);
//__>TMP_TOOLS__________________________________________________________________
void	print_info_struct(t_info info);
//‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾

//__>RAYCAST____________________________________________________________________
void	do_raycasting(t_info *infos);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
//‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾

//__>HOOKS______________________________________________________________________
void	handler_events(t_info *info);
//‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾

//__>UTILS______________________________________________________________________
int		check_file(char *path);

void	exit_program(t_info *info, char *error, int status);
//____>FREES____________________________________________________________________
void	free_mlx(t_mlx *mlx);
void	free_info_struct(t_info *info);
void	free_int_tab(int **tab, int *limit);
//‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾

#endif
