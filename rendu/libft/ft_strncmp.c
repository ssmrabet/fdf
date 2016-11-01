/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrabet <smrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 00:39:23 by smrabet           #+#    #+#             */
/*   Updated: 2016/04/25 13:21:49 by smrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && (i < n))
	{
		if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return (-1);
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return (1);
		i++;
	}
	if (i < n && s1[i])
		return (1);
	else if (i < n && s2[i])
		return (-1);
	else
		return (0);
}
