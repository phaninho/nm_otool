/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 20:05:55 by stmartin          #+#    #+#             */
/*   Updated: 2015/12/13 23:03:03 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	intsize;
	char	*nb;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	intsize = ft_intsize(n);
	if (!(nb = (char*)malloc(sizeof(char) * (intsize + 1))))
		return (NULL);
	nb[intsize] = '\0';
	if (n < 0)
	{
		nb[intsize - 1] = '-';
		n = -n;
	}
	while (i < intsize)
	{
		nb[i++] = n % 10 + '0';
		n = n / 10;
		if (nb[i] == '-')
			i++;
	}
	ft_strrev(nb);
	return (nb);
}
