/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_series.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:48:15 by brichard          #+#    #+#             */
/*   Updated: 2019/04/21 12:00:11 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fract_series(t_mlx *env, int x, int width)
{
	int		tx;
	int		y;

	y = 0;
	while (y <= W_HEIGHT)
	{
		tx = x;
		while (tx <= width)
		{
			if (env->fract_tab[env->graph.type] != NULL)
				env->fract_tab[env->graph.type]((void *)env, tx, y);
			++tx;
		}
		++y;
	}
}
