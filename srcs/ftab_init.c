/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftab_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:17:40 by brichard          #+#    #+#             */
/*   Updated: 2019/05/01 12:25:17 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_keytab(t_keyfunc *tab, int size)
{
	while (--size >= 0)
		tab[size] = NULL;
	tab[UP_KEY] = iter_inc;
	tab[DOWN_KEY] = iter_dec;
	tab[R_KEY] = reset;
	tab[TAB_KEY] = color_swap;
	tab[K1_KEY] = fract_swap;
}

void	ft_init_moutab(t_moufunc *tab, int size)
{
	while (--size >= 0)
		tab[size] = NULL;
	tab[SCROLLUP_KEY] = zoom_in;
	tab[SCROLLDOWN_KEY] = zoom_out;
	tab[BUT1_KEY] = center;
	tab[BUT3_KEY] = lock_mouse;
}

void	ft_init_fracttab(t_fractfunc *tab, int size)
{
	while (--size >= 0)
		tab[size] = NULL;
	tab[0] = mandelbrot;
	tab[1] = julia;
	tab[2] = zubieta;
	tab[3] = tricorn;
	tab[4] = ship;
	tab[5] = reverse_mandelbrot;
	tab[6] = my_frac_1;
	tab[7] = my_frac_2;
}
