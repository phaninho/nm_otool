/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:55:20 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/09 19:16:57 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fk_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	size_t	len;
	char	*str;

	if (!s)
		return (NULL);
	while (*s && fk_isspace((int)*s) == 1)
		s++;
	if (!(len = ft_strlen(s)))
		return (ft_strdup(s));
	while (fk_isspace((int)s[len - 1]) == 1)
		len--;
	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	str = ft_strsub(s, 0, len);
	return (str);
}
