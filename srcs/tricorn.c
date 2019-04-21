/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 12:01:40 by brichard          #+#    #+#             */
/*   Updated: 2019/04/21 12:14:24 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		tricorn(void *env, int x, int y)
{
	double	i;
	double	tmp;
	t_point	c;
	t_point	z;
	t_mlx	*cenv;

	cenv = (t_mlx*)env;
	c.x = (double)(x * cenv->graph.scale.x + cenv->graph.re.min);
	c.y = (double)(y * cenv->graph.scale.y + cenv->graph.im.min);
	z.x = 0.0;
	z.y = 0.0;
	i = 0;
	while (z.x * z.x + z.y * z.y < (1 << 16) && (int)i < cenv->graph.max_iter)
	{
		tmp = z.x * z.x - z.y * z.y + c.x;
		z.y = -2 * z.y * z.x + c.y;
		z.x = tmp;
		++i;
	}
	if (i < cenv->graph.max_iter)
		i += 1.0 - (log((log(z.x * z.x + z.y * z.y) / 2) / log(2)) / log(2));
	image_pixel_put(&cenv->img, x, y, get_color(&cenv->graph, i));
}
