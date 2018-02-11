/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:39:52 by stmartin          #+#    #+#             */
/*   Updated: 2015/12/14 20:54:05 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_intsize(int nb)
{
	size_t	intsize;

	if (nb == 0)
		return (1);
	intsize = 0;
	if (nb < 0)
	{
		intsize++;
		nb = -nb;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		intsize++;
	}
	return (intsize);
}
