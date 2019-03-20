/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:23:22 by brichard          #+#    #+#             */
/*   Updated: 2019/03/20 19:04:19 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# ifdef __APPLE__
#  include "TargetConditionals.h"
#  if TARGET_OS_MAC
#   define KEY_ESC 53
#  endif
# elif __linux__
#  define KEY_ESC 65307
# endif

# include "libft.h"
# include "mlx.h"
# include "colors.h"
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

void			ft_init_env(t_mlx *env);

/*
**	mandelbrot.c
*/

void			mandelbrot(void);

/*
**	EVENT DEFINITIONS
*/

/*
**	Input Event Masks. Used as event-mask window attribute and as arguments
**	to Grab requests.  Not to be confused with event names.
*/

# define KEYPRESSMASK				(1L<<0)
# define KEYRELEASEMASK				(1L<<1)
# define STRUCTURENOTIFYMASK		(1L<<17)

/*
**	Event names.  Used in "type" field in XEvent structures.  Not to be
**	confused with event masks above.  They start from 2 because 0 and 1
**	are reserved in the protocol for errors and replies.
*/

# define KEYPRESS				2
# define KEYRELEASE				3
# define DESTROYNOTIFY			17

#endif
