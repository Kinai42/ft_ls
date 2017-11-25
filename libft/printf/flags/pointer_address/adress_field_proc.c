/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adress_field_proc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 22:16:25 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/22 22:20:08 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	*address_fld_cus(t_pdata *print, t_pf *fl, va_list ag, int i)
{
	void	*addr;
	int		array[4];
	int		read;
	int		val_tmp[8];

	read = 0;
	address_multi_verif(fl, val_tmp);
	hier_man(print, fl, array, val_tmp);
	simple_sort(array, 3);
	while (i != 3)
	{
		if ((array[i] == val_tmp[2]) && val_tmp[3] != 1)
		{
			addr = get_next_void(&(read), fl->flag_arg_val, print, ag);
			val_tmp[3] = 1;
		}
		else if ((array[i] == val_tmp[0]) && (fl->width > 1))
			fl->width_val = get_next_int(&(read), fl->width_wild, print, ag);
		else if ((array[i] == val_tmp[1]) && (fl->precis > 1))
			fl->precis_val = get_next_int(&(read), fl->precis_wild, print, ag);
		i++;
	}
	address_verif_end(fl, val_tmp, addr);
	return (addr);
}

void		*address_field_proc(t_pdata *print, t_pf *flag, va_list args)
{
	void	*addr;
	int		read;

	read = 0;
	if (flag->width <= 1 && flag->precis <= 1 && flag->flag_arg == -1)
	{
		addr = get_next_void(&read, flag->flag_arg_val, print, args);
		return (addr);
	}
	addr = address_fld_cus(print, flag, args, read);
	return (addr);
}
