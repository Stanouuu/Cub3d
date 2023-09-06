/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:09:47 by sbarrage          #+#    #+#             */
/*   Updated: 2023/09/04 18:29:50 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

#include <X11/Xlib.h>
# include "mlx_int.h"
# include "mlx.h"

/* Ours */

typedef struct s_imge
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		try;
	int		trx;
	double	ry;
	double	rx;
	int		zoom;
	int		mr_cl;
	int		iso;
	int		color;
	double	h;
}	t_imge;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			map;
	int			refresh;
	t_imge		img;
}	t_data;

# include "mlx_basics.h"
# include "render.h"

#endif
