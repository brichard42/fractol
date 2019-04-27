/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_init_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 16:17:05 by brichard          #+#    #+#             */
/*   Updated: 2019/04/27 17:12:04 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_reverse_mandelbrot(t_graph *graph)
{
	graph->re.min = -1.77;
	graph->im.min = -1.63;
	graph->im.max = 1.67;
	graph->re.max = (W_WIDTH * (graph->im.max - graph->im.min)) / W_HEIGHT \
																+ graph->re.min;
}

void init_myfrac_1(t_graph *graph)
{
	graph->re.min = -2.9;
	graph->im.min = -1.2;
	graph->im.max = 1.2;
	graph->re.max = (W_WIDTH * (graph->im.max - graph->im.min)) / W_HEIGHT \
																+ graph->re.min;
}

void init_myfrac_2(t_graph *graph)
{
	graph->re.min = -2.9;
	graph->im.min = -1.2;
	graph->im.max = 1.2;
	graph->re.max = (W_WIDTH * (graph->im.max - graph->im.min)) / W_HEIGHT \
																+ graph->re.min;
}
