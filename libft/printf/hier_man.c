/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hier_man.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 18:24:10 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/12 18:25:49 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void var_init(int *array, int *val_tmp, char flag)
{
	if (flag == 0)
	{
		val_tmp[0] = 0;
		val_tmp[1] = 0;
		val_tmp[2] = 0;
	}
	else
	{
		array[0] = val_tmp[0];
		array[1] = val_tmp[1];
		array[2] = val_tmp[2];
	}
}

void hier_man(t_pdata *print, t_pf *flag, int *array, int *val_tmp)
{
	var_init(array, val_tmp, 0);
	if(flag->width > 1 && flag->width_wild < 0)
		val_tmp[0] = print->flags + 1;
	else
		val_tmp[0] = flag->width_wild;
	if(flag->precis > 1 && flag->precis_wild < 0 && val_tmp[0] != -1)
		val_tmp[1] = print->flags + 2;
	else if(flag->precis > 1 && flag->precis_wild < 0)
		val_tmp[1] = print->flags + 1;
	else
		val_tmp[1] = flag->precis_wild;
	if(flag->flag_arg == -1 && (flag->width == 2 && flag->width_wild == -1) && flag->precis == 2 && flag->precis_wild == -1)
		val_tmp[2] = print->flags + 3;
	else if(flag->flag_arg == -1 &&  ((flag->width == 2 && flag->width_wild \
					== -1) || (flag->precis == 2 && flag->precis_wild == -1)))
		val_tmp[2] = print->flags + 2;
	else if(flag->flag_arg > -1)
		val_tmp[2] = flag->flag_arg_val;
	else
		val_tmp[2] = print->flags + 1 ;
	var_init(array, val_tmp, 1);
}
