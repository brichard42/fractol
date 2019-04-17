/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:19:14 by brichard          #+#    #+#             */
/*   Updated: 2019/04/17 11:51:31 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(int iter_num)
{
	if (iter_num % 5 == 0)
		return (BLUE_1);
	else if (iter_num % 5 == 1)
		return (BLUE_2);
	else if (iter_num % 5 == 2)
		return (BLUE_3);
	else if (iter_num % 5 == 3)
		return (BLUE_4);
	else
		return (ORANGE);
}
