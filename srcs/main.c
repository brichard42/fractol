/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:22:19 by brichard          #+#    #+#             */
/*   Updated: 2019/03/18 16:51:38 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define MANDEL "mandelbrot"

int			main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	if (!(ft_strcmp(av[1], "mandelbrot")))
		mandelbrot();
	else
		return (0);
	return (0);
}
