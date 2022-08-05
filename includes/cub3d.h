/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlb <xlb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:11:20 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/05 23:15:53 by xlb              ###   ########.fr       */
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

struct	s_info
{
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

int		count_map_lines(char *map);
int		is_empty_line(char *line);

void free_split_char(char **str);

t_info	parser(char *map);
t_info  init_info_struct(void);

#endif
