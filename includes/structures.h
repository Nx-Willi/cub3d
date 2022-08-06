/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:46:35 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/06 15:31:38 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "cub3d.h"

typedef struct s_info		t_info;
// typedef struct s_color		t_color;
typedef struct s_check_map	t_check_map;
typedef struct s_mlx		t_mlx;
typedef struct s_data		t_data;

struct	s_info
{
	int		test;
	char	*no_texture;	
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	// t_color		floor_color;
	// t_color 	ceilling_color;
	t_mlx	*mlx;
};

struct	s_mlx
{
	void	*mlx;
	void	*window;
	int		*win_width;
	int		*win_heigth;
	t_data	*img;
};

struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
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
	int	c_color;
};

#endif
