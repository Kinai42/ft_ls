/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:49:33 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/24 17:14:35 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_unicode_to_utf8(wchar_t c, char *b)
{
	static char b_static[5];

	b = (char *)b_static;
	if (c < (1 << 7))
		*b++ = (unsigned char)(c);
	else if (c < (1 << 11))
	{
		*b++ = (unsigned char)((c >> 6) | 0xC0);
		*b++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 16))
	{
		*b++ = (unsigned char)(((c >> 12)) | 0xE0);
		*b++ = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		*b++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 21))
	{
		*b++ = (unsigned char)(((c >> 18)) | 0xF0);
		*b++ = (unsigned char)(((c >> 12) & 0x3F) | 0x80);
		*b++ = (unsigned char)(((c >> 6) & 0x3F) | 0x80);
		*b++ = (unsigned char)((c & 0x3F) | 0x80);
	}
	*b = '\0';
	return (b_static);
}

char	*wchar_data_process(t_pf *flags, wchar_t c)
{
	const char	*s_static;
	char		*string;
	int			to_copy;
	char		*b;

	b = NULL;
	s_static = ft_unicode_to_utf8(c, b);
	flags->size = ft_strlen(s_static);
	to_copy = flags->size;
	if ((flags->width_val != -1 && flags->width_val > 1))
		flags->size = flags->width_val;
	string = ft_memset(ft_strnew(flags->size), (flags->zero) ?\
		'0' : ' ', flags->size);
	if (flags->left_just == 1)
		ft_memcpy(&(string[0]), s_static, to_copy);
	else
		ft_memcpy(&(string[flags->size - to_copy]), s_static, to_copy);
	return (string);
}

char	*printf_wchar(t_pdata *print, t_pf *flags, va_list args)
{
	wchar_t	c;
	char	*str;

	c = wchar_field_proc(print, flags, args);
	str = c == '\0' ? char_data_process(flags, '\0') :\
	wchar_data_process(flags, c);
	return (str);
}
