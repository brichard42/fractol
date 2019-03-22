/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:39:20 by brichard          #+#    #+#             */
/*   Updated: 2019/03/22 15:55:45 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	math(t_mlx *env)
{
	int		x;
	int		y;
	int		i;
	double tmp;
	t_point c;
	t_point	z;

	env->graph.zoom.x = W_WIDTH / env->graph.d.x;
	env->graph.zoom.y = W_HEIGHT / env->graph.d.y;
	y = 0;
	while (y <= W_HEIGHT)
	{
		x = 0;
		while (x <= W_WIDTH)
		{
			c.x = x / env->graph.zoom.x + (env->graph.center.x - env->graph.d.x / 2);
			c.y = y / env->graph.zoom.y + (env->graph.center.y - env->graph.d.y / 2);
			z.x = 0;
			z.y = 0;
			i = 0;
			while (i <= env->graph.max_iter && z.x * z.x + z.y * z.y < 4)
			{
				tmp = z.x;
				z.x = z.x * z.x - z.y * z.y + c.x;
				z.y = 2 * z.y * tmp + c.y;
				++i;
			}
			if (i <= env->graph.max_iter)
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
	if (keycode == ESC_KEY)
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
		ft_printf("func's got a call!\n");
	math(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.img_ptr, 0, 0);
	return (0);
}

static int	do_mouse_press(int keycode, int x, int y, void *param)
{
	t_mlx	*env;

	env = (t_mlx *)param;
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	ft_bzero(env->img.data, W_HEIGHT * W_WIDTH * 4);
	if (keycode == SCROLLUP_KEY)
		zoom_in((void *)env);
	if (keycode == SCROLLDOWN_KEY)
		zoom_out((void *)env);
	if (keycode == BUT1_KEY)
		center((void *)env, x, y);
	math(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.img_ptr, 0, 0);
	return (0);
}

static void	init_graph(t_graph *graph)
{
	graph->max_iter = 50;
	graph->d.x = 3.6;
	graph->d.y = 2;
	graph->center.x = -0.8;
	graph->center.y = 0;

}

void		mandelbrot(void)
{
	t_mlx		env;

	ft_init_env(&env);
	init_graph(&env.graph);
	math(&env);
	mlx_put_image_to_window(env.mlx_ptr, env.win_ptr, env.img.img_ptr, 0, 0);
	mlx_hook(env.win_ptr, BUTTONPRESS, BUTTONPRESSMASK, do_mouse_press, \
			(void *)&env);
	mlx_hook(env.win_ptr, KEYPRESS, KEYPRESSMASK, do_key_press, (void *)&env);
	mlx_hook(env.win_ptr, KEYRELEASE, KEYRELEASEMASK, do_key_rel, (void *)&env);
	mlx_hook(env.win_ptr, DESTROYNOTIFY, STRUCTURENOTIFYMASK, \
			fract_close, (void *)&env);
	mlx_loop(env.mlx_ptr);
}
