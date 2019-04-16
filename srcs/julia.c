/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 11:48:42 by brichard          #+#    #+#             */
/*   Updated: 2019/04/16 14:11:42 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		julia(void *env, int x, int y)
{
	int		i;
	double	tmp;
	t_point	z;

	z.x = (double)(x * ((t_mlx*)env)->graph.scale.x + ((t_mlx*)env)->graph.re.min);
	z.y = (double)(y * ((t_mlx*)env)->graph.scale.y + ((t_mlx*)env)->graph.im.min);
	i = 0;
	while (i <= ((t_mlx*)env)->graph.max_iter && z.x * z.x + z.y * z.y < 4)
	{
		tmp = z.x;
		z.x = z.x * z.x - z.y * z.y + ((t_mlx*)env)->graph.c.x;
		z.y = 2 * z.y * tmp + ((t_mlx*)env)->graph.c.y;
		++i;
	}
	if (i <= ((t_mlx*)env)->graph.max_iter)
		image_pixel_put(&((t_mlx*)env)->img, x, y, get_color(i));
	else
		image_pixel_put(&((t_mlx*)env)->img, x, y, 0);
}
