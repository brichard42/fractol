/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:23:11 by brichard          #+#    #+#             */
/*   Updated: 2019/03/21 16:10:54 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_STRUCT_H
# define FRACT_STRUCT_H

# ifdef __APPLE__
#  include "TargetConditionals.h"
#  if TARGET_OS_MAC
#   define KEY_TAB 130
#  endif
# elif __linux__
#  define KEY_TAB 65453
# endif

typedef struct	s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct	s_graph
{
	t_point		max;
	t_point		min;
	t_point		zoom;
	int			max_iter;
}				t_graph;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
}				t_img;

typedef	void	(*t_keyfunc)(void *);

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_graph		graph;
	t_keyfunc	key_tab[KEY_TAB];
}				t_mlx;

#endif
