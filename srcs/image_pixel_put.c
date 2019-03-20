/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_pixel_put.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:22:43 by brichard          #+#    #+#             */
/*   Updated: 2019/03/20 18:12:35 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		image_pixel_put(t_img *img, int x, int y, int colour)
{
	if (((x + y * W_WIDTH) > W_HEIGHT * W_WIDTH) \
			|| (x + y * W_WIDTH) < 0 || x < 0 || y < 0 \
			|| y >= W_HEIGHT || x >= W_WIDTH)
		return (0);
	img->data[x + y * W_WIDTH] = colour;
	return (1);
}
