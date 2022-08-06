/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:11:20 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/06 12:13:46 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_info		t_info;
// typedef struct s_color		t_color;
typedef struct s_check_map	t_check_map;

struct	s_info
{
	int		test;
	char	*no_texture;	
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	// t_color		floor_color;
	// t_color 	ceilling_color;
};

// struct	s_color
// {
// 	int	r;
// 	int	g;
// 	int	b;
// };

struct	s_check_map
{
	int	no;	
	int	so;
	int	we;
	int	ea;
	int	f_color;
	int c_color;
};

int		check_map(char **map);
int		count_map_lines(char *map);
int		is_empty_line(char *line);

void free_split_char(char **str);

t_info	parser(char *map);
t_info  init_info_struct(void);

// tmp_tools _____________________________________________________________________

void	print_info_struct(t_info info);

#endif
