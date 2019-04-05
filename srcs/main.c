/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:22:19 by brichard          #+#    #+#             */
/*   Updated: 2019/04/05 16:03:46 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	if (!(ft_strcmp(av[1], "mandelbrot"))) // PUT FUNC TAB HERE
		fract_core(0);
	else if (!(ft_strcmp(av[1], "julia")))
		fract_core(1);
	else
		return (0);
	return (0);
}
