/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:23:22 by brichard          #+#    #+#             */
/*   Updated: 2019/04/03 19:08:03 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include "colors.h"
# include "keycodes.h"
# include "mlx_events.h"
# include "fract_struct.h"
# include <stdlib.h>
# include <math.h>

# define W_WIDTH 1920
# define W_HEIGHT 1080

# define CONTROLS		"            CONTROLS"
# define S_ZOOM_IN		"    Zoom In     |     z"
# define S_ZOOM_OUT		"    Zoom Out    |     e"
# define S_CHANGE_V		"   Change View  |     i"
# define S_CENTER_V		"   Center View  |     p"
# define S_RESET_V		"   Reset  View  |     r"
# define S_EXIT			"  Exit Program  |     esc"

/*
**	image_pixel_put.c
*/

int				image_pixel_put(t_img *img, int x, int y, int colour);

/*
**	fract_init.c
*/

void			init_graph(t_graph *graph);
void			ft_init_env(t_mlx *env);

/*
**	mandelbrot.c
*/

void			mandelbrot(void);

/*
**	key_fun.c
*/

void			iter_inc(void *env);
void			iter_dec(void *env);
void			reset(void *env);

/*
**	mouse_fun.c
*/

void			center(void *env, int x, int y);
void			zoom_in(void *env, int x, int y);
void			zoom_out(void *env, int x, int y);

/*
**	fract_colors.c
*/

int		get_color(int iter_num, int iter_max);

#endif
