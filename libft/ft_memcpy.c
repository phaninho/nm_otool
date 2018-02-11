/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:57:38 by stmartin          #+#    #+#             */
/*   Updated: 2015/11/27 10:26:02 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*cpdst;
	char	*cpsrc;
	size_t	i;

	i = 0;
	cpdst = (char *)dst;
	cpsrc = (char *)src;
	while (i < n)
	{
		cpdst[i] = cpsrc[i];
		i++;
	}
	return (dst);
}
