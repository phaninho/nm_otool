/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:06:15 by stmartin          #+#    #+#             */
/*   Updated: 2015/12/13 00:06:00 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		check;

	if (!s1 || !s2)
		return (0);
	check = ft_strcmp(s1, s2);
	if (check == 0)
		return (1);
	return (0);
}
