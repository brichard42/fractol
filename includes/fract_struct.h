/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:23:11 by brichard          #+#    #+#             */
/*   Updated: 2019/03/27 18:50:54 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_STRUCT_H
# define FRACT_STRUCT_H

# ifdef __APPLE__
#  include "TargetConditionals.h"
#  if TARGET_OS_MAC
#   define KEY_TAB 130
#   define MOU_TAB 7
#  endif
# elif __linux__
#  define KEY_TAB 65453
#  define MOU_TAB 7
# endif

typedef struct	s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct	s_graph
{
	t_point		d;
	t_point		center;
	int			max_iter;
}				t_graph;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
}				t_img;

typedef	void	(*t_keyfunc)(void *);
typedef	void	(*t_moufunc)(void *, int, int);

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_graph		graph;
	t_keyfunc	key_tab[KEY_TAB];
	t_moufunc	mou_tab[MOU_TAB];
}				t_mlx;

#endif
