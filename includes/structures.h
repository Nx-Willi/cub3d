/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:46:35 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/11 17:09:54 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

//__>TYPE_MLX___________________________________________________________________
typedef struct s_data		t_data;
typedef struct s_mlx		t_mlx;
//__>TYPE_FOR_GAME______________________________________________________________
typedef struct s_player		t_player;
typedef struct s_plane		t_plane;
typedef struct s_ray		t_ray;
typedef struct s_draw		t_draw;
typedef struct s_bres		t_bres;
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

//__>IN_GAME____________________________________________________________________
struct	s_player
{
	int		posX;
	int		posY;
	double	initX;
	double	initY;
};

struct	s_plane
{
	double	posX;
	double	posY;
};

struct	s_ray
{
	int		stepX;
	int		stepY;
	int		side;
	double	vecDirX;
	double	vecDirY;
	double	rayDirX;
	double	rayDirY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
};

struct	s_draw
{
	int		Xstart;
	int		Xend;
};

struct	s_game
{
	int			map_posX;
	int			map_posY;
	double		camX;
	t_player	player;
	t_plane		plane;
	t_ray		ray;
	t_draw		draw;
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
	int			**i_map;
	char		**map;
	char		*textures[4];
	t_color		floor_color;
	t_color		ceilling_color;
	t_mlx		mlx;
	t_game		game;
};

#endif
