/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_2d_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:55:36 by stmartin          #+#    #+#             */
/*   Updated: 2016/10/07 16:55:38 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_count_2d_tab(char **tab)
{
	int		k;
	int		j;
	size_t	len;

	k = 0;
	j = 0;
	while (tab[k])
	{
		j++;
		if (tab[k][j])
		{
			len = ft_strlen(tab[k]);
			k++;
			j = 0;
			ft_putnbr(len);
			ft_putchar('\n');
		}
	}
}
