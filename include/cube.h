/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:09:47 by sbarrage          #+#    #+#             */
/*   Updated: 2023/09/16 13:46:23 by stan             ###   ########.fr       */
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

/* Ours */

typedef struct s_imge
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		zoom;
	int		mr_cl;
	int		iso;
	int		color;
	double	h;
}	t_imge;

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

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	t_player	player;
	t_imge		img;
}	t_data;

# include "mlx_basics.h"
# include "render.h"

#endif
