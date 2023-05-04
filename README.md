# 🖱 42Paris Project | cub3d

## Objectives

The goal of this project is to make our first steps in the **Raycasting**.  
To help us, we will use the **[minilibx](https://harm-smits.github.io/42docs/libs/minilibx.html "42")** from 42, it asks to make a game in the steps of **[Wolfenstein 3D](http://users.atw.hu/wolf3d/)**.  
We have to manage the **textures** of the walls depending of their **directions**,  
set a **floor** and **ceiling colors** to two differents ones,  
move the camera with **W, A, S, D** (for moving) **LEFT_ARROW** and **RIGHT_ARROW** (for camera angle).  
The game will be **configured** by a **config file**, it define the **map**, the **color** of **floor** and **ceiling**, the **texture** files and the **start position** of the player.  
The mandatory part doesn't support wall collisions but the **bonus** part yes, we managed the **collision** and a **mini-map**.  

![image](https://user-images.githubusercontent.com/16923245/236213272-bdeab3d5-8d17-45ba-8ca2-3b19643b851f.png)

## Usage

`make` to compile the program.  
`make bonus` to compile with the bonus part.  
`clean` to clean objects files.  
`fclean` to clean objects files and program file.  

**Execute**: `./cub3D <map_name>`  
Few maps are already configured in maps folder.  

## Help

https://docs.google.com/document/d/1tdNYHg3Mfqf8dr8W6Ajs3seUugwtmaQizZ7BzimkXog/edit  
https://harm-smits.github.io/42docs/projects/cub3d  

## Score

[![wdebotte's 42 cub3d Score](https://badge42.vercel.app/api/v2/cl2zu1sil002509mf9zd91hy6/project/2706611)](https://github.com/JaeSeoKim/badge42)  

Done with [Xavier Le-baux](https://github.com/Xavier-LB "Xavier Le-baux")
