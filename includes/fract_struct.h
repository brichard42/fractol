/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:23:11 by brichard          #+#    #+#             */
/*   Updated: 2019/04/18 15:14:06 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_STRUCT_H
# define FRACT_STRUCT_H

# ifdef __APPLE__
#  include "TargetConditionals.h"
#  if TARGET_OS_MAC
#   define KEY_TAB 130
#   define MOU_TAB 7
#   define FRACT_TAB 3
#  endif
# elif __linux__
#  define KEY_TAB 65453
#  define MOU_TAB 7
#  define FRACT_TAB 3
# endif

typedef struct	s_mouse
{
	int			x;
	int			y;
}				t_mouse;

typedef struct	s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct	s_dif
{
	double		max;
	double		min;
}				t_dif;

typedef struct	s_graph
{
	int			type;
	int			color_tab[5][5];
	int			pal_num;
	t_point		c;
	t_dif		re;
	t_dif		im;
	t_point		scale;
	int			max_iter;
	int			lock_mouse;
}				t_graph;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
}				t_img;

typedef	void	(*t_keyfunc)(void *);
typedef	void	(*t_moufunc)(void *, int, int);
typedef	void	(*t_fractfunc)(void *, int, int);

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_graph		graph;
	t_keyfunc	key_tab[KEY_TAB];
	t_moufunc	mou_tab[MOU_TAB];
	t_fractfunc	fract_tab[FRACT_TAB];
}				t_mlx;

#endif
