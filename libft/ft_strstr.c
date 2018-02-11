/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:07:49 by stmartin          #+#    #+#             */
/*   Updated: 2015/12/14 16:26:23 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	last;

	i = 0;
	j = 0;
	last = 0;
	if (*s2 == 0)
		return ((char *)s1);
	while (s1[i])
	{
		if (s1[i] == s2[j])
		{
			if (s2[j + 1] == '\0')
				return ((char*)&s1[i - j]);
			j++;
		}
		else
		{
			j = 0;
			i = last++;
		}
		i++;
	}
	return (NULL);
}
