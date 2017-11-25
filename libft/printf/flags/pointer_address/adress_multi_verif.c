/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adress_multi_verif.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 22:22:22 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/22 22:24:05 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	address_multi_verif(t_pf *flag, int *val_tmp)
{
	val_tmp[4] = 0;
	val_tmp[5] = 0;
	if (flag->width_wild != -1 && (flag->width_wild == flag->precis_wild))
	{
		val_tmp[4] = flag->precis;
		val_tmp[5] = flag->precis_wild;
		flag->precis_wild = -1;
		flag->precis = -1;
	}
	if (flag->flag_arg != -1 && (flag->flag_arg_val == flag->precis_wild))
	{
		val_tmp[4] = flag->precis;
		val_tmp[5] = flag->precis_wild;
		flag->precis_wild = -1;
		flag->precis = -1;
	}
	if (flag->flag_arg != -1 && (flag->flag_arg_val == flag->width_wild))
	{
		val_tmp[6] = flag->width;
		val_tmp[7] = flag->width_wild;
		flag->width_wild = -1;
		flag->width = -1;
	}
}

void	address_verif_end(t_pf *flag, int *val_tmp, void *addr)
{
	if (val_tmp[5] != -1 && flag->width_wild == val_tmp[5])
	{
		flag->precis_val = flag->width_val;
		flag->precis = val_tmp[4];
		flag->precis_wild = val_tmp[5];
	}
	if (val_tmp[5] != -1 && flag->flag_arg_val == val_tmp[5])
	{
		flag->precis_val = (int)addr;
		flag->precis = val_tmp[4];
		flag->precis_wild = val_tmp[5];
	}
	if (val_tmp[5] != -1 && flag->flag_arg_val == val_tmp[6])
	{
		flag->precis_val = (int)addr;
		flag->precis = val_tmp[6];
		flag->precis_wild = val_tmp[7];
	}
}
