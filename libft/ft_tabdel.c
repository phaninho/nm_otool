/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 09:33:20 by stmartin          #+#    #+#             */
/*   Updated: 2018/02/28 10:11:56 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void		ft_tabdel(char ***tab)
{
	int		i;

	i = 0;
	if (!tab)
		return ;
	while (*tab && (*tab)[i])
	{
		if ((*tab)[i])
			free((*tab)[i]);
		(*tab)[i] = NULL;
		i++;
	}
	if (*tab)
		free(*tab);
	*tab = NULL;
}
