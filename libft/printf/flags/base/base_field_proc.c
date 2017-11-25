/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_field_proc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:17:24 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/22 22:00:35 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static t_ull	base_fld_cus(t_pdata *print, t_pf *fl, va_list ag, int i)
{
	t_ull	dec;
	int		array[4];
	int		read;
	int		val_tmp[8];

	read = 0;
	base_multi_verif(fl, val_tmp);
	hier_man(print, fl, array, val_tmp);
	simple_sort(array, 3);
	while (i != 3)
	{
		if ((array[i] == val_tmp[2]) && val_tmp[3] != 1)
		{
			dec = get_next_uns(&(read), fl->flag_arg_val, print, ag);
			val_tmp[3] = 1;
		}
		else if ((array[i] == val_tmp[0]) && (fl->width > 1))
			fl->width_val = get_next_uns(&(read), fl->width_wild, print, ag);
		else if ((array[i] == val_tmp[1]) && (fl->precis > 1))
			fl->precis_val = get_next_uns(&(read), fl->precis_wild, print, ag);
		i++;
	}
	int_verif_end(fl, val_tmp, dec);
	return (dec);
}

t_ull			base_field_proc(t_pdata *print, t_pf *flag, va_list args)
{
	t_ull	dec;
	int		read;

	read = 0;
	if (flag->width <= 1 && flag->precis <= 1 && flag->flag_arg == -1)
	{
		dec = get_next_uns(&read, flag->flag_arg_val, print, args);
		return (dec);
	}
	dec = base_fld_cus(print, flag, args, read);
	return (dec);
}
