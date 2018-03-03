#include "nm_otool.h"

int   get_arch_len(char *file_info)
{
  return (ft_atoi(ft_strchr(file_info, '/') + 1));
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
  tmp->next = new;
  return (lst);
}

void  display_archive(t_arlst *lst, void *ptr, char *av)
{
    t_arlst *tmp;
    struct ar_hdr *ar;
    int nmsize;

    tmp = lst;
    while (tmp)
    {
      ar = (void *)ptr + tmp->off;
      nmsize = get_arch_len(ar->ar_name);
      nm((void*)ar + sizeof(*ar) + nmsize, av);
      tmp = tmp->next;
    }
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
  offset = ptr + sizeof(struct ar_hdr) + len + SARMAG;
  ran = (void*)ptr + sizeof(struct ar_hdr) + SARMAG + len + sizeof(uint32_t);
	size = (*((int *)offset)) / sizeof(ran);
  // ft_printf("et len = %d\n", size);
  len = -1;
	while (++len < size)
		lst = build_lst(ran[len].ran_off, ran[len].ran_un.ran_strx, lst);
  display_archive(lst, ptr, av);
  return (0);
}
