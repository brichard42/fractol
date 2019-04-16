/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 11:48:42 by brichard          #+#    #+#             */
/*   Updated: 2019/04/16 17:03:51 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		julia(void *env, int x, int y)
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
		tmp = z.x;
		z.x = z.x * z.x - z.y * z.y + cenv->graph.c.x;
		z.y = 2 * z.y * tmp + cenv->graph.c.y;
		++i;
	}
	if (i < cenv->graph.max_iter)
		image_pixel_put(&cenv->img, x, y, get_color(i));
	else
		image_pixel_put(&cenv->img, x, y, 0);
}
