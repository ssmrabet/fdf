/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrabet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 18:46:44 by smrabet           #+#    #+#             */
/*   Updated: 2016/10/24 16:26:48 by smrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static t_point		projection(t_point *p, t_env *e)
{
	t_point			p1;

	if (e->type == 1)
	{
		p1.x = e->xstart + ((p->x * e->zoom) + 1 * (p->y * e->zoom));
		p1.y = e->ystart -
			((p->z * e->zoom / e->deep) - 1 * (p->y * e->zoom));
	}
	else if (e->type == 2)
	{
		p1.x = e->xstart + (150 + (p->x * e->zoom - 150)
				* pow(0.994, (p->y * e->zoom)));
		p1.y = e->ystart - (150 - (p->y * e->zoom + 150)
				* pow(0.994, (p->z * e->zoom / e->deep)));
	}
	else
	{
		p1.x = e->xstart +
			((sqrt(2) / 2) * ((p->x * e->zoom) - (p->y * e->zoom)));
		p1.y = e->ystart - ((sqrt(2 / 2) * (p->z * e->zoom / e->deep))
				- ((1 / sqrt(6)) * (e->zoom * (p->x + p->y))));
	}
	return (p1);
}

static void			trace_pixel(int x, int y, t_env *e)
{
	int				t;
	int				*i;

	if (y < Y && x < X && x > 0 && y > 0)
	{
		t = x * 4 + y * e->img_line;
		i = (int *)&e->data_img[t];
		*i = 0xFFFFFF + 10000000 / e->color;
	}
}

static void			line(t_env *e, t_point p1, t_point p2)
{
	e->dx = abs(p2.x - p1.x);
	e->dy = abs(p2.y - p1.y);
	e->sx = p1.x < p2.x ? 1 : -1;
	e->sy = p1.y < p2.y ? 1 : -1;
	e->e1 = (e->dx > e->dy ? e->dx : -e->dy) / 2;
	while (!(p1.x == p2.x && p1.y == p2.y))
	{
		trace_pixel(p1.x, p1.y, e);
		e->e2 = e->e1;
		if (e->e2 > -e->dx)
		{
			e->e1 -= e->dy;
			p1.x += e->sx;
		}
		if (e->e2 < e->dy)
		{
			e->e1 += e->dx;
			p1.y += e->sy;
		}
	}
}

void				put_map(t_env *e)
{
	t_point			*tmp;
	int				i;

	i = 0;
	tmp = e->map;
	while (tmp->next)
	{
		if ((tmp->x % e->nb_col) != 0)
			line(e, projection(tmp, e), projection(tmp->next, e));
		if (i < (e->nb_col * (e->nb_line - 1)))
			line(e, projection(tmp, e),
			projection(parallel_point(tmp, e), e));
		tmp = tmp->next;
		i++;
	}
}
