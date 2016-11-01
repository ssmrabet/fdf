/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrabet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 15:48:08 by smrabet           #+#    #+#             */
/*   Updated: 2016/10/24 16:00:56 by smrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void		free_var(char **var)
{
	int			i;

	i = -1;
	while (var[++i])
		free(var[i]);
	free(var);
}

static void		check_content(char *str, t_env *e)
{
	int			i;
	char		**var;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) != 1 && str[i] != ' ')
			ft_error("Is not digit.\n");
		i++;
	}
	var = ft_strsplit(str, ' ');
	i = -1;
	while (var[++i])
		add_point(i, e->nb_line, ft_atoi(var[i]), e);
	if (e->nb_line == 0)
		e->nb_col = i;
	if (i != e->nb_col)
		ft_error("Wrong number of columns.\n");
	free_var(var);
}

void			get_map(char *file, t_env *e)
{
	int			j;
	int			fd;
	char		*line;

	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error("Failed to open file.\n");
	while (get_next_line(fd, &line) > 0)
	{
		check_content(line, e);
		free(line);
		e->nb_line++;
	}
	if (e->nb_line == 0 && e->nb_col == 0)
		ft_error("Empty file\n");
	((close(fd)) == -1) ? ft_error("Failed to close file.\n") : 0;
}
