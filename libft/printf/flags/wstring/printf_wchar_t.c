/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_wchar_t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:57:50 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/22 22:30:03 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int			ft_strwlen(wchar_t *s)
{
	int		l;

	l = 0;
	while (*s++)
		l++;
	return (l);
}

int			ft_charwlen(wchar_t c)
{
	if (c > 0x800)
		return (c > 0x10000 ? 4 : 3);
	return (c > 0x80 ? 2 : 1);
}

static char	*data_process(t_pf *flags, wchar_t *str)
{
	const char	*s_static;
	char		*string;
	int			len;
	char		*b;
	int			a;

	b = NULL;
	a = 0;
	flags->size = 0;
	len = 0;
	while (str[len] && (flags->precis_val > a || flags->precis == -1))
		if (((a += ft_charwlen(str[len++])) <= flags->precis_val) || flags->precis == -1)
			flags->size = a;
	len = flags->size;
	if (flags->width_val > flags->size)
		flags->size = flags->width_val;
	if (!(string = ft_strnew(flags->size)))
		return ("");
	a = flags->left_just;
	ft_memset(string, (flags->zero > 0 && a == 0) ? '0' : ' ', flags->size);
	a = flags->left_just == 1 ? 0 : flags->size - len;
	while (*str && ((flags->precis_val > 0) || flags->precis == -1))
	{
		s_static = ft_unicode_to_utf8(*str++, b);
		if ((flags->precis_val -= ((int)ft_strlen(s_static))) >= 0 || flags->precis == -1)
			ft_memcpy((flags->left_just > 0) ? &(string[a]) :\
			&(string[a]), s_static, a += ft_strlen(s_static));
	}
	while (a < flags->size && flags->left_just == 1)
		string[a++] = ' ';
	return (string);
}

char		*printf_wstring(t_pdata *print, t_pf *flags, va_list args)
{
	wchar_t	*wstring;
	char	*str;

	str = NULL;
	wstring = wchart_field_proc(print, flags, args);
	str = data_process(flags, (wstring == NULL) ? L"(null)" : wstring);
	return (str);
}
