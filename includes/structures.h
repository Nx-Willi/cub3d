/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:46:35 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/20 04:44:11 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

//__>TYPE_MLX___________________________________________________________________
typedef struct s_data		t_data;
typedef struct s_mlx		t_mlx;
//__>TYPE_FOR_GAME______________________________________________________________
typedef struct s_ray		t_ray;
typedef struct s_draw		t_draw;
typedef struct s_move		t_move;
typedef struct s_texture	t_texture;
typedef struct s_game		t_game;
//__>TYPE_PARSING_______________________________________________________________
typedef struct s_check_info	t_check_info;
typedef struct s_color		t_color;
//__>TYPE_STRUCT_GENERAL________________________________________________________
typedef struct s_info		t_info;
//‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾

//__>MLX________________________________________________________________________
struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
};

struct	s_mlx
{
	void	*mlx;
	void	*window;
	int		win_width;
	int		win_heigth;
	t_data	img;
	t_info	*infos;
};
//‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾

//__>Raycast____________________________________________________________________
struct	s_ray
{
	int		step_x;
	int		step_y;
	int		side;
	int		pos_x;
	int		pos_y;
	int		line_height;
	double	map_x;
	double	map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	vecdir_x;
	double	vecdir_y;
	double	raydir_x;
	double	raydir_y;
	double	deltadist_x;
	double	deltadist_y;
	double	walldist;
};

struct	s_draw
{
	int	startdraw;
	int	enddraw;
};

struct	s_move
{
	int	rot_right;
	int	rot_left;
	int	forward;
	int	backward;
	int	left;
	int	right;
};

struct	s_texture
{
	int		texture;
	int		tex_x;
	int		tex_y;
	double	wall_x;
	double	step;
	double	tex_pos;
};

struct	s_game
{
	double		cam_x;
	double		planepos_x;
	double		planepos_y;
	t_ray		ray;
	t_draw		draw;
	t_move		move;
	t_data		textures[4];
	t_texture	draw_text;
	t_info		*infos;
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
	int	spawning_position;
	int	f_color;
	int	c_color;
	int	first_map_line;
	int	last_map_line;
	int	len_x;
	int	len_y;
};

struct	s_info
{
	int		**i_map;
	int		start_x;
	int		start_y;
	int		map_width;
	int		map_height;
	int		start_orientation;
	char	*textures[4];
	t_color	floor_color;
	t_color	ceilling_color;
	t_mlx	mlx;
	t_game	game;
};

#endif
