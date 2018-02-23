/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:52:32 by rabougue          #+#    #+#             */
/*   Updated: 2018/02/23 18:40:30 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*bb;
	size_t	i;

	c = (unsigned char)c;
	bb = (char *)b;
	i = 0;
	while (i < len)
	{
		bb[i] = c;
		i++;
	}
	return (bb);
}
