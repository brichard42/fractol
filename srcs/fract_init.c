/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:21:54 by brichard          #+#    #+#             */
/*   Updated: 2019/03/27 19:16:59 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_graph(t_graph *graph)
{
	graph->max_iter = 50;
	graph->d.x = 3.6;
	graph->d.y = 2;
	graph->center.x = -0.8;
	graph->center.y = 0;

}

static void	ft_init_keytab(t_keyfunc *tab, int size)
{
	while (--size >= 0)
		tab[size] = NULL;
	tab[UP_KEY] = iter_inc;
	tab[DOWN_KEY] = iter_dec;
	tab[R_KEY] = reset;
}

static void	ft_init_moutab(t_moufunc *tab, int size)
{
	while (--size >= 0)
		tab[size] = NULL;
	tab[SCROLLUP_KEY] = zoom_in;
	tab[SCROLLDOWN_KEY] = zoom_out;
	tab[BUT1_KEY] = center;
}

void		ft_init_env(t_mlx *env)
{
	int		bpp;
	int		endian;
	int		size_l;

	if (!(env->mlx_ptr = mlx_init()))
		exit(2);
	if (!(env->win_ptr = mlx_new_window(env->mlx_ptr, W_WIDTH,
											W_HEIGHT, "Fract'ol")))
		exit(3);
	if (!(env->img.img_ptr = mlx_new_image(env->mlx_ptr, W_WIDTH, W_HEIGHT)))
		exit(4);
	if (!(env->img.data = (int *)mlx_get_data_addr(env->img.img_ptr, \
													&bpp, &size_l, &endian)))
		exit(5);
	ft_init_keytab(env->key_tab, KEY_TAB);
	ft_init_moutab(env->mou_tab, MOU_TAB);
}
