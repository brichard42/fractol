/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:56:55 by brichard          #+#    #+#             */
/*   Updated: 2019/03/27 19:16:06 by brichard         ###   ########.fr       */
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
