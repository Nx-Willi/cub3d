#include "cub3d.h"

// int infos->i_map[24][24]=
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

void	raycasting(t_info *infos)
{
	double posX;
	double posY;

	double dirX;
	double dirY;

	double planeX;
	double planeY;

	double time;
	double oldTime;

	int	x;

	double cameraX;
	double rayDirX;
	double rayDirY;


    int mapX;
    int mapY;

    //length of ray from current position to next x or y-side
    double sideDistX;
    double sideDistY;

    double deltaDistX;
    double deltaDistY;
    double perpWallDist;

    //what direction to step in x or y-direction (either +1 or -1)
	int stepX;
	int stepY;

    int hit;
    int side; //was a NS or a EW wall hit?

	int lineHeight;
	int drawStart;
	int drawEnd;

	int	color;
	//x and y start position
	posX = 22;
	posY = 12;

	//initial direction vector
	dirX = -1;
	dirY = 0;

	//the 2d raycaster version of camera plane
	planeX = 0;
	planeY = 0.66;

	time = 0; //time of current frame
	oldTime = 0; //time of previous frame

	x = -1;
	while (++x < infos->mlx.win_width)
	{
		//calculate ray position and direction
		cameraX = 2 * x / (double)infos->mlx.win_width - 1; //x-coordinate in camera space
		rayDirX = dirX + planeX * cameraX;
		rayDirY = dirY + planeY * cameraX;


    	//which box of the map we're in
    	mapX = (int)posX;
    	mapY = (int)posY;

    	//length of ray from one x or y-side to next x or y-side
    	deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
    	deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));;

    	hit = 0; //was there a wall hit?

    	//calculate step and initial sideDist
    	if (rayDirX < 0)
    	{
    		stepX = -1;
    		sideDistX = (posX - mapX) * deltaDistX;
    	}
    	else
    	{
    		stepX = 1;
    		sideDistX = (mapX + 1.0 - posX) * deltaDistX;
    	}
    	if (rayDirY < 0)
    	{
    		stepY = -1;
    		sideDistY = (posY - mapY) * deltaDistY;
    	}
    	else
    	{
    		stepY = 1;
    		sideDistY = (mapY + 1.0 - posY) * deltaDistY;
    	}


    	//perform DDA
    	while (hit == 0)
    	{
    		//jump to next map square, either in x-direction, or in y-direction
    		if (sideDistX < sideDistY)
    		{
    			sideDistX += deltaDistX;
    			mapX += stepX;
    			side = 0;
    		}
    		else
    		{
    			sideDistY += deltaDistY;
    			mapY += stepY;
    			side = 1;
    		}
    		//Check if ray has hit a wall
    		if (infos->i_map[mapX][mapY] > 0)
				hit = 1;
    	} 

		//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
    	if(side == 0)
			perpWallDist = (sideDistX - deltaDistX);
    	else
			perpWallDist = (sideDistY - deltaDistY);

		
    	//Calculate height of line to draw on screen
    	lineHeight = (int)(infos->mlx.win_heigth / perpWallDist);

    	//calculate lowest and highest pixel to fill in current stripe
    	drawStart = -lineHeight / 2 + infos->mlx.win_heigth / 2;
    	if(drawStart < 0)
			drawStart = 0;
    	drawEnd = lineHeight / 2 + infos->mlx.win_heigth / 2;
    	if(drawEnd >= infos->mlx.win_heigth)
			drawEnd = infos->mlx.win_heigth - 1;

		
		if (infos->i_map[mapX][mapY] == 1)
		{
			printf("Wall mapX = %i mapY = %i worldMap = %i\n", mapX, mapY, infos->i_map[mapX][mapY]);
			color = 0x00FF0000;
		}
		else
		{
			printf("NO Wall mapX = %i mapY = %i worldMap = %i\n", mapX, mapY, infos->i_map[mapX][mapY]);
			color = 0x0000FF00;
		}
		draw_vertical_line(infos, x, drawStart, drawEnd, color);
		mlx_put_image_to_window(infos->mlx.mlx, infos->mlx.window,
				infos->mlx.img.img, 0, 0);
	}
}