/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrabet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 16:54:45 by smrabet           #+#    #+#             */
/*   Updated: 2016/05/10 16:54:47 by smrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_exit(const char *message)
{
	if (message != NULL)
		ft_putendl_fd(message, 1);
	exit(1);
}
