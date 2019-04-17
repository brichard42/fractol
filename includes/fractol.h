/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:23:22 by brichard          #+#    #+#             */
/*   Updated: 2019/04/17 16:43:11 by brichard         ###   ########.fr       */
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
# include <pthread.h>

# define W_WIDTH 1400
# define W_HEIGHT 800
# define NTHREADS 8

# define CONTROLS		"            CONTROLS"
# define S_ZOOM_IN		"    Zoom In     |     z"
# define S_ZOOM_OUT		"    Zoom Out    |     e"
# define S_CHANGE_V		"   Change View  |     i"
# define S_CENTER_V		"   Center View  |     p"
# define S_RESET_V		"   Reset  View  |     r"
# define S_EXIT			"  Exit Program  |     esc"

/*
**	main.c
*/

int				fract_close(void *param);

/*
**	fract_core.c
*/

void			fract_core(int fract);

/*
**	fract_init.c
*/

void			init_graph(t_graph *graph);
void			ft_init_env(t_mlx *env);

/*
**	ftab_init.c
*/

void			ft_init_keytab(t_keyfunc *tab, int size);
void			ft_init_moutab(t_moufunc *tab, int size);
void			ft_init_fracttab(t_fractfunc *tab, int size);

/*
**	fract_threads.c
*/

void			fract_threads(t_mlx *env);
void			*set_limits(void *env);

/*
**	image_pixel_put.c
*/

int				image_pixel_put(t_img *img, int x, int y, int colour);

/*
**	fract_series.c
*/

void			fract_series(t_mlx *env, int x, int width);

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
void			lock_mouse(void *env, int x, int y);

/*
**	mandelbrot.c
*/

void			mandelbrot(void *env, int x, int y);

/*
**	julia.c
*/

void			julia(void *env, int x, int y);

/*
**	zubieta.c
*/

void			zubieta(void *env, int x, int y);

/*
**	fract_colors.c
*/

int				get_color(int iter_num, int iter_max);

#endif
