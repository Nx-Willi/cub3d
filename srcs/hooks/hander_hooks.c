/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hander_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 13:41:43 by wdebotte          #+#    #+#             */
/*   Updated: 2022/08/07 13:59:04 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int key_handler(int keycode, t_mlx *mlx)
{
    (void)mlx;
    printf("%i\n", keycode);
}

void    handler_hooks(t_mlx *mlx)
{
    mlx_key_hook(mlx->window, );
}