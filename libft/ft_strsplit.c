/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 17:04:04 by stmartin          #+#    #+#             */
/*   Updated: 2015/12/13 23:12:37 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	size_t	n;
	size_t	word;

	i = 0;
	n = 0;
	word = ft_countword_btwsign(s, c);
	if (!(split = (char**)malloc(sizeof(char*) * (word + 1))))
		return (NULL);
	split[word] = NULL;
	while (n < word)
	{
		j = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			j++;
		}
		split[n++] = ft_strsub(s, (i - j), j);
	}
	return (split);
}
