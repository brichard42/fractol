/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:02:30 by brichard          #+#    #+#             */
/*   Updated: 2019/03/21 17:11:25 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	center(void *env, int x, int y)
{
	t_mlx *tmp;
	t_point mouse;
	t_point	win;

	tmp = (t_mlx *)env;
	mouse.x = x / tmp->graph.zoom.x;
	mouse.y = y / tmp->graph.zoom.y;
	win.x = (tmp->graph.max.x - tmp->graph.min.x);
	win.y = (tmp->graph.max.y - tmp->graph.min.y);
	tmp->graph.max.x += (mouse.x - win.x / 2);
	tmp->graph.max.y += (mouse.y - win.y / 2);
	tmp->graph.min.x += (mouse.x - win.x / 2);
	tmp->graph.min.y += (mouse.y - win.y / 2);
}
