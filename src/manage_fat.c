#include "../include/nm_otool.h"
// t_envfat   init_envfat()
// {
//   t_envfat e;
//
//   e.i = 0;
//   e.j = 0;
//   e.len = 0;
//   e.segname = NULL;
//   e.sectname = NULL;
//   return (e);
// }

int swap_endian(int n)
{
   return (((n>>24)&0xff) | // move byte 3 to byte 0
                  ((n<<8)&0xff0000) | // move byte 1 to byte 2
                  ((n>>8)&0xff00) | // move byte 2 to byte 1
                  ((n<<24)&0xff000000));
}

void handle_fat(void *ptr, int o)
{
  t_envfat e;
  // struct fat_header *header;
int archn;
(void)o;
  // e = init_env_fat();
  e.header = (struct fat_header *)ptr;
  archn = e.header->nfat_arch;
  if (e.header->magic == FAT_CIGAM)
  {
    archn = swap_endian(e.header->nfat_arch);
    printf("sw => [%d]\n", archn);
  }
  e.lc = ptr + sizeof(struct fat_header);
  archn = swap_endian(e.lc->cputype);
  printf("[%d]\n", archn);
  // while (e.i++ < (int)e.header->ncmds)
  // {
  //   if (e.lc->cmd == LC_SEGMENT)
  //     e = lc_segment_fat(e);
  //   if (e.lc->cmd == LC_SYMTAB)
  //   {
  //     e.sym = (struct symtab_command *)e.lc;
  //     print_output_fat(e, ptr, o);
  //     break ;
  //   }
  //   e.lc = (void *)e.lc + e.lc->cmdsize;
  // }
}
