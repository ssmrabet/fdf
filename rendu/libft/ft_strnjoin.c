/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrabet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 17:28:11 by smrabet           #+#    #+#             */
/*   Updated: 2016/05/07 17:36:10 by smrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t len)
{
	char	*ret;

	ret = NULL;
	if (s1 && s2)
	{
		if ((ret = (char*)malloc(sizeof(char)
		* ft_strlen(s1) + len + 1)) == NULL)
			return (NULL);
		ft_strcpy(ret, s1);
		ft_strncat(ret, s2, len);
	}
	return (ret);
}
