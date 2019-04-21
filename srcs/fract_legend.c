/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_legend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 11:33:27 by brichard          #+#    #+#             */
/*   Updated: 2019/04/21 11:31:03 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fract_legend(t_mlx *env)
{
	mlx_string_put(env->mlx_ptr, env->win_ptr, 0, 0, WHITE, CONTROLS);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 0, 15, WHITE, S_CHANGE_C);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 0, 30, WHITE, S_CHANGE_FR);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 0, 45, WHITE, S_CHANGE_FO);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 0, 60, WHITE, S_ZOOM);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 0, 75, WHITE, S_CENTER_V);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 0, 90, WHITE, S_RESET_V);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 0, 105, WHITE, S_EXIT);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 0, 120, WHITE, S_ENDLINE);
}
