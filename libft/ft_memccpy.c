/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 08:29:40 by stmartin          #+#    #+#             */
/*   Updated: 2015/12/13 23:05:57 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*cpdst;
	unsigned char	*cpsrc;

	i = 0;
	cpdst = (unsigned char*)dst;
	cpsrc = (unsigned char*)src;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		*cpdst = *cpsrc;
		if (*cpdst == (unsigned char)c)
			return (cpdst + 1);
		i++;
		cpdst++;
		cpsrc++;
	}
	return (NULL);
}
