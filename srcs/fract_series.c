/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_series.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:48:15 by brichard          #+#    #+#             */
/*   Updated: 2019/04/09 11:47:33 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fract_series(t_mlx *env, int x, int width)
{
	int		tx;
	int		y;
	t_point	scale;

	scale.x = (env->graph.re.max - env->graph.re.min) / W_WIDTH;
	scale.y = (env->graph.im.max - env->graph.im.min) / W_HEIGHT;
	y = 0;
	while (y <= W_HEIGHT)
	{
		tx = x;
		while (tx <= width)
		{
			env->fract_tab[env->graph.type]((void *)env, scale, tx, y);
			++tx;
		}
		++y;
	}
}
