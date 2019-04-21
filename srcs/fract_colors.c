/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:19:14 by brichard          #+#    #+#             */
/*   Updated: 2019/04/20 12:38:44 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_rgb(int color_1, int color_2, int offset, double deci)
{
	return (((color_1 >> offset) & 0xFF) + (((color_2 >> offset) & 0xFF) \
										- ((color_1 >> offset) & 0xFF)) * deci);
}

int			get_color(t_graph *graph, double iter_num)
{
	int		color_1;
	int		color_2;
	int		col;
	double	deci;

	color_1 = graph->color_tab[graph->pal_num][(((int)iter_num) % 5)];
	color_2 = graph->color_tab[graph->pal_num][((((int)iter_num) + 1) % 5)];
	deci = iter_num - (int)iter_num;
	if (iter_num < graph->max_iter && iter_num >= 0)
		col = (((0 << 24)) \
						| ((get_rgb(color_1, color_2, 16, deci) << 16)) \
						| ((get_rgb(color_1, color_2, 8, deci) << 8)) \
						| (get_rgb(color_1, color_2, 0, deci)));
	else
		col = 0;
	return (col);
}
