/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: william <william@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:42:20 by william           #+#    #+#             */
/*   Updated: 2022/08/17 19:55:22 by william          ###   ########.fr       */
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
		game->draw_text.wall_x = game->ray.pos_y + game->ray.walldist
			* game->ray.raydir_y;
	else
		game->draw_text.wall_x = game->ray.pos_x + game->ray.walldist
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

void	draw_wall_line(t_info *infos, int x)
{
	int		y;
	t_game	*game;

	game = &infos->game;
	init_texture_variables(game);
	y = game->draw.startdraw - 1;
	while (++y <= game->draw.enddraw)
	{
		game->draw_text.tex_y = (int)game->draw_text.tex_pos
			& (game->textures[game->draw_text.texture].height - 1);
		game->draw_text.tex_pos += game->draw_text.step;
		put_texture(infos, game, x, y);
	}
}
