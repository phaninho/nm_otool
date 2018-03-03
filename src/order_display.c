/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:12:10 by stmartin          #+#    #+#             */
/*   Updated: 2018/03/03 19:40:51 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm_otool.h"

char    *complete_addr(char *str)
{
  char *addr;
  int len;
  int i;
  int j;

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

int     is_in_alpha_order(char *str, char *cmp, int check_addr)
{
  int len_str;
  int len_cmp;
  int i;
  int j;

  i = 0;
  j = 0;
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

void	  tab_alpha_order32(int *order, struct nlist *array, char *strtab, int last)
{
  int t;
  char *str;
  char *cmp;
  int check_addr;

  t = -1;
  cmp = NULL;
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
    {
      ft_swap(&order[t], &order[last]);
      // cmp = ft_strdup(strtab + array[order[last]].n_un.n_strx);
    }
  }
  if (cmp)
    free(cmp);
  if (str)
    free(str);
}

void	  tab_alpha_order64(int *order, struct nlist_64 *array, char *strtab, int last)
{
  int t;
  char *str;
  char *cmp;
  int check_addr;

  t = -1;
  cmp = NULL;
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
      // if (!ft_strcmp(cmp, "120"))
      // ft_printf("\n\n\n\n\n\n\n%s %s\n\n\n\n\n\n\n\n\n\n", cmp, str);
    }
    if (is_in_alpha_order(str, cmp, check_addr))
    {
      // ft_printf("t=>%s last=>%s ", ft_lltoa(array[order[t]].n_value, 16), ft_lltoa(array[order[last]].n_value, 16));
      ft_swap(&order[t], &order[last]);
      // ft_printf("t=>%s last=>%s\n",ft_lltoa(array[order[t]].n_value, 16), ft_lltoa(array[order[last]].n_value, 16));
      // cmp = ft_strdup(strtab + array[order[last]].n_un.n_strx);
    }
  }
  if (cmp)
    free(cmp);
  if (str)
    free(str);
}
