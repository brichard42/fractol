/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:56:55 by brichard          #+#    #+#             */
/*   Updated: 2019/04/21 11:59:56 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iter_inc(void *env)
{
	t_mlx	*tmp;

	tmp = (t_mlx *)env;
	tmp->graph.max_iter += 10;
}

void	iter_dec(void *env)
{
	t_mlx	*tmp;

	tmp = (t_mlx *)env;
	if (tmp->graph.max_iter != 10)
		tmp->graph.max_iter -= 10;
}

void	reset(void *env)
{
	init_graph(&((t_mlx *)env)->graph);
}

void	color_swap(void *env)
{
	t_mlx	*tmp;

	tmp = (t_mlx *)env;
	if (tmp->graph.pal_num != 4)
		++(tmp->graph.pal_num);
	else
		tmp->graph.pal_num = 0;
}

void	fract_swap(void *env)
{
	t_mlx	*tmp;

	tmp = (t_mlx *)env;
	if (tmp->graph.type < FRACT_TAB - 1)
		++(tmp->graph.type);
	else
		tmp->graph.type = 0;
	init_graph(&tmp->graph);
}
