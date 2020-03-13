/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nstabel <nstabel@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 15:59:03 by nstabel        #+#    #+#                */
/*   Updated: 2020/02/15 16:05:53 by nstabel       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef	struct		s_ilist
{
	long long		content;
	struct s_ilist	*next;
}					t_ilist;

size_t				ft_abs(int nb);
void				ft_ilstadd(t_ilist **alst, t_ilist *newlst);
void				ft_ilstapp(t_ilist **alst, t_ilist *newlst);
void				ft_ilstdel(t_ilist **alst);
void				ft_ilstdelone(t_ilist **alst);
t_ilist				*ft_ilstnew(long long content);
char				*ft_append(char **str, char const *append);
size_t				ft_arsize(void **ar);
long long			ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_count_words(char const *s, char c);
void				ft_delnode(void *content, size_t content_size);
int					ft_end(char const *s);
void				ft_freezero(void *mem, size_t size);
t_list				**ft_hsh_chain(void **ar, size_t size, \
					size_t hsh(void *));
t_list				**ft_hsh_linprob(void **ar, size_t size, \
					size_t hsh(void *));
t_list				**ft_hsh_quadprob(void **ar, size_t size, \
					size_t hsh(void *));
char				*ft_insert(char **str, char const *insert, size_t pos);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprime(size_t prime);
int					ft_isprint(int c);
char				*ft_itoa(int n);
char				*ft_itoa_base(long long value, int base);
char				*ft_itoa_long(long long n);
void				ft_lstadd(t_list **alst, t_list *newlst);
void				ft_lstapp(t_list **alst, t_list *newlst);
t_list				*ft_lstcpy(t_list *alst);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstsrt(t_list **alst, int (*method)(void *, void *));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
int					ft_nchar(const char *str, int c);
char				*ft_prepend(char **str, char const *prepend);
size_t				*ft_primetab(size_t n);
int					ft_printf(const char *format, ...);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int i);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnstr(char const *str, size_t len);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_replace(char **str, char const *insert, size_t pos, \
					size_t len);
char				*ft_select(char **str, size_t pos, size_t len);
int					ft_start(char const *s);
int					ft_skipspc(const char *str);
char				*ft_strcalc_add(char **nb, const char *s2);
char				*ft_strcalc_mult(char **nb);
char				*ft_strcalc_div(char **nb);
char				*ft_strcalc_multexptwo(char **nb, int exponent);
int					ft_strcalc_valid(char *s);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strlwr(char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnewfill(size_t len, char c);
char				*ft_strnstr(const char *haystack, const char *needle, \
					size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrev(char *str);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				*ft_strupr(char *s);
size_t				ft_strval(void *ptr);
void				ft_swap(void **ptr1, void **ptr2);
int					ft_tolower(int c);
int					ft_toupper(int c);
t_list				*ft_lstfind_size(t_list *head, size_t size);
char				*ft_strcdup(const char *str, int c);
t_list				*ft_lstunlink(t_list **head, t_list *lst);

#endif
