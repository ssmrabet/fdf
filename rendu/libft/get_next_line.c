/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrabet <smrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 00:33:12 by smrabet           #+#    #+#             */
/*   Updated: 2016/06/04 10:45:24 by smrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			leak_join(t_list *list, char *buf, int len)
{
	char			*str;

	str = list->content;
	list->content = ft_strnjoin(list->content, buf, len);
	free(str);
}

static void			leak_dup(t_list *list, int len)
{
	char			*str;

	str = list->content;
	list->content = ft_strdup(list->content + len);
	free(str);
}

static t_list		*fd_list(t_list **list, int fd)
{
	t_list			*tmp;

	tmp = *list;
	while (tmp)
	{
		if (fd == (int)tmp->content_size)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", fd);
	tmp->next = *list;
	*list = tmp;
	return (tmp);
}

static int			line_linked(char *str, char **line)
{
	int				i;

	i = 0;
	if (ft_strchr(str, '\n'))
	{
		while (str[i] && str[i] != '\n')
			i++;
	}
	else
		i = ft_strlen(str);
	*line = ft_strndup(str, i);
	if (str[i] == '\n')
		return (++i);
	return (i);
}

int					get_next_line(int const fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_list	*list = NULL;
	t_list			*tmp;
	int				ret;
	int				r;

	if (fd < 0 || line == NULL || read(fd, buf, 0))
		return (-1);
	tmp = list;
	list = fd_list(&tmp, fd);
	while (!ft_strchr(list->content, '\n') && (ret = read(fd, buf, BUFF_SIZE)))
		leak_join(list, buf, ret);
	r = line_linked((char*)list->content, line);
	leak_dup(list, r);
	list = tmp;
	if (r > 0)
		return (1);
	else
		return (0);
}
