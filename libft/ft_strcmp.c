/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:04:30 by stmartin          #+#    #+#             */
/*   Updated: 2015/12/12 23:16:04 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	char	*cps1;
	char	*cps2;

	cps1 = (char *)s1;
	cps2 = (char *)s2;
	while (*cps2 && (unsigned char)*cps1 == (unsigned char)*cps2)
	{
		cps1++;
		cps2++;
	}
	return ((unsigned char)*cps1 - (unsigned char)*cps2);
}
