/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:52:28 by ozalisky          #+#    #+#             */
/*   Updated: 2018/06/04 17:13:15 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 100
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
typedef struct		s_gnl
{
	int				fd;
	char			*buffer;
	size_t			file_size;
	struct s_gnl	*next;
}					t_gnl;
typedef struct		s_params
{
	short			minus;
	short			plus;
	short			space;
	short			hash;
	short			zero;
	long			w;
	long			p;
	int				x;
	int				length;
	int				skip;
	char			type;
	ssize_t			counter;
	long			meter;
	char			*ostr;
	int				freeme;
	int				error;
	int				dminus;
}					t_params;
int					get_next_line(const int fd, char **line);
void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
long				ft_strlen(const char *s);
long				ft_strwlen(const wchar_t *s);
long				ft_charwlen(const wchar_t c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *lil, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
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
char				*ft_itoa(long n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				*ft_memcpy_bkw(void *dst, const void *src, size_t n);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_iscntrlch(int c);
int					ft_isspace(int c);
int					ft_iscntrlspace(int c);
int					ft_issign(int c);
int					ft_nbr_lngth(long n);
int					ft_arrdel(char **ar, int size);
int					ft_has_ch(char const *s, char c);
size_t				ft_words(char const *s, char c);
size_t				ft_format_len(const char **format);
t_params			*ft_create_specs();
void				ft_clean_params(t_params **temp);
char				*ft_itoa_base(unsigned long value, int base, int i);
long				ft_strsimplelen(const wchar_t *s);
void				ft_buffer_add_wrong(t_params **temp, const char **s);
int					ft_type_ch(const char **format);
int					ft_prec_ch(const char **format);
int					ft_width_ch(const char **format);
int					ft_length_ch(const char **format);
int					ft_flag_ch(const char *format);
void				ft_flag_add(t_params **temp, const char **format);
void				ft_width_add(t_params **temp, const char **format,
								va_list vl);
void				ft_prec_add(t_params **temp, const char **format,
								va_list vl);
void				ft_length_add(t_params **temp, const char **format);
void				ft_type_add(t_params **temp, const char **format);
void				ft_length_influence_p(t_params **temp, unsigned long xx);
void				ft_length_influence_c(t_params **temp, unsigned int c);
void				ft_length_influence_s(t_params **temp, char *s);
void				ft_buffer_add_ws(t_params **ts, wchar_t *s);
void				ft_length_influence_di(t_params **temp, long di);
void				ft_length_influence_o(t_params **temp, unsigned long o);
void				ft_length_influence_u(t_params **temp, unsigned long u);
void				ft_length_influence_xx(t_params **temp, unsigned long xx);
void				ft_length_influence_b(t_params **temp, unsigned long b);
long				ft_u_size_forbuffer_add(t_params **temp);
void				ft_u_minus_wps(t_params **temp, char **str, long size);
void				ft_u_minus(t_params **ts, char **str, long size);
void				ft_buffer_add_o(t_params **temp, char *ostr);
void				ft_buffer_add_u(t_params **ts, char *ostr);
void				ft_buffer_add_xx(t_params **ts, char *xx);
void				ft_buffer_add_di(t_params **ts, long size);
void				ft_buffer_add_p(t_params **ts, char *di_char);
void				ft_buffer_add_s(t_params **ts, char *s);
void				ft_buffer_add_c(t_params **temp, unsigned char di);
void				ft_buffer_add_wc(t_params **temp, wchar_t c);
void				ft_buffer_wc(t_params **temp, wchar_t c);
int					ft_printf(const char *format, ...);
void				ft_0_wsp(t_params **temp, char **str, long size, long i);
void				ft_0_wps(t_params **temp, char **str, long size, long i);
void				ft_o_minus(t_params **ts, char **str, long size);
void				ft_o_wsp(t_params **temp, char **str, long i, long j);
long				ft_p_size(t_params **temp);
void				ft_p_minus_wsp(t_params **temp, char **str, long size,
								long i);
void				ft_p_minus_ps(t_params **temp, char **str, long size,
								long i);
void				ft_p_minus_wps(t_params **temp, char **str, long size,
								long i);
void				ft_p_minus(t_params **ts, char **str, long size);
void				ft_p_wsp(t_params **temp, char **str, long i);
void				ft_di_minus(t_params **ts, long size, char *str);
void				ft_di_wsp(t_params **ts, long i, char *str);
void				ft_di_p(t_params **ts, long i, char *str);
void				ft_di_wps(t_params **ts, long i, long j, char *str);
void				ft_di_else(t_params **ts, char *str);
void				ft_di_less(t_params **ts);
long				ft_precstrlen(t_params **temp, wchar_t *str);
long				ft_precwidstrlen(t_params **temp, wchar_t *str);
void				ft_buffer_add_ws(t_params **ts, wchar_t *s);
void				ft_ws_minus(t_params **ts, wchar_t **str, wchar_t *s,
							long size);
void				ft_ws_plus(t_params **ts, wchar_t **str, wchar_t *s,
							long size);
void				ft_ws_plus_0(t_params **ts, wchar_t **str, long size);
void				ft_s_plus(t_params **ts, char **str, char *s, long size);
void				ft_x_p(t_params **ts, char **str, long i);
void				ft_x_0(t_params **ts, char **str, long i);
void				ft_x_wpd(t_params **ts, char **str, long i);
void				ft_x_x(char **str, long i);
void				ft_x_free(char *di_char, char *str, t_params **temp);
void				ft_x_minus(t_params **ts, char **str, char *di_char,
							long size);
void				ft_itoa_base_dec(long value, t_params **temp);
long				ft_sl_d(const char *s, t_params **ts);
long				ft_di_size(t_params **ts);
#endif
