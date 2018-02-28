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

char    define_symbol_type(char c, int addr_value, char *sct, char *seg)
{
  if ((c & N_TYPE) == N_UNDF)
  {
    c = 'u';
    if (addr_value != 0)
      c = 'c';
  }
  else if ((c & N_TYPE) == N_PBUD)
     c = 'u';
  else if ((c & N_TYPE) == N_ABS)
    c = 'a';
  else if ((c & N_TYPE) == N_SECT)
  {
    if (ft_strcmp(sct, SECT_TEXT) == 0 && ft_strcmp(seg, SEG_TEXT) == 0)
      c = 't';
    else if (ft_strcmp(sct, SECT_DATA) == 0 && ft_strcmp(seg, SEG_DATA) == 0)
      c = 'd';
    else if (ft_strcmp(sct, SECT_BSS) == 0 && ft_strcmp(seg, SEG_DATA) == 0)
      c = 'b';
    else
      c = 's';
  }
  else if ((c & N_TYPE) == N_INDR)
    c = 'i';
  else
    c = '?';
  return (c);
}

void  nm(void *ptr)
{
  int   magic_number;

  magic_number = *(int *)ptr;
  if (magic_number == (int)MH_MAGIC_64 || magic_number == (int)MH_CIGAM_64)
    handle_64(ptr);
  else
    ft_putendl("Not a 64 bit binary");
}

int	 read_args(char *av)
{
  int fd;
  char  *ptr;
  struct stat buff;

  if ((fd = open(av, O_RDONLY)) <= 0)
  {
    ft_putendl("Open error");
    return (1);
  }
  if (fstat(fd, &buff) < 0)
  {
    ft_putendl("fstat error");
    return (1);
  }
  if ((ptr = mmap(0, buff.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
  {
    ft_putendl("mmap error");
    return (1);
  }
  nm(ptr);
  if (munmap(ptr, buff.st_size) < 0)
  {
    ft_putendl("munmap error");
    return (1);
  }
  return (0);
}

int main(int ac, char **av)
{
  int i;

  i = 0;
  if (ac < 2)
  {
    ft_putendl("Nombre d'arguments insuffisant");
    return (1);
  }
  while (++i < ac)
  {
    if (ac > 2)
      ft_printf("\n%s:\n", av[i]);
    read_args(av[i]);
  }
  return (0);
}
