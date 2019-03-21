/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:56:55 by brichard          #+#    #+#             */
/*   Updated: 2019/03/21 17:41:57 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(void *env)
{
	t_mlx *tmp;

	tmp = (t_mlx *)env;
	tmp->graph.max.y -= 0.05;
	tmp->graph.min.x += 0.05;
	tmp->graph.min.y += 0.05;
	tmp->graph.max.x = ((tmp->graph.max.y - tmp->graph.min.y) * W_WIDTH / W_HEIGHT) + tmp->graph.min.x;
}

void	zoom_out(void *env)
{
	t_mlx *tmp;

	tmp = (t_mlx *)env;
	tmp->graph.max.y += 0.05;
	tmp->graph.min.x -= 0.05;
	tmp->graph.min.y -= 0.05;
	tmp->graph.max.x = ((tmp->graph.max.y - tmp->graph.min.y) * W_WIDTH / W_HEIGHT) + tmp->graph.min.x;
}
