/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 11:48:42 by brichard          #+#    #+#             */
/*   Updated: 2019/04/15 11:48:55 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		julia(void *env, t_point scale, int x, int y)
{
	int		i;
	double	tmp;
	t_point	c;
	t_point	z;

	z.x = (double)(x * scale.x + ((t_mlx*)env)->graph.re.min);
	z.y = (double)(y * scale.y + ((t_mlx*)env)->graph.im.min);
	c.x = (double)(((t_mlx*)env)->graph.mouse.x * scale.x + ((t_mlx*)env)->graph.re.min);
	c.y = (double)(((t_mlx*)env)->graph.mouse.y * scale.y + ((t_mlx*)env)->graph.im.min);
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
