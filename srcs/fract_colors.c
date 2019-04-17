/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:19:14 by brichard          #+#    #+#             */
/*   Updated: 2019/04/17 18:34:54 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(int iter_num, int iter_max)
{
	int	color_tab[5];

	(void)iter_max;
/*	
	color_tab[0] = BLACK;
	color_tab[1] = BLACK_BEAN;
	color_tab[2] = MAROON;
	color_tab[3] = BOSTONU_RED;
	color_tab[4] = RED;
	*/
	
	color_tab[0] = DARK_OLD_GOLD;
	color_tab[1] = METALLIC_SUNBURST;
	color_tab[2] = DARK_KHAKI;
	color_tab[3] = OLD_GOLD;
	color_tab[4] = GOLD;
	
	return (color_tab[(iter_num / 3) % 5]);
}
