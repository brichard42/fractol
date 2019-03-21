/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:21:54 by brichard          #+#    #+#             */
/*   Updated: 2019/03/21 15:15:42 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_init_keytab(t_keyfunc *tab, int size)
{
	while (--size >= 0)
		tab[size] = NULL;
}

void		ft_init_env(t_mlx *env)
{
	int		bpp;
	int		endian;
	int		size_l;

	if (!(env->mlx_ptr = mlx_init()))
		exit(2);
	if (!(env->win_ptr = mlx_new_window(env->mlx_ptr, W_WIDTH,
											W_HEIGHT, "Fract'ol")))
		exit(3);
	if (!(env->img.img_ptr = mlx_new_image(env->mlx_ptr, W_WIDTH, W_HEIGHT)))
		exit(4);
	if (!(env->img.data = (int *)mlx_get_data_addr(env->img.img_ptr, \
													&bpp, &size_l, &endian)))
		exit(5);
	ft_init_keytab(env->key_tab, KEY_TAB);
}
