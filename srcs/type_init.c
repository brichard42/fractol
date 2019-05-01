/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 15:44:29 by brichard          #+#    #+#             */
/*   Updated: 2019/05/01 19:24:35 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_mandelbrot(t_graph *graph)
{
	graph->re.min = -2.9;
	graph->im.min = -1.2;
	graph->im.max = 1.2;
	graph->re.max = (W_WIDTH * (graph->im.max - graph->im.min)) / W_HEIGHT \
					+ graph->re.min;
}

void init_julia(t_graph *graph)
{
	graph->re.min = -1.8;
	graph->im.min = -1.0;
	graph->im.max = 1.0;
	graph->re.max = (W_WIDTH * (graph->im.max - graph->im.min)) / W_HEIGHT \
					+ graph->re.min;
	graph->c.x = -0.75;
	graph->c.y = 0.0525;
}

void init_zubieta(t_graph *graph)
{
	graph->re.min = -2;
	graph->im.min = -1.1;
	graph->im.max = 1.2;
	graph->re.max = (W_WIDTH * (graph->im.max - graph->im.min)) / W_HEIGHT \
					+ graph->re.min;
	graph->c.x = 0.06;
	graph->c.y = 0.155;
}

void init_tricorn(t_graph *graph)
{
	graph->re.min = -3.8;
	graph->im.min = -2;
	graph->im.max = 2.1;
	graph->re.max = (W_WIDTH * (graph->im.max - graph->im.min)) / W_HEIGHT \
					+ graph->re.min;
}

void init_ship(t_graph *graph)
{
	graph->re.min = -3.6;
	graph->im.min = -2.1;
	graph->im.max = 1.5;
	graph->re.max = (W_WIDTH * (graph->im.max - graph->im.min)) / W_HEIGHT \
					+ graph->re.min;
}
