/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 20:10:33 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/23 15:50:48 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include "libft.h"

# define DEFAULT "\e[38;5;252m"
# define GREEN "\e[38;5;82m"
# define RED "\e[38;5;196m"
# define ORANGE "\e[38;5;202m"
# define YELLOW "\e[38;5;226m"
# define BLUE "\e[38;5;69m"
# define CYAN "\e[38;5;123m"
# define WHITE "\e[38;5;15m"
# define BROWN "\e[38;5;202m"
# define VIOLET "\e[38;5;212m"
# define LEMON "\e[38;5;190m"

typedef unsigned long long		t_ull;
typedef long long				t_ll;

typedef struct	s_pdata
{
	char	*data;
	size_t	len;
	int		flags;
	int		tstart;
	int		tend;
	int		length;
}				t_pdata;

typedef struct	s_pf
{
	char	left_just;
	char	num_sign;
	char	space;
	char	num_type;
	char	zero;
	char	comma;
	char	width;
	int		width_wild;
	int		width_val;
	char	precis;
	int		precis_wild;
	int		precis_val;
	int		length;
	char	flag;
	char	flag_arg;
	int		flag_arg_val;
	int		size;
}				t_pf;

typedef struct	s_temp
{
	int		i;
	int		count;
	int		flag;
	int		start;
	int		end;

}				t_temp;

char			*((*g_function[2])(t_pdata *print, t_pf *flags, va_list args));
int				ft_printf(const char *str, ...);
int				is_flag(char c);
int				check_width(t_pf *flag, const char *str, int start, int end);
int				check_precis(t_pf *flag, const char *str, int start, int end);
void			data_man(t_pdata *print, const char *src, int start, int end);
int				check_lenth(t_pf *flag, const char *str, int start, int end);
int				flag_man(t_pdata **print, t_temp *temp, const char *str,\
				va_list args);
int				format_verif(t_pf **flag, const char *str, t_temp *tp,\
				int *len);
t_ll			get_next_int(int *read, int arg_num, t_pdata *print,\
				va_list args);
void			hier_man(t_pdata *print, t_pf *flag, int *array, int *val_tmp);
char			*ft_precis(t_pf *flags, char *str, int size);
char			*ft_sign(t_pf *flags, char *str, char sign);
char			*ft_num_type(char *str, int base, char maj);
int				ft_position(t_pf *flags, int size, int len);
char			*printf_string(t_pdata *print, t_pf *flags, va_list args);
char			*str_field_proc(t_pdata *print, t_pf *flag, va_list args);
char			*get_next_str(int *read, int arg_num, t_pdata *print,\
				va_list args);
void			str_multi_verif(t_pf *flag, int *val_tmp, int inv);
char			*printf_int(t_pdata *print, t_pf *flags, va_list args);
t_ll			int_field_proc(t_pdata *print, t_pf *flag, va_list args);
void			int_multi_verif(t_pf *flag, int *val_tmp);
void			int_verif_end(t_pf *flag, int *val_tmp, int inv);
char			*printf_char(t_pdata *print, t_pf *flags, va_list args);
char			char_field_proc(t_pdata *print, t_pf *flag, va_list args);
char			get_next_char(int *read, int arg_num, t_pdata *print,\
				va_list args);
char			*char_data_process(t_pf *flags, char c);
void			char_multi_verif(t_pf *flag, int *val_tmp, int inv);
char			*printf_base(t_pdata *print, t_pf *flags, va_list args);
t_ull			base_field_proc(t_pdata *print, t_pf *flag, va_list args);
void			base_multi_verif(t_pf *flag, int *val_tmp);
void			base_verif_end(t_pf *flag, int *val_tmp, int inv);
t_ull			get_next_uns(int *read, int arg_num, t_pdata *print,\
				va_list args);
char			*printf_address(t_pdata *print, t_pf *flags, va_list args);
void			*address_field_proc(t_pdata *print, t_pf *flag, va_list args);
void			address_multi_verif(t_pf *flag, int *val_tmp);
void			address_verif_end(t_pf *flag, int *val_tmp, void *addr);
void			*get_next_void(int *read, int arg_num, t_pdata *print,\
				va_list args);
char			*printf_float(t_pdata *print, t_pf *flags, va_list args);
double			float_field_proc(t_pdata *print, t_pf *flag, va_list args);
void			float_multi_verif(t_pf *flag, int *val_tmp, int inv);
double			get_next_float(int *read, int arg_num, t_pdata *print,\
				va_list args);
char			*data_process_f(t_pf *flags, double floa);
char			*printf_scientific(t_pdata *print, t_pf *flags, va_list args);
double			scientific_field_proc(t_pdata *print, t_pf *flag, va_list args);
char			*data_process_e(t_pf *flags, double floa);
char			*printf_short_represent(t_pdata *print, t_pf *flags,\
				va_list args);
char			*printf_wchar(t_pdata *print, t_pf *flags, va_list args);
wchar_t			wchar_field_proc(t_pdata *print, t_pf *flag, va_list args);
wchar_t			get_next_wchar(int *read, int arg_num, t_pdata *print,\
				va_list args);
void			wchar_multi_verif(t_pf *flag, int *val_tmp, int inv);
int				ft_strwlen(wchar_t *s);
char			*wchar_data_process(t_pf *flags, wchar_t c);
char			*ft_unicode_to_utf8(wchar_t c, char *b);
char			*printf_wstring(t_pdata *print, t_pf *flags, va_list args);
wchar_t			*wchart_field_proc(t_pdata *print, t_pf *flag, va_list args);
wchar_t			*get_next_wchart(int *read, int arg_num, t_pdata *print,\
				va_list args);
void			wchart_multi_verif(t_pf *flag, int *val_tmp, int inv);
char			*nothing_printed(t_pdata *print, t_pf *flags, va_list args);
t_ll			*get_next_int_p(int *read, int arg_num, t_pdata *print,\
				va_list args);
char			*data_process_modulo(t_pf *flags);
#endif
