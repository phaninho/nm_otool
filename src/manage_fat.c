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

// int swap_endian(int n)
// {
//    return (((n>>24)&0xff) | // move byte 3 to byte 0
//                   ((n<<8)&0xff0000) | // move byte 1 to byte 2
//                   ((n>>8)&0xff00) | // move byte 2 to byte 1
//                   ((n<<24)&0xff000000));
// }

int		swap_bin(int val)
{
	return (((val & 0xFF) << 24) | (((val >> 8) & 0xFF) << 16) |
		(((val >> 16) & 0xFF) << 8) | ((val >> 24) & 0xFF));
}

void handle_fat(void *ptr, int o)
{
//   t_envfat e;
//   // struct fat_header *header;
// int arch_n;
// (void)o;
//   // e = init_env_fat();
//   e.header = (struct fat_header *)ptr;
//   arch_n = e.header->nfat_arch;
//   if (e.header->magic == FAT_CIGAM)
//   {
//     arch_n = swap_endian(e.header->nfat_arch);
//     printf("sizeof(struct fat_arch) => [%lu]\n", sizeof(struct fat_arch));
//   }
//   e.arch = (void *)e.header + sizeof(struct fat_header);
//   // archn = swap_endian(e.lc->cputype);
//   printf("cputype[%d] offset %d size %d\n", swap_endian(e.arch->cputype), swap_endian(e.arch->offset), swap_endian(e.arch->size));
//   if (swap_endian(e.arch->cputype) == CPU_TYPE_I386)
//     printf("ok\n");

struct fat_header		*fat_header;
	struct fat_arch			*arch;
	uint32_t				offset;
	struct mach_header_64	*header;
	int				i;

	fat_header = (struct fat_header *)ptr;
	arch = (void *)fat_header + sizeof(*fat_header);
	offset = swap_bin(arch->offset);
	i = 0;
	while (i < swap_bin(fat_header->nfat_arch))
	{
		offset = swap_bin(arch->offset);
		header = (void *)ptr + offset;
		if (swap_bin(arch->cputype) == CPU_TYPE_X86_64)
			break ;
		arch = (void *)arch + sizeof(*arch);
		// if (check_range_addr(arch) || check_range_addr(header))
			// return (print_error("file", "truncated or malformed object"));
		i++;
	}
	header = (void *)ptr + offset;
  handle_64((void *)header, o);
    // handle_32((void *)e.lc + sizeof(struct fat_arch) + swap_endian(e.lc->offset), o);

  // e.lc = (void *)e.lc + sizeof(struct fat_arch);
  // printf("cputype[%d] offset %d size %d\n", swap_endian(e.lc->cputype), swap_endian(e.lc->offset), swap_endian(e.lc->size));
  // if (swap_endian(e.lc->cputype) == CPU_TYPE_X86_64)
  //   printf("ok\n");
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
