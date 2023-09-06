/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_basics.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarrage <sbarrage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:21:05 by sbarrage          #+#    #+#             */
/*   Updated: 2023/09/04 16:28:59 by sbarrage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MLX_BASICS
# define MLX_BASICS

#include "cube.h"

/* exit_mlx */
void exit_mlx(t_data data);

/* hook_mlx */
int	handle_input(int keysym, t_data *data);

/* init_mlx */
int init_mlx(t_data *data);

#endif