/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_field_proc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:54:36 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/12 17:55:28 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static wchar_t	wchar_fld_cus(t_pdata *print, t_pf *fl, va_list ag, int i)
{
	wchar_t	str;
	int		array[4];
	int		read;
	int		val_tmp[8];

	read = 0;
	str_multi_verif(fl, val_tmp, 1);
	hier_man(print, fl, array, val_tmp);
	simple_sort(array, 3);
	while (i != 3)
	{
		if ((array[i] == val_tmp[2]) && val_tmp[3] != 1)
		{
			str = get_next_wchar(&(read), fl->flag_arg_val, print, ag);
			val_tmp[3] = 1;
		}
		else if ((array[i] == val_tmp[0]) && (fl->width > 1))
			fl->width_val = get_next_int(&(read), fl->width_wild, print, ag);
		else if ((array[i] == val_tmp[1]) && (fl->precis > 1))
			fl->precis_val = get_next_int(&(read), fl->precis_wild, print, ag);
		i++;
	}
	str_multi_verif(fl, val_tmp, 2);
	return (str);
}

wchar_t			wchar_field_proc(t_pdata *print, t_pf *flag, va_list args)
{
	wchar_t	c;
	int		read;

	read = 0;
	if (flag->width <= 1 && flag->precis <= 1 && flag->flag_arg == -1)
	{
		c = get_next_wchar(&read, flag->flag_arg_val, print, args);
		return (c);
	}
	c = wchar_fld_cus(print, flag, args, read);
	return (c);
}
