/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:23:22 by brichard          #+#    #+#             */
/*   Updated: 2019/04/27 17:13:15 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include "mlx_events.h"
# include "colors.h"
# include "keycodes.h"
# include "fract_struct.h"
# include <stdlib.h>
# include <pthread.h>
# include <math.h>

# define W_WIDTH 1400
# define W_HEIGHT 800
# define NTHREADS 8

# define CONTROLS		"   |_____________CONTROLS_____________|"
# define S_CHANGE_C		"   | Change Color   |    [Tab]        |"
# define S_CHANGE_FR	"   | Change Fractal |    [1]          |"
# define S_CHANGE_FO	"   | Change Form    |    Middle Clic  |"
# define S_ZOOM			"   | Zoom In / out  |    Mouse Scroll |"
# define S_CENTER_V		"   | Center_on_Clic |    Left Clic    |"
# define S_RESET_V		"   | Reset          |    [r]          |"
# define S_EXIT			"   | Exit Program   |    [esc]        |"
# define S_ENDLINE		"   |__________________________________|"

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
**	init_type.c
*/

void			init_mandelbrot(t_graph *graph);
void			init_julia(t_graph *graph);
void			init_zubieta(t_graph *graph);
void			init_tricorn(t_graph *graph);
void			init_ship(t_graph *graph);

/*
**	init_type_2.c
*/

void			init_reverse_mandelbrot(t_graph *graph);
void			init_myfrac_1(t_graph *graph);
void			init_myfrac_2(t_graph *graph);

/*
**	fract_threads.c
*/

void			fract_threads(t_mlx *env);

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
void			color_swap(void *env);
void			fract_swap(void *env);

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
**	tricorn.c
*/

void			tricorn(void *env, int x, int y);

/*
**	ship.c
*/

void			ship(void *env, int x, int y);

/*
**	reverse_mandelbrot.c
*/

void			reverse_mandelbrot(void *env, int x, int y);

/*
**	my_frac_1.c
*/

void			my_frac_1(void *env, int x, int y);

/*
**	fract_colors.c
*/

int				get_color(t_graph *graph, double iter_num);

/*
**	fract_legend.c
*/

void			fract_legend(t_mlx *env);

#endif
