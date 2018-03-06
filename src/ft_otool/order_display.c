/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:12:10 by stmartin          #+#    #+#             */
/*   Updated: 2018/03/04 00:48:56 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

t_arlst		*offset_ascending_order(t_arlst *lst)
{
	t_arlst		*tmp;
	uint32_t	off;
	int			stop;

	tmp = lst;
	stop = 1;
	while (tmp && stop)
	{
		stop = 0;
		tmp = lst;
		while (tmp->next)
		{
			if (tmp->off > tmp->next->off)
			{
				stop = 1;
				off = tmp->off;
				tmp->off = tmp->next->off;
				tmp->next->off = off;
			}
			tmp = tmp->next;
		}
	}
	return (lst);
}
