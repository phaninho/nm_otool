/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 08:12:56 by stmartin          #+#    #+#             */
/*   Updated: 2015/12/15 15:55:47 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*cpyd;
	char	*cpys;

	cpys = (char *)src;
	cpyd = (char *)dst;
	i = 0;
	if (src > dst)
		return (ft_memcpy(dst, src, len));
	cpys = cpys + len;
	cpyd = cpyd + len;
	while (i < len)
	{
		*--cpyd = *--cpys;
		i++;
	}
	return (dst);
}
