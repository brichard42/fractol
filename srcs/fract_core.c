/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:48:23 by brichard          #+#    #+#             */
/*   Updated: 2019/04/15 12:01:15 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	t_mlx		*env;

	env = (t_mlx *)param;
	if (keycode >= 0 && keycode <= KEY_TAB && env->key_tab[keycode])
	{
		env->key_tab[keycode]((void *)env);
		fract_threads(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.img_ptr, 0, 0);
		mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 30, 0xFFFFFF, ft_lltoa((int)env->graph.max_iter));
	}
	return (0);
}

static int	do_mouse_press(int keycode, int x, int y, void *param)
{
	t_mlx		*env;
	int			i;

	env = (t_mlx *)param;
	if (keycode >= 0 && keycode <= MOU_TAB && env->mou_tab[keycode])
	{
		env->mou_tab[keycode]((void *)env, x, y);
		fract_threads(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.img_ptr, 0, 0);
		mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 30, 0xFFFFFF, ft_lltoa((int)env->graph.max_iter));
	}
	return (0);
}

static int	do_mouse_motion(int x, int y, void *param)
{
	t_mlx		*env;
	int			i;

	env = (t_mlx *)param;
	env->graph.mouse.x = x; //gaffe au debordement de fenetre
	env->graph.mouse.y = y;
	if (env->graph.type != 0)
	{
		fract_threads(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img.img_ptr, 0, 0);
		mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 30, 0xFFFFFF, ft_lltoa((int)env->graph.max_iter));
	}
	return (0);
}

void		fract_core(int fract)
{
	t_mlx		env;

	env.graph.type = fract;
	ft_init_env(&env);
	init_graph(&env.graph);
	mlx_put_image_to_window(env.mlx_ptr, env.win_ptr, env.img.img_ptr, 0, 0);
	mlx_hook(env.win_ptr, KEYPRESS, KEYPRESSMASK, do_key_press, (void *)&env);
	mlx_hook(env.win_ptr, KEYRELEASE, KEYRELEASEMASK, do_key_rel, (void *)&env);
	mlx_hook(env.win_ptr, DESTROYNOTIFY, STRUCTURENOTIFYMASK, \
			fract_close, (void *)&env);
	mlx_hook(env.win_ptr, BUTTONPRESS, BUTTONPRESSMASK, do_mouse_press, \
			(void *)&env);
	mlx_hook(env.win_ptr, MOTIONNOTIFY, POINTERMOTIONMASK, do_mouse_motion, \
			(void *)&env);
	mlx_loop(env.mlx_ptr);
}
