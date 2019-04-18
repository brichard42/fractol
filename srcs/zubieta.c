/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zubieta.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:19:54 by brichard          #+#    #+#             */
/*   Updated: 2019/04/18 20:05:40 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		zubieta(void *env, int x, int y)
{
	double	i;
	double	tmp;
	t_point	z;
	t_mlx	*cenv;

	cenv = (t_mlx*)env;
	z.x = (double)(x * cenv->graph.scale.x + cenv->graph.re.min);
	z.y = (double)(y * cenv->graph.scale.y + cenv->graph.im.min);
	i = 0;
	while (z.x * z.x + z.y * z.y < (1 << 16) && (int)i < cenv->graph.max_iter)
	{
		tmp = z.x * z.x - z.y * z.y + (cenv->graph.c.x * z.x + \
							cenv->graph.c.y * z.y) / (z.x * z.x + z.y * z.y);
		z.y = 2 * z.y * z.x + (cenv->graph.c.y * z.x - \
							cenv->graph.c.x * z.y) / (z.x * z.x + z.y * z.y);
		z.x = tmp;
		++i;
	}
	if (i < cenv->graph.max_iter)
		i += 1 - (log((log(z.x * z.x + z.y * z.y) / 2) / log(2)) / log(2));
	image_pixel_put(&cenv->img, x, y, get_color(&cenv->graph, i));
}
