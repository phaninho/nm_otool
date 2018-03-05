/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 05:35:23 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/06 08:43:17 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_len(long nb, int base)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= base;
		len++;
	}
	return (len);
}

static char		ft_char(long nb)
{
	if (nb < 10)
		return (nb + '0');
	return (nb + 'a' - 10);
}

char			*ft_itoa_base(int value, int base)
{
	long	nb;
	int		neg;
	char	*str;
	int		len;

	nb = value;
	neg = 0;
	if (nb < 0)
	{
		nb = -nb;
		neg = 1;
	}
	len = ft_len(nb, base) + neg;
	str = (char*)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	while (--len >= 0)
	{
		str[len] = ft_char(nb % base);
		nb /= base;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
//
// char			*ft_itoa_base_sub(int val, int base, int output_size)
// {
// 	char			buffer[output_size + 1];
// 	char			*p;
// 	unsigned int	unsigned_val;
//
// 	unsigned_val = (unsigned int)val;
// 	if (base > 36 || base < 2)
// 		return (NULL);
// 	buffer[output_size] = 0;
// 	p = buffer + output_size - 1;
// 	*p = '0';
// 	if (unsigned_val > 0)
// 	{
// 		while (unsigned_val > 0)
// 		{
// 			*p-- = "0123456789abcdef"[unsigned_val % base];
// 			unsigned_val = unsigned_val / base;
// 			if (p < buffer)
// 				break ;
// 		}
// 		p++;
// 	}
// 	while (p > buffer)
// 		*--p = '0';
// 	return (ft_strdup(p));
// }
