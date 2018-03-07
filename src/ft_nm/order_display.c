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

char		*complete_addr(char *str)
{
	char		*addr;
	int			len;
	int			i;
	int			j;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	addr = (char *)malloc(sizeof(char) * (16 + 1));
	addr[16] = '\0';
	if (len < 16)
	{
		while (i + len < 16)
		{
			addr[i] = '0';
			i++;
		}
		while (i < 16)
		{
			addr[i] = str[j];
			i++;
			j++;
		}
	}
	return (addr);
}

int			is_in_alpha_order(char *str, char *cmp, int check_addr)
{
	int			len_str;
	int			len_cmp;
	int			i;

	i = 0;
	len_str = ft_strlen(str);
	len_cmp = ft_strlen(cmp);
	if (check_addr)
	{
		if (len_str < 16)
			str = complete_addr(str);
		if (len_cmp < 16)
			cmp = complete_addr(cmp);
	}
	while (i < len_str >= len_cmp ? len_cmp : len_str)
	{
		if (str[i] > cmp[i])
			return (1);
		else if (str[i] < cmp[i])
			return (0);
		i++;
	}
	return (0);
}

int			al_ord32(int *order, struct nlist *array, char *strtab, int last)
{
	int			t;
	char		*str;
	char		*cmp;
	int			check_addr;

	t = -1;
	cmp = NULL;
	if (check_bin_limit(strtab + array[last].n_un.n_strx) || check_bin_limit(strtab + array[order[t]].n_un.n_strx))
		return (ft_printf("CORRUPTION DETECTED, SWAT on the way\n"));
	while (++t < last)
	{
		check_addr = 0;
		cmp = ft_strdup(strtab + array[last].n_un.n_strx);
		str = ft_strdup(strtab + array[order[t]].n_un.n_strx);
		if (!ft_strcmp(str, cmp))
		{
			check_addr = 1;
			cmp = ft_strdup(ft_lltoa(array[last].n_value, 16));
			str = ft_strdup(ft_lltoa(array[order[t]].n_value, 16));
		}
		if (is_in_alpha_order(str, cmp, check_addr))
			ft_swap(&order[t], &order[last]);
	}
	if (cmp)
		free(cmp);
	if (str)
		free(str);
	return (0);
}

int			al_ord64(int *order, struct nlist_64 *array, char *strtab, int last)
{
	int			t;
	char		*str;
	char		*cmp;
	int			check_addr;

	t = -1;
	cmp = NULL;
	if (check_bin_limit(strtab + array[last].n_un.n_strx) || check_bin_limit(strtab + array[order[t]].n_un.n_strx))
		return (ft_printf("CORRUPTION DETECTED, SWAT on the way\n"));

	while (++t < last)
	{
		check_addr = 0;
		cmp = ft_strdup(strtab + array[last].n_un.n_strx);
		str = ft_strdup(strtab + array[order[t]].n_un.n_strx);
		if (!ft_strcmp(str, cmp))
		{
			check_addr = 1;
			cmp = ft_strdup(ft_lltoa(array[last].n_value, 16));
			str = ft_strdup(ft_lltoa(array[order[t]].n_value, 16));
		}
		if (is_in_alpha_order(str, cmp, check_addr))
			ft_swap(&order[t], &order[last]);
	}
	if (cmp)
		free(cmp);
	if (str)
		free(str);
	return (0);
}

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
