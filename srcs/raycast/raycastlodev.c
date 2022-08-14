/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastlodev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:23:37 by william           #+#    #+#             */
/*   Updated: 2022/08/14 15:33:16 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int worldMap[24][24]=
// {
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
//   {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// };

static void	draw_vertical_line(t_info *infos, int x, int drawStart,
			int drawEnd, int color)
{
	int	y;

	y = drawStart;
	while (y < drawEnd)
	{
		my_mlx_pixel_put(&infos->mlx, x, y, color);
		y++;
	} 
}

void	do_raycasting(t_info *infos)
{
	// Start position
	double	init_pos_x = 3;
	double	init_pos_y = 3;
	// Initial direction vector
	double	dirX = 0;
	double	dirY = 1;
	// 2D raycaster of camera plane
	double	planeX = 0;
	double	planeY = 0.66;
	int	x = -1;
	int	w = infos->mlx.win_width;
	while (++x < w)
	{
		// Calculate ray position
		double	cameraX = 2 * x / (double)w - 1;
		double	raydir_x = dirX + planeX * cameraX;
		double	raydir_y = dirY + planeY * cameraX;
		// Position in map
		int	pos_x = (int)init_pos_x;
		int	pos_y = (int)init_pos_y;
		// length of ray from position to next x | y side
		double	sidedist_x;
		double	sidedist_y;
		// lot of doc
		double	deltadist_x = sqrt(1 + (raydir_y * raydir_y)
			/ (raydir_x * raydir_x));
		double	deltadist_y = sqrt(1 + (raydir_x * raydir_x)
			/ (raydir_y * raydir_y));
		double	walldist;
		// Step direction
		int	step_x;
		int	step_y;
		// Wall hit
		int	hit = 0;
		int	side;
		// calculate step
		if(raydir_x < 0)
		{
			step_x = -1;
			sidedist_x = (init_pos_x - pos_x) * deltadist_x;
		}
		else
		{
			step_x = 1;
			sidedist_x = (pos_x + 1.0 - init_pos_x) * deltadist_x;
		}
		if(raydir_y < 0)
		{
			step_y = -1;
			sidedist_y = (init_pos_y - pos_y) * deltadist_y;
		}
		else
		{
			step_y = 1;
			sidedist_y = (pos_y + 1.0 - init_pos_y) * deltadist_y;
		}
		//perform DDA
		while(hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if(sidedist_x < sidedist_y)
			{
				sidedist_x += deltadist_x;
				pos_x += step_x;
				side = 0;
			}
			else
			{
				sidedist_y += deltadist_y;
				pos_y += step_y;
				side = 1;
			}
			//Check if ray has hit a wall
			if(infos->i_map[pos_y][pos_x] > 0 || infos->i_map[pos_y][pos_x] == -1)
				hit = 1;
		}
		if( side == 0)
			walldist = (sidedist_x - deltadist_x);
		else
			walldist = (sidedist_y - deltadist_y);
		//Calculate height of line to draw on screen
		int	h = infos->mlx.win_heigth;
		int lineHeight = (int)(h / walldist);
		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + h / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + h / 2;
		if(drawEnd >= h)
			drawEnd = h - 1;
		int	color;
		if (infos->i_map[pos_y][pos_x] == 1)	
			color = 0x00FF0000;
		else
			color = 0x0000FF00;
		draw_vertical_line(infos, x, drawStart, drawEnd, color);
		mlx_put_image_to_window(infos->mlx.mlx, infos->mlx.window,
			infos->mlx.img.img, 0, 0);
	}
}