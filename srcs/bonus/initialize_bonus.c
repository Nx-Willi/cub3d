/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:05:21 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/20 05:03:55 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// a vector shows the direction in a plane with coordinates x and y as,
// if a vector goes to North, the y will increase of one, in south it'll
// decrease.
// same thing for the direction East and West with the x coordinate.
void	get_initial_vector_direction(t_game *game)
{
	int	orientation;

	orientation = game->infos->start_orientation;
	if (orientation == NO || orientation == SO)
	{
		if (orientation == NO)
			game->ray.vecdir_y = -1;
		else
			game->ray.vecdir_y = 1;
	}
	else if (orientation == WE || orientation == EA)
	{
		if (orientation == WE)
			game->ray.vecdir_x = -1;
		else
			game->ray.vecdir_x = 1;
	}
}

void	ray_calculs(t_game *game, int x)
{
	game->cam_x = 2 * x / (double)game->infos->mlx.win_width - 1;
	game->ray.raydir_x = game->ray.vecdir_x + game->planepos_x
		* game->cam_x;
	game->ray.raydir_y = game->ray.vecdir_y + game->planepos_y
		* game->cam_x;
	game->ray.pos_x = (int)game->ray.map_x;
	game->ray.pos_y = (int)game->ray.map_y;
	game->ray.deltadist_x = sqrt(1 + (game->ray.raydir_y * game->ray.raydir_y)
			/ (game->ray.raydir_x * game->ray.raydir_x));
	game->ray.deltadist_y = sqrt(1 + (game->ray.raydir_x * game->ray.raydir_x)
			/ (game->ray.raydir_y * game->ray.raydir_y));
}

void	get_step_for_ray(t_game *game)
{
	if (game->ray.raydir_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.sidedist_x = (game->ray.map_x - game->ray.pos_x)
			* game->ray.deltadist_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.sidedist_x = (game->ray.pos_x + 1.0 - game->ray.map_x)
			* game->ray.deltadist_x;
	}
	if (game->ray.raydir_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.sidedist_y = (game->ray.map_y - game->ray.pos_y)
			* game->ray.deltadist_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.sidedist_y = (game->ray.pos_y + 1.0 - game->ray.map_y)
			* game->ray.deltadist_y;
	}
}

void	get_next_hitten_wall(t_game *game)
{
	int	hit;

	hit = FALSE;
	while (hit == FALSE)
	{
		if (game->ray.sidedist_x < game->ray.sidedist_y)
		{
			game->ray.sidedist_x += game->ray.deltadist_x;
			game->ray.pos_x += game->ray.step_x;
			game->ray.side = FALSE;
		}
		else
		{
			game->ray.sidedist_y += game->ray.deltadist_y;
			game->ray.pos_y += game->ray.step_y;
			game->ray.side = TRUE;
		}
		if (game->infos->i_map[game->ray.pos_y][game->ray.pos_x] > 0)
			hit = TRUE;
	}
}

void	get_wall_and_draw_distance(t_game *game)
{
	if (game->ray.side == FALSE)
		game->ray.walldist = game->ray.sidedist_x - game->ray.deltadist_x;
	else
		game->ray.walldist = game->ray.sidedist_y - game->ray.deltadist_y;
	game->ray.line_height = (int)(game->infos->mlx.win_heigth
			/ game->ray.walldist);
	game->draw.startdraw = -game->ray.line_height / 2
		+ game->infos->mlx.win_heigth / 2;
	if (game->draw.startdraw < 0)
		game->draw.startdraw = 0;
	game->draw.enddraw = game->ray.line_height / 2
		+ game->infos->mlx.win_heigth / 2;
	if (game->draw.enddraw >= game->infos->mlx.win_heigth)
		game->draw.enddraw = game->infos->mlx.win_heigth - 1;
}
