/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 16:23:20 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/22 20:42:59 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <wchar.h>
# include <unistd.h>
# include <stdio.h>

# define BASE_MAJ(x) "0123456789ABCDEF"[x]
# define BASE_MIN(x) "0123456789abcdef"[x]

typedef unsigned long long int	t_ull;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			ft_bzero(void *s, size_t n);
void 			ft_cleaner(char **tab, int count);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstpush(t_list **alst, t_list *new);
void			ft_memdel(void **ap);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbrendl(int i);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_puttab(char **tab);
void			ft_putwchar(wchar_t c);
void			ft_putwstr(wchar_t *s);
void			ft_simple_sort(int *array, int len);
void			ft_strclr(char *s);
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));

void			*ft_memccpy (void *dest, const void *src, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memalloc(size_t size);

char		*ft_ftoa(double floa, long long *f);
char			*ft_itoa(long long n);
char		*ft_itoabase_uns(unsigned long long n, int b, long long *f, char c);
char			*ft_strcat(char *dest, char *src);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dest, char *src);

char			*ft_strchri(const char *s, int c, unsigned int len);
char			*ft_strdup(char *src);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoini(char const *s1, char const *s2, size_t len);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dest, char *src, size_t n);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(char *str, char *to_find, size_t len);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char(*f)(unsigned int, char));
char			*ft_strrchr(const char *s, int c);
char			*ft_strrem(char *str, int from, int len);
char			*ft_strresize(char *str, size_t size);
char			*ft_strrev(char *str);
char			*ft_strstr(char *str, char *to_find);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);

int				ft_abs(int i);
int				ft_atoi(char *str);
int		ft_charwlen(wchar_t c);
int				ft_chrindex(char *str, char c);
int				ft_chrindexi(char *str, char c, int len);
int			ft_countwords(char const *s, char c);
int				ft_errret(char *name, char *msg, int ret);
int				ft_freeret(void *p, int r);
int				ft_intlen(long long n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isspace(char c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_sqrt(int nb);
int				ft_strcmp(char *s1, char *s2);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int		ft_strwlen(wchar_t *s);
int				ft_tolower(int c);
int				ft_toupper(int c);

t_ull			ft_iterative_power(int nb, int power);

size_t			ft_strlcat(char *dest, char const *src, size_t size);
size_t			ft_strlen(const char *s);

t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
