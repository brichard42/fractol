/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:02:30 by brichard          #+#    #+#             */
/*   Updated: 2019/03/22 15:58:59 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	center(void *env, int x, int y)
{
	t_mlx *tmp;

	tmp = (t_mlx *)env;
	tmp->graph.center.x = x / tmp->graph.zoom.x;
	tmp->graph.center.y = y / tmp->graph.zoom.y;
}

void	zoom_in(void *env)
{
	t_mlx *tmp;

	tmp = (t_mlx *)env;
	tmp->graph.d.x *= 0.9;
	tmp->graph.d.y *= 0.9;
}

void	zoom_out(void *env)
{
	t_mlx *tmp;

	tmp = (t_mlx *)env;
	tmp->graph.d.x *= 1.1;
	tmp->graph.d.y *= 1.1;
}
