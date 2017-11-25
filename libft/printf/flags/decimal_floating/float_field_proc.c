/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_field_proc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:19:17 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/12 17:21:02 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static double	float_fld_cus(t_pdata *print, t_pf *fl, va_list ag, int i)
{
	double	floa;
	int		array[4];
	int		read;
	int		val_tmp[8];

	read = 0;
	float_multi_verif(fl, val_tmp, 1);
	hier_man(print, fl, array, val_tmp);
	simple_sort(array, 3);
	while (i != 3)
	{
		if ((array[i] == val_tmp[2]) && val_tmp[3] != 1)
		{
			floa = get_next_float(&(read), fl->flag_arg_val, print, ag);
			val_tmp[3] = 1;
		}
		else if ((array[i] == val_tmp[0]) && (fl->width > 1))
			fl->width_val = get_next_int(&(read), fl->width_wild, print, ag);
		else if ((array[i] == val_tmp[1]) && (fl->precis > 1))
			fl->precis_val = get_next_int(&(read), fl->precis_wild, print, ag);
		i++;
	}
	float_multi_verif(fl, val_tmp, 2);
	return (floa);
}

double			float_field_proc(t_pdata *print, t_pf *flag, va_list args)
{
	double	floa;
	int		read;

	read = 0;
	if (flag->width <= 1 && flag->precis <= 1 && flag->flag_arg == -1)
	{
		floa = get_next_float(&read, flag->flag_arg_val, print, args);
		return (floa);
	}
	floa = float_fld_cus(print, flag, args, read);
	return (floa);
}
