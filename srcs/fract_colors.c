/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:19:14 by brichard          #+#    #+#             */
/*   Updated: 2019/04/18 20:08:05 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(t_graph *graph, double iter_num)
{
	int	color_1;
	int	color_2;
	int	red;
	int	green;
	int	blue;
	int	col;
	double	deci;

	color_1 = graph->color_tab[graph->pal_num][(((int)iter_num) % 5)];
	color_2 = graph->color_tab[graph->pal_num][((((int)iter_num) + 1) % 5)];
	deci = iter_num - (int)iter_num;
	red = ((color_1 >> 16) & 0xFF) + (((color_2 >> 16) & 0xFF) - ((color_1 >> 16) & 0xFF)) * deci;
	green = ((color_1 >> 8) & 0xFF) + (((color_2 >> 8) & 0xFF) - ((color_1 >> 8) & 0xFF)) * deci;
	blue = (color_1 & 0xFF) + (((color_2) & 0xFF) - ((color_1) & 0xFF)) * deci;
	if (iter_num < graph->max_iter)
		col = ((0 << 24) | (red << 16) | (green << 8) | blue);
	else
		col = 0;
	return (col);
}
