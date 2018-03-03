#include "nm_otool.h"

int   get_arch_len(char *file_info)
{
  return (ft_atoi(ft_strchr(file_info, '/') + 1));
}

int			remove_lst_doubl(t_arlst *lst, uint32_t off)
{
	t_arlst	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->off == off)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}


t_arlst  *build_lst(uint32_t off, uint32_t strx, t_arlst *lst)
{
  t_arlst  *new;
  t_arlst  *tmp;

  new = (t_arlst *)malloc(sizeof(t_arlst));
  new->off = off;
  new->strx = strx;
  new->next = NULL;
  if (!lst)
    return (new);
  tmp = lst;
  while (tmp->next)
    tmp = tmp->next;
  if (remove_lst_doubl(lst, off))
    return (lst);
  tmp->next = new;
  return (lst);
}

void  display_archive(t_arlst *lst, void *ptr, char *av)
{
    t_arlst *tmp;
    struct ar_hdr *ar;
    int nmsize;
    char *name;

    tmp = lst;
    while (tmp)
    {
      ar = (void *)ptr + tmp->off;
      nmsize = get_arch_len(ar->ar_name);
      name = ft_strstr(ar->ar_name, ARFMAG) + ft_strlen(ARFMAG);
      ft_printf("\n%s(%s):\n",  av, name);
      nm((void*)ar + sizeof(*ar) + nmsize, av);
      tmp = tmp->next;
    }
}

t_arlst			*offset_ascending_order(t_arlst *lst)
{
	t_arlst	*tmp;
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

int   handle_archive(void *ptr, char *av)
{
  int len;
  int size;
  char  *offset;
  struct ranlib *ran;
  t_arlst *lst;

  lst = NULL;
  len = get_arch_len((char *)ptr);
  offset = (void *)ptr + sizeof(struct ar_hdr) + len + SARMAG;
  ran = (void *)ptr + sizeof(struct ar_hdr) + SARMAG + len + sizeof(uint32_t);
	size = (*((int *)offset)) / sizeof(struct ranlib);
  len = -1;
	while (++len < size)
		lst = build_lst(ran[len].ran_off, ran[len].ran_un.ran_strx, lst);
  display_archive(offset_ascending_order(lst), ptr, av);
  return (0);
}
