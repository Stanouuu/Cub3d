/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:09:47 by sbarrage          #+#    #+#             */
/*   Updated: 2023/09/22 22:00:33 by stan             ###   ########.fr       */
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

#define HEIGHT 480
#define WIDTH 640
#define texWidth 64
#define texHeight 64
#define mapWidth 24
#define mapHeight 24

typedef struct s_imge
{
	void	*mlx_img;
	char	*addr;
	int		*data;
	int		bpp;
	int		line_len;
	int		endian;
	int		size;
	int 	img_w;
	int		img_h;
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
	float	posX;
	float	posY;
	float	dirX;
	float	dirY;
	float	planeX;
	float	planeY;
	int		**texture;
	float	movespeed;
	float	roatationspeed;
	int		re_buf;

} t_player;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		 **maptmp;
	int			bufbuf[HEIGHT][WIDTH];
	t_player player;
	t_imge		img;
	t_map		map;
}	t_data;

# include "mlx_basics.h"
# include "render.h"


int loop_loop(t_data *data);
void load_texture(t_data *data);


#endif
