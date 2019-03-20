/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:39:20 by brichard          #+#    #+#             */
/*   Updated: 2019/03/20 19:03:30 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define X1 -2.55
#define X2 1
#define Y1 -1
#define Y2 1
#define MAX_ITER 1000

static void	math(t_mlx *env)
{
	int		x;
	int		y;
	int		i;
	double tmp;
	t_point	zoom;
	t_point c;
	t_point	z;

	zoom.x = W_WIDTH / (X2 - X1);
	zoom.y = W_HEIGHT / (Y2 - Y1);
	y = 0;
	while (y <= W_HEIGHT)
	{
		x = 0;
		while (x <= W_WIDTH)
		{
			c.x = x / zoom.x + X1;
			c.y = y / zoom.y + Y1;
			z.x = 0;
			z.y = 0;
			i = 0;
			while (i <= MAX_ITER && z.x * z.x + z.y * z.y < 4)
			{
				tmp = z.x;
				z.x = z.x * z.x - z.y * z.y + c.x;
				z.y = 2 * z.y * tmp + c.y;
				++i;
			}
			if (i <= MAX_ITER)
				image_pixel_put(&env->img, x, y, 0xFFFFFF);
			++x;
		}
		++y;
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
	math(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.img_ptr, 0, 0);
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
