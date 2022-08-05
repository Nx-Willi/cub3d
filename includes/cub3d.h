/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:11:20 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/05 11:05:59 by xle-baux         ###   ########.fr       */
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
typedef struct s_texture	t_texture;
// typedef struct s_color		t_color;

struct	s_info
{
	t_texture	textures;
	t_color		floor;
	t_color 	ceilling;
};

struct s_texture
{
	char	*nord_texture;	
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
};

// struct	s_color
// {
// 	unsigned int	r;
// 	unsigned int	g;
// 	unsigned int	b;
// };

t_info	*parcer(char *map);

#endif
