/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:46:35 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/12 14:23:34 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

//__>TYPE_MLX___________________________________________________________________
typedef struct s_data		t_data;
typedef struct s_mlx		t_mlx;
//__>TYPE_FOR_GAME______________________________________________________________
typedef struct s_player		t_player;
typedef struct s_ray		t_ray;
typedef struct s_draw		t_draw;
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

//__>Raycast____________________________________________________________________
struct	s_player
{
	int		posX;
	int		posY;
};

struct	s_ray
{
	int		stepX;
	int		stepY;
	int		side;
	double	sideDistX;
	double	sideDistY;
	double	vecDirX;
	double	vecDirY;
	double	rayDirX;
	double	rayDirY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
};

struct	s_draw
{
	int		startDraw;
	int		endDraw;
};

struct	s_game
{
	int			mapX;
	int			mapY;
	double		camX;
	double		planePosX;
	double		planePosY;
	t_player	player;
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
	int last_map_line;
	int len_x;
	int len_y;
};

struct	s_info
{
	int			**i_map;
	int			start_x;
	int			start_y;
	int			start_orientation;
	char		*textures[4];
	t_color		floor_color;
	t_color		ceilling_color;
	t_mlx		mlx;
	t_game		game;
};

#endif
