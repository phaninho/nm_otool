/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 10:06:50 by stmartin          #+#    #+#             */
/*   Updated: 2018/02/28 11:21:04 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char		*ft_lltoa(long long val, int base)
{
	char	buf[64];
	int		i;
	int		sign;

	i = 62;
	sign = (val < 0);
	if (sign)
		val = -val;
	if (val == 0)
		return ("0");
	while (val && i)
	{
		buf[i] = "0123456789abcdef"[val % base];
		i--;
		val /= base;
	}
	if (sign)
		buf[i--] = '-';
	return (ft_strdup(&buf[i + 1]));
}
