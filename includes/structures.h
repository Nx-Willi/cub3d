/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:46:35 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/10 13:12:33 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_info		t_info;
typedef struct s_color		t_color;
typedef struct s_check_info	t_check_info;
typedef struct s_mlx		t_mlx;
typedef struct s_data		t_data;

//__>MLX_______________________________________________________________________
struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct	s_mlx
{
	void	*mlx;
	void	*window;
	int		win_width;
	int		win_heigth;
	t_data	img;
};
//‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾

struct	s_color
{
	int	r;
	int	g;
	int	b;
};

struct	s_check_info
{
	int	no;
	int	so;
	int	we;
	int	ea;
	int	f_color;
	int	c_color;
	int	first_map_line;
	int last_map_line;
	int len_x;
	int len_y;
};

struct	s_info
{
	char		**map;
	char		*textures[4];
	char		*no_texture;	
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	t_color		floor_color;
	t_color		ceilling_color;
	t_mlx		mlx;
};

#endif
