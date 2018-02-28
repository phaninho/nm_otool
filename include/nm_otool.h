/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 15:51:56 by stmartin          #+#    #+#             */
/*   Updated: 2018/02/23 15:52:02 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NMO_TOOL_H
# define NMO_TOOL_H

#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "../libft/includes/libft.h"
#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <mach-o/fat.h>

typedef struct s_env32 t_env32;
typedef struct s_env64 t_env64;
typedef struct s_envfat t_envfat;
typedef struct s_ut t_ut;

struct  s_ut
{
  int i;
  int len;
  int o;
  char *strtab;
  char *str;
};

struct  s_env32
{
  int   i;
  int   j;
  int   k;
  int   len;
  char   **segname;
  char   **sectname;
  struct mach_header *header;
  struct load_command       *lc;
  struct symtab_command   *sym;
  struct section       *sct32;
  struct segment_command *sg32;
  struct nlist       *array;
};

struct  s_env64
{
  int   i;
  int   j;
  int   k;
  int   len;
  char   **segname;
  char   **sectname;
  struct mach_header_64 *header;
  struct load_command       *lc;
  struct symtab_command   *sym;
  struct section_64       *sct64;
  struct segment_command_64 *sg64;
  struct nlist_64       *array;
};

struct  s_envfat
{
  // int   i;
  // int   j;
  // int   k;
  // int   len;
  // char   **segname;
  // char   **sectname;
  struct fat_header *header;
  struct fat_arch       *lc;
  // struct symtab_command   *sym;
  // struct section_64       *sct64;
  // struct segment_command_64 *sg64;
  // struct nlist_64       *array;
};

void    print_output_32(t_env32 e, void *ptr, int o);
void    print_output_64(t_env64 e, void *ptr, int o);
void	  tab_alpha_order32(int *order, struct nlist *array, char *strtb, int l);
void	  tab_alpha_order64(int *order, struct nlist_64 *array, char *strtb, int l);
void    handle_32(void *ptr, int o);
void    handle_64(void *ptr, int o);
void    handle_fat(void *ptr, int o);
char    define_symbol_type(char c, int addr_value, char *sct, char *seg);

#endif
