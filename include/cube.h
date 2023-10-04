/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:09:47 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/04 16:04:07 by nklingsh         ###   ########.fr       */
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

typedef struct s_imge
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_imge;

/* map */

typedef struct s_map
{
	char *north;
	char *east;
	char *west;
	char *south; /* containing  image.xpm*/
	int floor_color;
	int ceiling_color;
	int **map;
	int map_width;
	int map_lenght;
} t_map;

/* for you change it as you please */

typedef struct s_player
{
	float	fov;
	float	x;
	float	y;
	float	a;
	float	eyex;
	float	eyey;
	float	ray_angle;
	float	distance_to_wall;

} t_player;


typedef struct s_math
{
	float camera;
	float rayDirx;
	float rayDiry;
} t_math;


typedef struct s_player2
{
	float posX;
	float posY;
	float dirX;
	float dirY;
	float planeX;
	float planeY;
	t_math math;
} t_player2;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		 **maptmp;
	t_player player;
	t_player2 player2;
	t_imge		img;
	t_map		map;
}	t_data;

# include "mlx_basics.h"
# include "render.h"

#endif
