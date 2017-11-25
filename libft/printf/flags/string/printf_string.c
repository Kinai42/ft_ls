/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:42:49 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/22 22:28:28 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char *str_data_process(t_pf *flags, char *str)
{
	char *string;
	int total;
	int copy;
	int str_len;
	int a;

	a = flags->precis_val;
	str_len = ft_strlen(str);
	copy = (a < str_len && a != -1) ? a : str_len;
	total = (flags->width_val > copy ) ? flags->width_val : copy;
	string = ft_strnew(total);
	a = flags->left_just;
	ft_memset(string, (flags->zero > 0 && a == 0) ? '0' : ' ', total);
	a = total - copy;
	ft_memcpy((flags->left_just > 0) ? &(string[0]) : &(string[a]), str, copy);
	flags->size = total;
	return (string);
}

char			*printf_string(t_pdata *print, t_pf *flags, va_list args)
{
	char	*str;

	if (flags->length == 108)
	 return (printf_wstring(print, flags, args));
	str = str_field_proc(print, flags, args);
	str = str_data_process(flags, (str == NULL) ? "(null)" : str);
	return (str);
}
