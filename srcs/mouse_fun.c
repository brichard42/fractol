/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:02:30 by brichard          #+#    #+#             */
/*   Updated: 2019/03/27 18:30:27 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	center(void *env, int x, int y)
{
	t_mlx *tmp;

	tmp = (t_mlx *)env;
	tmp->graph.center.x = (tmp->graph.d.x * (((double)x / W_WIDTH) - 0.5)) + tmp->graph.center.x;
	tmp->graph.center.y = (tmp->graph.d.y * (((double)y / W_HEIGHT) - 0.5)) + tmp->graph.center.y;
}

void	zoom_in(void *env, int x, int y)
{
	t_mlx *tmp;

	tmp = (t_mlx *)env;
	(void)x;
	(void)y;
	tmp->graph.d.x *= 0.9;
	tmp->graph.d.y *= 0.9;
}

void	zoom_out(void *env, int x, int y)
{
	t_mlx *tmp;

	tmp = (t_mlx *)env;
	(void)x;
	(void)y;
	tmp->graph.d.x *= 1.1;
	tmp->graph.d.y *= 1.1;
}
