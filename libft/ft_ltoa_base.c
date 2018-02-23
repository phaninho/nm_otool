/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 03:53:41 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/06 08:51:08 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

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

char			*ft_ltoa_base(long value, int base)
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
