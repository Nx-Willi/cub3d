/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastlodev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:23:37 by william           #+#    #+#             */
/*   Updated: 2022/08/14 13:50:13 by wdebotte         ###   ########.fr       */
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
	double	init_posX = 3;
	double	init_posY = 3;
	// Initial direction vector
	double	dirX = 1;
	double	dirY = 0;
	// 2D raycaster of camera plane
	double	planeX = 0;
	double	planeY = 0.66;
	int	x = -1;
	int	w = infos->mlx.win_width;
	while (++x < w)
	{
		// Calculate ray position
		double	cameraX = 2 * x / (double)w - 1;
		double	rayDirX = dirX + planeX * cameraX;
		double	rayDirY = dirY + planeY * cameraX;
		// Position in map
		int	posX = (int)init_posX;
		int	posY = (int)init_posY;
		// length of ray from position to next x | y side
		double	sideDistX;
		double	sideDistY;
		// lot of doc
		double	deltaDistX = sqrt(1 + (rayDirY * rayDirY)
			/ (rayDirX * rayDirX));
		double	deltaDistY = sqrt(1 + (rayDirX * rayDirX)
			/ (rayDirY * rayDirY));
		double	perpWallDist;
		// Step direction
		int	stepX;
		int	stepY;
		// Wall hit
		int	hit = 0;
		int	side;
		// calculate step
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (init_posX - posX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (posX + 1.0 - init_posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (init_posY - posY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (posY + 1.0 - init_posY) * deltaDistY;
		}
		//perform DDA
		while(hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				posX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				posY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if(infos->i_map[posY][posX] > 0 || infos->i_map[posY][posX] == -1)
				hit = 1;
		}
		if( side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);
		//Calculate height of line to draw on screen
		int	h = infos->mlx.win_heigth;
		int lineHeight = (int)(h / perpWallDist);
		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + h / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + h / 2;
		if(drawEnd >= h)
			drawEnd = h - 1;
		int	color;
		if (infos->i_map[posY][posX] == 1)	
			color = 0x00FF0000;
		else
			color = 0x0000FF00;
		draw_vertical_line(infos, x, drawStart, drawEnd, color);
		mlx_put_image_to_window(infos->mlx.mlx, infos->mlx.window,
			infos->mlx.img.img, 0, 0);
	}
}