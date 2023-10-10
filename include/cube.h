/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:09:47 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/10 13:42:28 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

#include <math.h>
#include <X11/Xlib.h>
# include "mlx_int.h"
# include "mlx.h"
#include "../source/gnl/get_next_line.h"
#include "libft.h"
# include "mlx_basics.h"
# include "render.h"

# define ERR_MLX_START "Could not start mlx"
# define ERR_MLX_WIN "Could not create mlx window"
# define ERR_MLX_IMG "Could not create mlx image"
# define ERR_MALLOC "Could not allocate memory"

// Taille de la fenêtre
# define WIN_WIDTH 640
# define WIN_HEIGHT 480

# define MOVESPEED 0.05
# define ROTEDSPEED 0.05

# define DIST_EDGE_MOUSE_WRAP 10

// taille ttextures mures
# define TEX_SIZE 64

// 
#endif
