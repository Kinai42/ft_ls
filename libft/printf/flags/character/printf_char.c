/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:56:40 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/24 17:15:32 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*char_data_process(t_pf *flags, char c)
{
	char	*str;

	flags->size = 1;
	if ((flags->width_val != -1 && flags->width_val > 1))
		flags->size = flags->width_val;
	if (flags->zero == 1 && flags->left_just == 0)
		str = ft_memset(ft_memalloc(flags->size + 1), '0', flags->size);
	else
		str = ft_memset(ft_memalloc(flags->size + 1), ' ', flags->size);
	if (flags->left_just == 1)
		str[0] = c;
	else
		str[flags->size - 1] = c;
	return (str);
}

char	*printf_char(t_pdata *print, t_pf *flags, va_list args)
{
	char	c;
	wchar_t	wc;
	char	*str;

	if (print->length == 108)
	{
		wc = wchar_field_proc(print, flags, args);
		str = wchar_data_process(flags, wc);
	}
	else
	{
		c = char_field_proc(print, flags, args);
		str = char_data_process(flags, c);
	}
	return (str);
}
