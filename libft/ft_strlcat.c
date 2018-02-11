/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 08:23:29 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/09 19:17:19 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (len < size && *dst && *(dst++))
		len++;
	i = size - len;
	if (i < 1)
		return (len + ft_strlen((char *)src));
	while (*src)
	{
		if (i > 1)
		{
			*dst++ = *src;
			i--;
		}
		src++;
		len++;
	}
	*dst = '\0';
	return (len);
}
