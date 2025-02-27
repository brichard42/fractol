/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:21:54 by brichard          #+#    #+#             */
/*   Updated: 2019/05/01 13:24:04 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	make_color_tab(t_graph *graph)
{
	graph->color_tab[0][0] = BLACK;
	graph->color_tab[0][1] = BLACK_BEAN;
	graph->color_tab[0][2] = MAROON;
	graph->color_tab[0][3] = BOSTONU_RED;
	graph->color_tab[0][4] = RED;
	graph->color_tab[1][0] = DARK_OLD_GOLD;
	graph->color_tab[1][1] = METALLIC_SUNBURST;
	graph->color_tab[1][2] = DARK_KHAKI;
	graph->color_tab[1][3] = OLD_GOLD;
	graph->color_tab[1][4] = GOLD;
	graph->color_tab[2][0] = BRICK_RED;
	graph->color_tab[2][1] = LIGHT_CARMINE_PINK;
	graph->color_tab[2][2] = PASTEL_ORANGE;
	graph->color_tab[2][3] = MAXIMUM_BLUE;
	graph->color_tab[2][4] = BOTTLE_GREEN;
	graph->color_tab[3][0] = LUST;
	graph->color_tab[3][1] = VIVID_GAMBOGE;
	graph->color_tab[3][2] = COPPER_RED;
	graph->color_tab[3][3] = LIVER;
	graph->color_tab[3][4] = ZINNWALDITE_BROWN;
	graph->color_tab[4][0] = PALE_ROBIN_EGG_BLUE;
	graph->color_tab[4][1] = TURKISH_ROSE;
	graph->color_tab[4][2] = VIVID_TANGERINE;
	graph->color_tab[4][3] = FLAVESCENT;
	graph->color_tab[4][4] = PALE_GOLDENROD;
}

void		init_graph(t_graph *graph)
{
	graph->pal_num = 4;
	make_color_tab(graph);
	graph->max_iter = 51;
	if (graph->type == 0)
		init_mandelbrot(graph);
	else if (graph->type == 1)
		init_julia(graph);
	else if (graph->type == 2)
		init_zubieta(graph);
	else if (graph->type == 3)
		init_tricorn(graph);
	else if (graph->type == 4)
		init_ship(graph);
	else if (graph->type == 5)
		init_reverse_mandelbrot(graph);
	else if (graph->type == 6)
		init_myfrac_1(graph);
	else if (graph->type == 7)
		init_myfrac_2(graph);
	graph->scale.x = (graph->re.max - graph->re.min) / W_WIDTH;
	graph->scale.y = (graph->im.max - graph->im.min) / W_HEIGHT;
}

void		ft_init_env(t_mlx *env)
{
	int		bpp;
	int		endian;
	int		size_l;

	if (!(env->mlx_ptr = mlx_init()))
		exit(2);
	if (!(env->win_ptr = mlx_new_window(env->mlx_ptr, W_WIDTH, \
											W_HEIGHT, "Fract'ol")))
		exit(3);
	if (!(env->img.img_ptr = mlx_new_image(env->mlx_ptr, W_WIDTH, W_HEIGHT)))
		exit(4);
	if (!(env->img.data = (int *)mlx_get_data_addr(env->img.img_ptr, \
													&bpp, &size_l, &endian)))
		exit(5);
	ft_init_keytab(env->key_tab, KEY_TAB);
	ft_init_moutab(env->mou_tab, MOU_TAB);
	ft_init_fracttab(env->fract_tab, FRACT_TAB);
}
