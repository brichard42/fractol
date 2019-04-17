/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:39:20 by brichard          #+#    #+#             */
/*   Updated: 2019/04/17 16:43:39 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mandelbrot(void *env, int x, int y)
{
	int		i;
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
	while (i < cenv->graph.max_iter && z.x * z.x + z.y * z.y < 4)
	{
		tmp = z.x;
		z.x = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * z.y * tmp + c.y;
		++i;
	}
	if (i < cenv->graph.max_iter)
		image_pixel_put(&cenv->img, x, y, get_color(i, cenv->graph.max_iter));
	else
		image_pixel_put(&cenv->img, x, y, 0);
}
