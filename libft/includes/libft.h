/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 16:57:38 by stmartin          #+#    #+#             */
/*   Updated: 2018/02/28 11:28:43 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <wchar.h>

# define F format
# define BUFF_SIZE 100
# define TRUE 1
# define FALSE 0
# define RC ft_putchar('\n');

typedef struct		s_line
{
	int				oct;
	char			*tmp;
	char			*chr;
	char			*buff;
}					t_line;

typedef struct		s_list
{
	char			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_printf
{
	int				ret;
	int				ret_wchar;
	int				space_number;
	int				valid;
	int				negatif;
	int				neg_sign;
	int				negatif_x;
	int				zero;
	int				d;
	int				ok;
	int				sharp;
	int				plus;
	int				space;
	int				point;
	int				precision_zero;
	int				precision_space;
	int				i;
}					t_printf;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *s1, const char *s2, size_t n);
size_t				ft_countword_btwsign(const char *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char const *s, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *nev);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
double				ft_p2(double nb);
void				ft_tabdel(char ***tab);
void				ft_swap(int *a, int *b);
char				*ft_strrev(char *str);
char				*ft_crypt(char *str);
char				*ft_decrypt(char *str);
void				ft_debug();
int					get_next_line(int const fd, char **line);
void				ft_tab_free(char **tab);
int					ft_tab_len(char **tab);
double				ft_sqrt(double a);
long				ft_atol(const char *str);
void				ft_count_2d_tab(char **tab);
char				*ft_itoa_base(int value, int base);
size_t				ft_strclen(const char *s, char c);
char				*ft_hexa_itoa(unsigned int n, int up);
char				*ft_hexa_ltoa(unsigned long long n, int up);
void				print_memory(const void *addr, size_t size);
void				ft_put_long(long n);
char				*ft_ltoa(long n);
char				*ft_ltoa_base(long value, int base);
void				ft_put_ulong(unsigned long n);
char				*ft_ultoa(unsigned long n);
char				*ft_ultoa_base(unsigned long value, int base);
size_t				ft_size_ttoa(size_t n);
int					ft_printf(const char *format, ...);
double				ft_double_abs(double nb);
int					ft_abs(int nb);
size_t				ft_intsize(int nb);
int					ft_isspace(int c);
size_t				ft_move_sign(const char *s, char c, size_t i);

const char			*percent_percent(const char *format, t_printf *printf);
const char			*percent_percent_neg(const char *format, t_printf *printf);
const char			*if_percent(const char *format, t_printf *printf);
const char			*percent_c(va_list pa, t_printf *print, const char *format);
const char			*percent_x(va_list pa, t_printf *print, const char *format);
const char			*percent_l(va_list pa, t_printf *print, const char *format);
const char			*percent_j(va_list pa, t_printf *print, const char *format);
const char			*percent_h(va_list pa, t_printf *print, const char *format);
const char			*percent_z(va_list pa, t_printf *print, const char *format);
const char			*percent_d(va_list pa, t_printf *print, const char *format);
const char			*percent_d_up(va_list pa, t_printf *print, const char *f);
const char			*percent_o(va_list pa, t_printf *print, const char *format);
const char			*check_valid_specifier(const char *format);
const char			*count_espace(const char *format, t_printf *print);
const char			*check_neg_sign(t_printf *print, const char *format);
const char			*check_space(const char *format, t_printf *print);
const char			*precision(const char *format, int d, t_printf *print);
const char			*take_precision(const char *format, t_printf *print);
void				write_space_int(int space, t_printf *print);
void				write_space_wchar(t_printf *print);
void				write_space_char(char *p, t_printf *print);
void				write_space_int_other(t_printf *print, const char *format);
void				percent_u_up(va_list pa, t_printf *print);
void				percent_o_up(va_list pa, t_printf *print);
void				percent_c_up(va_list pa, t_printf *print);
void				percent_s_up(va_list pa, t_printf *print);
void				percent_p(va_list pa, t_printf *print, const char *format);
void				init_struct(t_printf *printf);
void				write_space_hex(long space, t_printf *print);
void				write_space_percent_s(int space, t_printf *print);
void				put_space_or_zero(t_printf *print, int d);
void				put_space_or_zero_u(t_printf *print, unsigned int d);
void				put_space_or_zero_o(t_printf *print, int o);
void				put_space_or_zero_x(t_printf *print, int x);
void				put_space_or_zero_s(t_printf *print, char *s);
void				percent_s(va_list pa, t_printf *p);
void				struct_is_zero(t_printf *print, const char *format);
int					space_zero(t_printf *print, const char *format, int d);
int					ft_printf(const char *format, ...);
int					count_space(const char *format);
int					is_precision_ok(const char *format, t_printf *print);
void				percent_l_5(va_list pa, t_printf *print, const char *f);
void				percent_l_6(va_list pa, t_printf *print, const char *f);
void				loop_zero(t_printf *print);
void				loop_space(t_printf *print);
void				while_nb_zero(int nb_zero, t_printf *print);
void				while_space_number(t_printf *print);
void				while_space(t_printf *print);
void				loop_space_no_ret(t_printf *print);
void				while_precision_space(t_printf *print);
void				while_space_number_zero(t_printf *print);
void				write_null(t_printf *print);
void				space_number_inf(t_printf *print);
char				*ft_lltoa(long long val, int base);

int					space_zero(t_printf *print, const char *format, int d);
void				put_space_or_zero(t_printf *print, int d);
void				decr_space_number(t_printf *print);
void				decr_precision_zero(t_printf *print, int z);
void				struct_is_zero(t_printf *print, const char *format);
void				write_space_hex(long space, t_printf *print);
void				percent_s_up_normal_1(t_printf *print, wchar_t *s, int i);
void				percent_s_up_precision(t_printf *print, wchar_t *s);
int					count_octet_wchar(wchar_t *s, t_printf *print);
void				percent_no_specifier(const char *format, t_printf *print);
int					is_precision_ok(const char *format, t_printf *print);
int					particular_case(va_list pa);
int					particular_case_2(va_list pa);
void				loop_zero_no_ret(t_printf *print);
void				is_precision_ok_2(const char *format, t_printf *print);
const char			*percent_x(va_list pa, t_printf *print, const char *format);
const char			*precision(const char *format, int d, t_printf *print);
const char			*percent_d(va_list pa, t_printf *print, const char *format);
const char			*percent_d_5(const char *f, t_printf *print, int d);
const char			*check_flag(const char *format, t_printf *print);
const char			*check_flag_1(const char *format, t_printf *print);
const char			*percent_l(va_list pa, t_printf *print, const char *format);
const char			*take_precision(const char *format, t_printf *print);
const char			*ft_printf_1(const char *format, t_printf *print);
const char			*ft_printf_2(const char *format, t_printf *pri, va_list pa);
const char			*ft_printf_3(const char *format, t_printf *pri, va_list pa);
const char			*ft_printf_4(const char *format, t_printf *pri, va_list pa);
const char			*if_is_digit(const char *format, t_printf *print);
const char			*if_point_or_plus(const char *format, t_printf *print);

#endif
