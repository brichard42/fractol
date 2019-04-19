/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:22:19 by brichard          #+#    #+#             */
/*   Updated: 2019/04/19 11:33:18 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	usage(void)
{
	ft_putendl("Error: No or Invalid parameter.");
	ft_putendl("Usage: ./fractol [julia] [mandelbrot] [zubieta]");
	return (0);
}

int			fract_close(void *param)
{
	t_mlx	*env;

	env = (t_mlx *)param;
	mlx_destroy_image(env->mlx_ptr, env->img.img_ptr);
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	exit(0);
	return (0);
}

int			main(int ac, char **av)
{
	if (ac != 2)
		return (usage());
	if (!(ft_strcmp(av[1], "mandelbrot")))
		fract_core(0);
	else if (!(ft_strcmp(av[1], "julia")))
		fract_core(1);
	else if (!(ft_strcmp(av[1], "zubieta")))
		fract_core(2);
	else
		return (usage());
	return (0);
}
