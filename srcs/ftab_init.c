/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftab_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:17:40 by brichard          #+#    #+#             */
/*   Updated: 2019/04/15 12:00:05 by brichard         ###   ########.fr       */
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
}

void	ft_init_moutab(t_moufunc *tab, int size)
{
	while (--size >= 0)
		tab[size] = NULL;
	tab[SCROLLUP_KEY] = zoom_in;
	tab[SCROLLDOWN_KEY] = zoom_out;
	tab[BUT1_KEY] = center;
}

void	ft_init_fracttab(t_fractfunc *tab, int size)
{
	while (--size >= 0)
		tab[size] = NULL;
	tab[0] = mandelbrot;
	tab[1] = julia;
	//tab[2] = tricorn;
}
