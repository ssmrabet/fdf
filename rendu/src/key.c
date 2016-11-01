/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrabet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 10:53:15 by smrabet           #+#    #+#             */
/*   Updated: 2016/10/24 13:49:26 by smrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		key_hook(int key, t_env *e)
{
	e->ystart += (key == DOWN) ? 10 : 0;
	e->xstart += (key == RIGHT) ? 10 : 0;
	e->ystart -= (key == UP) ? 10 : 0;
	e->xstart -= (key == LEFT) ? 10 : 0;
	if (e->zoom < 100)
		e->zoom += (key == PLUS) ? 1 : 0;
	if (e->zoom > 1)
		e->zoom -= (key == MOIN) ? 1 : 0;
	if (e->deep < 100)
		e->deep += (key == DEEP_PLUS) ? 1 : 0;
	if (e->deep > 1)
		e->deep -= (key == DEEP_MOIN) ? 1 : 0;
	if (e->mode <= 2)
		e->mode += (key == MODE) ? 1 : 0;
	if (e->mode > 2)
		e->mode = (key == MODE) ? 0 : 0;
	(key == R) ? init(e) : 0;
	(key == ESC) ? exit(1) : 0;
	e->color += (key == COLOR) ? 1 : 0;
	put_final_img(e);
	return (0);
}
