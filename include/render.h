/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:26:01 by sbarrage          #+#    #+#             */
/*   Updated: 2023/09/12 19:31:53 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

#include "cube.h"

void	img_pix_put(t_imge *img, int x, int y, int color);
int render_ctrl(t_data *data);
void first_draft(t_data *data);

#endif
