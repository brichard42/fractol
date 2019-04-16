/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zubieta.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:19:54 by brichard          #+#    #+#             */
/*   Updated: 2019/04/16 17:14:02 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		zubieta(void *env, int x, int y)
{
	int		i;
	double	tmp;
	t_point	z;
	t_mlx	*cenv;

	cenv = (t_mlx*)env;
	z.x = (double)(x * cenv->graph.scale.x + cenv->graph.re.min);
	z.y = (double)(y * cenv->graph.scale.y + cenv->graph.im.min);
	i = 0;
	while (i < cenv->graph.max_iter && z.x * z.x + z.y * z.y < 4)
	{
		tmp = z.x * z.x - z.y * z.y + (cenv->graph.c.x * z.x + \
							cenv->graph.c.y * z.y) / (z.x * z.x + z.y * z.y);
		z.y = 2 * z.y * z.x + (cenv->graph.c.y * z.x - \
							cenv->graph.c.x * z.y) / (z.x * z.x + z.y * z.y);
		z.x = tmp;
		++i;
	}
	if (i < cenv->graph.max_iter)
		image_pixel_put(&cenv->img, x, y, get_color(i));
	else
		image_pixel_put(&cenv->img, x, y, 0);
}
