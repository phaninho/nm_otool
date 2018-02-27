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
    // if (!ft_strcmp(cmp, "_is_in_alpha_order"))
      // printf("\n[%s][%s]\n", str,cmp);
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

// int     check_tab_doubl(char *str, char *strtab, struct nlist_64 *array, int *tab, int lim)
// {
//   int   i;
//
//   i = 0;
//   while (i < lim)
//   {
//     if (!ft_strcmp(str, strtab + array[tab[i]].n_un.n_strx))
//       return (1);
//     i++;
//   }
//   return (0);
// }

char  *ft_lltoa(long long val, int base)
{
    char buf[64];
    int i = 62;
    int sign = (val < 0);

    if (sign)
      val = -val;
    if(val == 0)
      return "0";
    while(val && i)
    {
      buf[i] = "0123456789abcdef"[val % base];
      i--;
      val /= base;
    }
    if(sign)
        buf[i--] = '-';
    return (ft_strdup(&buf[i + 1]));
}


void    print_output(t_env64 e, void *ptr)
{
  // int nsyms, int symoff, int stroff, void *ptr, char **sgname, char **sctname

  int i;
  int len;
  char *strtab;
  struct nlist_64 *array;
  char type[e.sym->nsyms];
  char *str;
  int  al_order[e.sym->nsyms];

  array = ptr + e.sym->symoff;
  strtab = ptr + e.sym->stroff;
  i =-1;
  while (++i < (int)e.sym->nsyms)
    al_order[i] = i;
  i = 0;
  while (i < (int)e.sym->nsyms)
  {
    type[i] = array[i].n_type;
    if ((type[i] & N_STAB))
      type[i] = '-';
    else
    {
      if ((type[i] & N_TYPE) == N_UNDF)
      {
        type[i] = 'u';
        if ((array[i].n_value) != 0)
          type[i] = 'c';
      }
      else if ((type[i] & N_TYPE) == N_PBUD)
         type[i] = 'u';
      else if ((type[i] & N_TYPE) == N_ABS)
        type[i] = 'a';
      else if ((type[i] & N_TYPE) == N_SECT)
      {
        if (ft_strcmp(e.sectname[(int)array[i].n_sect - 1], SECT_TEXT) == 0 && ft_strcmp(e.segname[(int)array[i].n_sect - 1], SEG_TEXT) == 0)
          type[i] = 't';
        else if (ft_strcmp(e.sectname[(int)array[i].n_sect - 1], SECT_DATA) == 0 && ft_strcmp(e.segname[(int)array[i].n_sect - 1], SEG_DATA) == 0)
          type[i] = 'd';
        else if (ft_strcmp(e.sectname[(int)array[i].n_sect - 1], SECT_BSS) == 0 && ft_strcmp(e.segname[(int)array[i].n_sect - 1], SEG_DATA) == 0)
          type[i] = 'b';
        else
          type[i] = 's';
      }
      else if ((type[i] & N_TYPE) == N_INDR)
        type[i] = 'i';
      else
        type[i] = '?';
    }

    if ((array[i].n_type & N_EXT) && type[i] != '?')
      type[i] = ft_toupper(type[i]);
    if (i > 0)
      tab_alpha_order(al_order, array, strtab, i);
    i++;
  }
  i = -1;
  while (++i < (int)e.sym->nsyms)
  {
    str = ft_strdup(strtab + array[al_order[i]].n_un.n_strx);
    while (i < (int)e.sym->nsyms  && (!ft_strcmp("", str) || str[0] == '/' || \
    (str[0] != '_'  && !(str[0] == 'G' && str[1] == 'C') && !(str[0] == 'd' && \
    str[1] == 'y') && !(str[0] == '-' && str[1] == '[') && !(str[0] == '+' && str[1] == '['))))
    {
      i++;
      if (i < (int)e.sym->nsyms)
        str = ft_strdup(strtab + array[al_order[i]].n_un.n_strx);
      else if (str)
        free(str);
    }
    if (i >= (int)e.sym->nsyms)
      break;
    if (array[al_order[i]].n_type != 36 && array[al_order[i]].n_type != 38 && array[al_order[i]].n_type != 32)
    {
      if ((array[al_order[i]].n_value))
      {
        if ((len = ft_strlen(ft_lltoa(array[al_order[i]].n_value, 16))) < 16)
        len = 16 - len;
        while (len-- > 0)
          ft_putchar('0');
        ft_printf("%s", ft_lltoa(array[al_order[i]].n_value, 16));
      }
      else
        ft_printf("                ");
      if (type[al_order[i]])
        ft_printf(" %c ", type[al_order[i]]);
      else
        ft_printf(" %d ", array[al_order[i]].n_type);
      ft_printf("%s\n",strtab + array[al_order[i]].n_un.n_strx);
    }
    if (str)
      free(str);
  }
}

t_env64   init_env64()
{
  t_env64 e;

  e.i = 0;
  e.j = 0;
  e.len = 0;
  e.segname = NULL;
  e.sectname = NULL;
  return (e);
}

void handle_64(void *ptr)
{
  t_env64 e;

  e = init_env64();
  e.header = (struct mach_header_64 *)ptr;
  e.lc = ptr + sizeof(struct mach_header_64);
  while (e.i++ < (int)e.header->ncmds)
  {
    if (e.lc->cmd == LC_SEGMENT_64)
    {

      e.sg64 = (struct segment_command_64 *)e.lc;
      e.sct64 = (struct section_64 *)((char *)e.sg64 + sizeof(struct segment_command_64));
      e.len = e.len == 0 ? e.sg64->nsects : (e.len + e.sg64->nsects);
      if (!e.segname && !e.sectname)
      {
        e.segname = (char **)malloc(sizeof(char *) * (e.len + 1));
        e.sectname = (char **)malloc(sizeof(char *) * (e.len + 1));
      }
      else if (e.len)
      {
        e.segname = (char **)realloc(e.segname, sizeof(char *) * (e.len + 1));
        e.sectname = (char **)realloc(e.sectname, sizeof(char *) * (e.len + 1));
      }
      e.segname[e.len] = NULL;
      e.sectname[e.len] = NULL;
      e.k = 0;
      while (e.j < e.len)
      {
        e.segname[e.j] = (char *)malloc(sizeof(char) * (ft_strlen((e.k + e.sct64)->segname) + 1));
        e.segname[e.j][ft_strlen(e.sct64->segname)] = '\0';
        ft_strcpy(e.segname[e.j], (e.k + e.sct64)->segname);
        e.sectname[e.j] = (char *)malloc(sizeof(char) * (ft_strlen((e.k + e.sct64)->sectname) + 1));
        e.sectname[e.j][ft_strlen(e.sct64->sectname)] = '\0';
        ft_strcpy(e.sectname[e.j], (e.k + e.sct64)->sectname);
        e.k++;
        e.j++;
      }
    }
    if (e.lc->cmd == LC_SYMTAB)
    {
      e.sym = (struct symtab_command *)e.lc;
      print_output(e, ptr);
      break ;
    }
    e.lc = (void *)e.lc + e.lc->cmdsize;
  }
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
