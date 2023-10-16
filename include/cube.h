/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklingsh <nklingsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:09:47 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/16 17:34:13 by nklingsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

#include <math.h>
#include <X11/Xlib.h>
# include "mlx_int.h"
#include <stdlib.h>
# include "mlx.h"
#include "../source/gnl/get_next_line.h"
#include "libft.h"
#include <errno.h>

# define WIDTH 1500
# define LENGTH 900

typedef struct s_imge
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		*tex;
	int		line_len;
	int 	tex_to_open;
	int		endian;
	int		tex_width;
	int		tex_height;
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

typedef struct s_tex
{
	t_imge *wall_no;
	t_imge *wall_so;
	t_imge *wall_we;
	t_imge *wall_ea;
} t_tex;

/* for you change it as you please */

typedef struct s_player
{
	float	fov;
	float	x;
	float	y;
	float	a;
	float	dirX;
	float	dirY;
	float	planeX;
	float	planeY;
	float	ray_angle;
	float	distance_to_wall;
} t_player;

typedef struct s_ray
{
	float camerax;
	float rayDirX;
	float rayDirY;
	int mapx;
	int mapy;
	float sideDistX;
	float sideDistY;
	float deltadistX;
	float deltadistY;
	float perpWallDist;
	int		stepX;
	int		stepY;
	int hit ;
	int side;
} t_ray;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			*stock_int;
	t_player player;
	t_tex 		*tex;
	t_ray		ray;
	t_imge		img;
	t_map		*map;
}	t_data;

void	ft_error(t_map *map, t_data *data, char *str);
void	ft_exit(t_data *data);
void	free_mat(void **tab, int l);
void	init_tex(t_data *data);
void	ft_exit_map(t_map *map);

# include "mlx_basics.h"
# include "render.h"
# include "parse.h"

#endif
