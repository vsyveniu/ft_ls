/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:05:13 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/06/05 14:17:19 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *destptr, const char *srcptr);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t num);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strdup(char *src);
char				*ft_strncpy(char *dest, const char *src, size_t count);
char				*ft_strchr(const char *str, int symbol);
char				*ft_strrchr(const char *str, int symbol);
void				*ft_memset(void *dest, int ch, size_t count);
void				ft_bzero(void *src, size_t n);
void				*ft_memcpy(void *restrict dst,
					const void *restrict src, size_t count);
void				*ft_memmove(void *dst, const void *src, size_t count);
void				*ft_memccpy(void *dst, const void *src, int c, size_t size);
void				*ft_memchr(const void *src, int c, size_t num);
int					ft_memcmp(const void *s1, const void *s2, size_t num);
void				*ft_memalloc(size_t size);
int					ft_isascii(int ch);
int					ft_atoi(const char *str);
int					ft_isalnum(int	c);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t num);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_putchar(char c);
char				*ft_strtrim(char const *s);
void				ft_putendl(char const *s);
void				ft_putstr(char const *s);
void				ft_putendl_fd(char const *s, int fd);
char				**ft_strsplit(char const *s, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_itoa(int n);
t_list				*ft_lstnew(void const *content, size_t content_size);
int					ft_isprint (int c);
char				*ft_strstr(const char *str, const char *substr);
char				*ft_strnstr(const char *str, const char *substr,
					size_t num);
void				ft_lstdelone(t_list **alst, void (*del) (void *, size_t));
void				ft_lstdel(t_list **alst, void (*del) (void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_lstlen(t_list *lst);
int					ft_sqrt(int nb);
char				*ft_capitalizer(char *str);
int					ft_countwords(const char *s);
int					ft_strclen(const char *str, int c);
void				ft_swap(int *a, int *b);
void				ft_putlongnbr(unsigned long long n);
void				ft_putnnstr(const char *str, int start);
void				ft_putnnnstr(const char *str, int start, int end);
#endif
