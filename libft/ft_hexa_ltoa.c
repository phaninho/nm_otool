/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_ltoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:55:51 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/07 16:55:52 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static	int	switch_hexa(int x, int up)
{
	if (0 <= x && x <= 9)
		return (48 + x);
	if (x >= 10 && x <= 15)
	{
		x = x - 10;
		if (up == 0)
			return ('a' + x);
		else if (up == 1)
			return ('A' + x);
	}
	return (0);
}

char		*ft_hexa_ltoa(unsigned long long n, int up)
{
	char				*str;
	int					size;
	unsigned long long	x;

	x = n;
	size = 0;
	while (x >= 16)
	{
		x /= 16;
		size++;
	}
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str)
	{
		str[size + 1] = '\0';
		while (size >= 0)
		{
			x = n % 16;
			str[size] = switch_hexa(x, up);
			n /= 16;
			size--;
		}
	}
	return (str);
}
