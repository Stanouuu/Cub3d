/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:18:45 by sbarrage          #+#    #+#             */
/*   Updated: 2023/10/17 15:01:33 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	img_pix_put(t_imge *img, int x, int y, int color)
{
	char	*pixel;

	if (x > WIDTH || x < 0 || y > LENGTH || y < 0)
	{
		write(1, "h", 1);
		return ;
	}
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}