/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_ttoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 23:35:22 by rabougue          #+#    #+#             */
/*   Updated: 2016/08/06 08:42:51 by rabougue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static void	incr(size_t *i, size_t *res)
{
	while (*res != 0)
	{
		*res = *res / 10;
		*i = *i + 1;
	}
}

size_t		ft_size_ttoa(size_t n)
{
	size_t			i;
	size_t			res;

	i = 0;
	res = n;
	if (res == 0)
		i = 1;
	incr(&i, &res);
	return (i);
}
