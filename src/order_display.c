/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:12:10 by stmartin          #+#    #+#             */
/*   Updated: 2018/02/28 11:12:13 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/nm_otool.h"

int     is_in_alpha_order(char *str, char *cmp)
{
  int len_str;
  int len_cmp;
  int i;

  i = 0;
  len_str = ft_strlen(str);
  len_cmp = ft_strlen(cmp);
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

void	  tab_alpha_order(int *order, struct nlist_64 *array, char *strtab, int last)
{
  int t = 0;
  char *str;
  char *cmp;

  cmp = NULL;
  while (t < last)
  {
    cmp = ft_strdup(strtab + array[last].n_un.n_strx);
    str = ft_strdup(strtab + array[order[t]].n_un.n_strx);
    if (!ft_strcmp(str, cmp))
    {
      cmp = ft_strdup(ft_lltoa(array[last].n_value, 16));
      str = ft_strdup(ft_lltoa(array[order[t]].n_value, 16));
    }
    if (is_in_alpha_order(str, cmp))
    {
      ft_swap(&order[t], &order[last]);
      cmp = ft_strdup(strtab + array[order[last]].n_un.n_strx);
    }
    t++;
  }
  if (cmp)
    free(cmp);
  if (str)
    free(str);
}
