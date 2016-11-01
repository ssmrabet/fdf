/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrabet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 15:48:30 by smrabet           #+#    #+#             */
/*   Updated: 2016/10/24 16:27:56 by smrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define Y 1000
# define X 1000
# define ESC 53
# define TYPE 83
# define COLOR 84
# define RESET 85
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define PLUS 69
# define MOIN 78
# define DEEP_PLUS 92
# define DEEP_MOIN 88

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	struct s_point	*next;
}					t_point;

typedef struct		s_env
{
	t_point			*map;
	void			*mlx;
	void			*win;
	void			*img;
	char			*data_img;
	int				bpp;
	int				img_line;
	int				end;
	int				nb_line;
	int				nb_col;
	int				zoom;
	int				deep;
	int				type;
	int				color;
	int				xstart;
	int				ystart;
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				e1;
	int				e2;
}					t_env;

t_point				*parallel_point(t_point *p, t_env *e);
void				ft_error(const char *str);
void				init(t_env *e);
void				get_map(char *file, t_env *e);
void				add_point(int j, int i, int k, t_env *e);
void				put_map(t_env *e);
void				put_final_img(t_env *e);
int					key_hook(int key, t_env *e);

#endif
