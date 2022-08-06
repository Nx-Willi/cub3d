/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-baux <xle-baux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:46:35 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/06 18:21:04 by xle-baux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "cub3d.h"

typedef struct s_info		t_info;
typedef struct s_color		t_color;
typedef struct s_check_map	t_check_map;

struct	s_color
{
	int	r;
	int	g;
	int	b;
};

struct	s_check_map
{
	int	no;	
	int	so;
	int	we;
	int	ea;
	int	f_color;
	int	c_color;
};

struct	s_info
{
	char		*no_texture;	
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	t_color		floor_color;
	t_color 	ceilling_color;
};

#endif
