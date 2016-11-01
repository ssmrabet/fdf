/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrabet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 15:47:54 by smrabet           #+#    #+#             */
/*   Updated: 2016/10/24 16:28:22 by smrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void			ft_error(const char *str)
{
	ft_putstr_fd(str, 2);
	exit(-1);
}

void			init(t_env *e)
{
	e->color = 10;
	e->zoom = 30;
	e->deep = 15;
	e->xstart = X / 2;
	e->ystart = Y / 3;
	e->type = 0;
}

void			put_final_img(t_env *e)
{
	e->img = mlx_new_image(e->mlx, X, Y);
	e->data_img = mlx_get_data_addr(e->img, &(e->bpp),
			&(e->img_line), &(e->end));
	put_map(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->data_img);
}

int				key_hook(int key, t_env *e)
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
	if (e->type <= 2)
		e->type += (key == TYPE) ? 1 : 0;
	if (e->type > 2)
		e->type = (key == TYPE) ? 0 : 0;
	if (e->color <= 200)
		e->color += (key == COLOR) ? 30 : 0;
	if (e->color > 200)
		e->color = (key == COLOR) ? 10 : 0;
	(key == RESET) ? init(e) : 0;
	(key == ESC) ? exit(1) : 0;
	put_final_img(e);
	return (0);
}

int				main(int ac, char **av)
{
	t_env		e;

	if (ac != 2)
		ft_error("error: Wrong number of argument.\n");
	else
	{
		init(&e);
		e.nb_line = 0;
		e.nb_line = 0;
		e.map = NULL;
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, X, Y, "FDF");
		get_map(av[1], &e);
		put_final_img(&e);
		mlx_hook(e.win, 2, 3, key_hook, &e);
		mlx_loop(e.mlx);
	}
}
