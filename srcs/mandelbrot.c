/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:39:20 by brichard          #+#    #+#             */
/*   Updated: 2019/03/18 17:52:36 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	math(void)
{
	t_point	pix;
	t_point	zoom;

	zoom.x = W_WIDTH / (1.0 - (-2.5));
	zoom.x = W_HEIGTH / (1.0 - (-1));
	while (pix.x <= W_WIDTH)
	{
		while (pix.y <= W_HEIGHT)
		{
			x0 = scaled x coordinate of pixel (scaled to lie in the Mandelbrot X scale (-2.5, 1))
			y0 = scaled y coordinate of pixel (scaled to lie in the Mandelbrot Y scale (-1, 1))
			x = 0.0
			y = 0.0
			iteration = 0
			max_iteration = 1000
			while (x*x + y*y <= 2*2  AND  iteration < max_iteration)
			{
				xtemp = x*x - y*y + x0
				y = 2*x*y + y0
				x = xtemp
				iteration = iteration + 1
			}
			color = palette[iteration]
			plot(Px, Py, color)
			++pix.y;
		}
		++pix.x;
	}
}

static int	fract_close(void *param)
{
	t_mlx	*env;

	env = (t_mlx *)param;
	mlx_destroy_image(env->mlx_ptr, env->img.img_ptr);
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	exit(0);
	return (0);
}

static int	do_key_rel(int keycode, void *param)
{
	t_mlx	*env;

	env = (t_mlx *)param;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(env->mlx_ptr, env->img.img_ptr);
		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
		exit(0);
	}
	return (0);
}

static int	do_key_press(int keycode, void *param)
{
	t_mlx	*env;

	env = (t_mlx *)param;
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	ft_bzero(env->img.data, W_HEIGHT * W_WIDTH * 4);
	if (keycode >= 0 && keycode <= KEY_TAB && env->key_tab[keycode])
		ft_printf("Function's got a call!\n");;
	math();
	return (0);
}

void		mandelbrot(void)
{
	t_mlx		env;

	ft_init_env(&env);
	mlx_hook(env.win_ptr, KEYPRESS, KEYPRESSMASK, do_key_press, (void *)&env);
	mlx_hook(env.win_ptr, KEYRELEASE, KEYRELEASEMASK, do_key_rel, (void *)&env);
	mlx_hook(env.win_ptr, DESTROYNOTIFY, STRUCTURENOTIFYMASK, \
			fract_close, (void *)&env);
	mlx_loop(env.mlx_ptr);
}
