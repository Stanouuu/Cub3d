/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_basics.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:21:05 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/18 16:09:55 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_BASICS_H
# define MLX_BASICS_H

# include "cube.h"

# define WIDTH 1500
# define LENGTH 900

typedef struct s_imge
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		*tex;
	int		line_len;
	int		tex_to_open;
	int		endian;
	int		tex_width;
	int		tex_height;
}	t_imge;

/* map */

typedef struct s_map
{
	char	*north;
	char	*east;
	char	*west;
	char	*south;
	int		floor_color;
	int		ceiling_color;
	int		**map;
	int		map_width;
	int		map_lenght;
}	t_map;

typedef struct s_tex
{
	t_imge	wall_no;
	t_imge	wall_so;
	t_imge	wall_we;
	t_imge	wall_ea;
}	t_tex;

/* for you change it as you please */

typedef struct s_player
{
	float	fov;
	float	x;
	float	y;
	float	a;
	float	dirx;
	float	diry;
	float	planex;
	float	planey;
	float	ray_angle;
	float	distance_to_wall;
	int		lineheight;
	int		drawstart;
	int		drawend;
	float	wallx;
	int		texx;
	int		texy;
}	t_player;

typedef struct s_ray
{
	float	camerax;
	float	raydirx;
	float	raydiry;
	int		mapx;
	int		mapy;
	float	sidedistx;
	float	sidedisty;
	float	deltadistx;
	float	deltadisty;
	float	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
}	t_ray;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			*stock_int;
	t_player	player;
	t_tex		*tex;
	t_ray		ray;
	t_imge		img;
	t_map		*map;
}	t_data;

/* exit_mlx */
void	exit_mlx(t_data *data);

/* hook_mlx */
int		handle_input(int keysym, t_data *data);

/* init_mlx */
int		init_mlx(t_data *data);

#endif
