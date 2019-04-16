/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:39:20 by brichard          #+#    #+#             */
/*   Updated: 2019/04/16 14:11:17 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mandelbrot(void *env, int x, int y)
{
	int		i;
	double	tmp;
	t_point	c;
	t_point	z;

	c.x = (double)(x * ((t_mlx*)env)->graph.scale.x + \
												((t_mlx*)env)->graph.re.min);
	c.y = (double)(y * ((t_mlx*)env)->graph.scale.y + \
												((t_mlx*)env)->graph.im.min);
	z.x = 0.0;
	z.y = 0.0;
	i = 0;
	while (i <= ((t_mlx*)env)->graph.max_iter && z.x * z.x + z.y * z.y < 4)
	{
		tmp = z.x;
		z.x = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * z.y * tmp + c.y;
		++i;
	}
	if (i <= ((t_mlx*)env)->graph.max_iter)
		image_pixel_put(&((t_mlx*)env)->img, x, y, get_color(i));
	else
		image_pixel_put(&((t_mlx*)env)->img, x, y, 0);
}
