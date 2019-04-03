/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:19:14 by brichard          #+#    #+#             */
/*   Updated: 2019/04/03 19:34:15 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(int iter_num, int iter_max)
{
	(void)iter_max;
	if (iter_num % 5 == 0)
		return (0x090C9B);
	else if (iter_num % 5 == 1)
		return (0x3D52D5);
	else if (iter_num % 5 == 2)
		return (0x86A5D9);
	else if (iter_num % 5 == 3)
		return (0xF4A83D);
	else
		return (0xFFD447);
}
