/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:42:20 by william           #+#    #+#             */
/*   Updated: 2022/08/21 18:45:54 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_texture(t_game *game)
{
	if (game->ray.side == FALSE)
	{
		if (game->ray.raydir_x < 0)
			game->draw_text.texture = T_WE;
		else
			game->draw_text.texture = T_EA;
	}
	else
	{
		if (game->ray.raydir_y < 0)
			game->draw_text.texture = T_NO;
		else
			game->draw_text.texture = T_SO;
	}
}

static void	init_texture_variables(t_game *game)
{
	get_texture(game);
	if (game->ray.side == FALSE)
		game->draw_text.wall_x = game->ray.map_y + game->ray.walldist
			* game->ray.raydir_y;
	else
		game->draw_text.wall_x = game->ray.map_x + game->ray.walldist
			* game->ray.raydir_x;
	game->draw_text.wall_x -= floor(game->draw_text.wall_x);
	game->draw_text.tex_x = (int)(game->draw_text.wall_x
			* (double)(game->textures[game->draw_text.texture].width));
	if (game->ray.side == FALSE && game->ray.raydir_x > 0)
		game->draw_text.tex_x = game->textures[game->draw_text.texture].width
			- game->draw_text.tex_x - 1;
	if (game->ray.side == TRUE && game->ray.raydir_y < 0)
		game->draw_text.tex_x = game->textures[game->draw_text.texture].width
			- game->draw_text.tex_x - 1;
	game->draw_text.step = 1.0 * game->textures[game->draw_text.texture].height
		/ game->ray.line_height;
	game->draw_text.tex_pos = (game->draw.startdraw
			- game->infos->mlx.win_heigth / 2 + game->ray.line_height / 2)
		* game->draw_text.step;
}

static void	put_texture(t_info *infos, t_game *game, int x, int y)
{
	int	texture;

	texture = game->draw_text.texture;
	infos->mlx.img.addr[y * infos->mlx.img.line_length + x
		* infos->mlx.img.bits_per_pixel / 8]
		= game->textures[texture].addr[game->draw_text.tex_y
		* game->textures[texture].line_length + game->draw_text.tex_x
		* (game->textures[texture].bits_per_pixel / 8)];
	infos->mlx.img.addr[y * infos->mlx.img.line_length + x
		* infos->mlx.img.bits_per_pixel / 8 + 1]
		= game->textures[texture].addr[game->draw_text.tex_y
		* game->textures[texture].line_length + game->draw_text.tex_x
		* (game->textures[texture].bits_per_pixel / 8) + 1];
	infos->mlx.img.addr[y * infos->mlx.img.line_length + x
		* infos->mlx.img.bits_per_pixel / 8 + 2]
		= game->textures[texture].addr[game->draw_text.tex_y
		* game->textures[texture].line_length + game->draw_text.tex_x
		* (game->textures[texture].bits_per_pixel / 8) + 2];
}

static void	draw_ceilling_and_floor(t_info *infos, t_draw *draw, int x)
{
	int	y;

	y = -1;
	while ((x >= 0 && x <= infos->mlx.win_width) && (++y >= 0
			&& y <= infos->mlx.win_heigth) && y < draw->startdraw)
	{
		infos->mlx.img.addr[y * infos->mlx.img.line_length + x
			* infos->mlx.img.bits_per_pixel / 8 + 2] = infos->ceilling_color.r;
		infos->mlx.img.addr[y * infos->mlx.img.line_length + x
			* infos->mlx.img.bits_per_pixel / 8 + 1] = infos->ceilling_color.g;
		infos->mlx.img.addr[y * infos->mlx.img.line_length + x
			* infos->mlx.img.bits_per_pixel / 8] = infos->ceilling_color.b;
	}
	y = draw->enddraw - 1;
	while ((x >= 0 && x <= infos->mlx.win_width) && (++y >= 0
			&& y <= infos->mlx.win_heigth) && y < infos->mlx.win_heigth)
	{
		infos->mlx.img.addr[y * infos->mlx.img.line_length + x
			* infos->mlx.img.bits_per_pixel / 8 + 2] = infos->floor_color.r;
		infos->mlx.img.addr[y * infos->mlx.img.line_length + x
			* infos->mlx.img.bits_per_pixel / 8 + 1] = infos->floor_color.g;
		infos->mlx.img.addr[y * infos->mlx.img.line_length + x
			* infos->mlx.img.bits_per_pixel / 8] = infos->floor_color.b;
	}
}

void	draw_wall_line(t_info *infos, int x)
{
	int		tmp;
	int		y;
	t_game	*game;

	game = &infos->game;
	y = game->draw.startdraw - 1;
	init_texture_variables(game);
	while ((x >= 0 && x <= infos->mlx.win_width)
		&& (++y >= 0 && y <= infos->mlx.win_heigth)
		&& y <= game->draw.enddraw)
	{
		tmp = y * game->textures[game->draw_text.texture].line_length
			- infos->mlx.win_heigth
			* game->textures[game->draw_text.texture].line_length / 2
			+ game->ray.line_height
			* game->textures[game->draw_text.texture].line_length / 2;
		game->draw_text.tex_y = ((tmp
					* game->textures[game->draw_text.texture].height)
				/ game->ray.line_height)
			/ game->textures[game->draw_text.texture].line_length;
		put_texture(infos, game, x, y);
	}
	draw_ceilling_and_floor(infos, &game->draw, x);
}
