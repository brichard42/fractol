/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:23:11 by brichard          #+#    #+#             */
/*   Updated: 2019/03/18 15:23:12 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

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
	t_keyfunc	key_tab[KEY_TAB];
}				t_mlx;

#endif
