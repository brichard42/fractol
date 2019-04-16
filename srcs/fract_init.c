/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:21:54 by brichard          #+#    #+#             */
/*   Updated: 2019/04/16 13:58:46 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_graph(t_graph *graph)
{
	graph->max_iter = 50;
	graph->re.max = 1.1;
	graph->re.min = -2.5;
	graph->im.max = 1;
	graph->im.min = -1;
	graph->scale.x = (graph->re.max - graph->re.min) / W_WIDTH;
	graph->scale.y = (graph->im.max - graph->im.min) / W_HEIGHT;
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
	ft_init_fracttab(env->fract_tab, MOU_TAB);
}
