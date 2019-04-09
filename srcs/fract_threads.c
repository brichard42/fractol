/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:04:58 by brichard          #+#    #+#             */
/*   Updated: 2019/04/09 16:53:06 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fract_threads(t_mlx *env)
{
	pthread_t	id[NTHREADS];
	int			i;

	i = 0;
	while (i < NTHREADS)
		pthread_create(&id[i++], NULL, set_limits, (void *)env);
	i = 0;
	while (i < NTHREADS)
		pthread_join(id[i++], NULL);
}

void	*set_limits(void *env)
{
	static int  i = 0;
	int         lims[2];
	t_mlx   *f;

	f = (t_mlx *)env;
	if (i >= NTHREADS)
	    i = 0;
	lims[0] = (W_WIDTH / NTHREADS) * i;
	lims[1] = (W_WIDTH / NTHREADS) * ++i;
	fract_series(f, lims[0], lims[1]);
	return (NULL);
}
