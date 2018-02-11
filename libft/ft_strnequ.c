/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:13:17 by stmartin          #+#    #+#             */
/*   Updated: 2015/12/18 19:00:52 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(const char *s1, const char *s2, size_t n)
{
	int		check;

	if ((!s2 || !*s2) && n == 0)
		return (1);
	if (!s1 || !s2)
		return (0);
	check = ft_strncmp(s1, s2, n);
	if (check == 0)
		return (1);
	return (0);
}
