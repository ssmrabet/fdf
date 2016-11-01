/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrabet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 11:39:11 by smrabet           #+#    #+#             */
/*   Updated: 2016/10/24 16:01:59 by smrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void			put_on_map(t_point **map, t_point *p)
{
	if (!(*map))
		*map = p;
	else
	{
		p->next = *map;
		*map = p;
	}
}

void				add_point(int j, int i, int k, t_env *e)
{
	t_point			*p;

	p = NULL;
	if (!(p = (t_point *)malloc(sizeof(t_point))))
		exit(2);
	p->x = j;
	p->y = i;
	p->z = k;
	p->next = NULL;
	put_on_map(&(e->map), p);
}

t_point				*parallel_point(t_point *p, t_env *e)
{
	int				i;
	t_point			*tmp;

	tmp = p;
	i = -1;
	while (++i < e->nb_col)
		tmp = tmp->next;
	return (tmp);
}
