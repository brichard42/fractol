/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:02:30 by brichard          #+#    #+#             */
/*   Updated: 2019/04/09 16:13:25 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	center(void *env, int x, int y)
{
	t_mlx	*tmp;
	t_point	mouse;
	t_point	dif;

	tmp = (t_mlx *)env;
	mouse.x = (double)x * ((tmp->graph.re.max - tmp->graph.re.min) / W_WIDTH) \
															+ tmp->graph.re.min;
	mouse.y = (double)y * ((tmp->graph.im.max - tmp->graph.im.min) / W_HEIGHT) \
															+ tmp->graph.im.min;
	dif.x = (tmp->graph.re.max - tmp->graph.re.min) / 2;
	dif.y = (tmp->graph.im.max - tmp->graph.im.min) / 2;
	tmp->graph.re.min = mouse.x - dif.x;
	tmp->graph.re.max = mouse.x + dif.x;
	tmp->graph.im.min = mouse.y - dif.y;
	tmp->graph.im.max = mouse.y + dif.y;
}

void	zoom_in(void *env, int x, int y)
{
	t_mlx	*tmp;
	t_point	mouse;

	tmp = (t_mlx *)env;
	mouse.x = (double)x * ((tmp->graph.re.max - tmp->graph.re.min) / W_WIDTH) \
															+ tmp->graph.re.min;
	mouse.y = (double)y * ((tmp->graph.im.max - tmp->graph.im.min) / W_HEIGHT) \
															+ tmp->graph.im.min;
	tmp->graph.re.max = mouse.x + ((tmp->graph.re.max - mouse.x) * 0.9);
	tmp->graph.im.max = mouse.y + ((tmp->graph.im.max - mouse.y) * 0.9);
	tmp->graph.re.min = mouse.x + ((tmp->graph.re.min - mouse.x) * 0.9);
	tmp->graph.im.min = mouse.y + ((tmp->graph.im.min - mouse.y) * 0.9);
}

void	zoom_out(void *env, int x, int y)
{
	t_mlx	*tmp;
	t_point	mouse;

	tmp = (t_mlx *)env;
	mouse.x = (double)x * ((tmp->graph.re.max - tmp->graph.re.min) / W_WIDTH) \
															+ tmp->graph.re.min;
	mouse.y = (double)y * ((tmp->graph.im.max - tmp->graph.im.min) / W_HEIGHT) \
															+ tmp->graph.im.min;
	tmp->graph.re.max = mouse.x + ((tmp->graph.re.max - mouse.x) * 1.1);
	tmp->graph.im.max = mouse.y + ((tmp->graph.im.max - mouse.y) * 1.1);
	tmp->graph.re.min = mouse.x + ((tmp->graph.re.min - mouse.x) * 1.1);
	tmp->graph.im.min = mouse.y + ((tmp->graph.im.min - mouse.y) * 1.1);
}
