/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_t_multi_verif.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 18:01:15 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/12 18:02:02 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	wchart_multi_verif(t_pf *flag, int *val_tmp, int inv)
{
	val_tmp[4] = 0;
	val_tmp[5] = 0;
	if (inv == 1)
	{
		if (flag->width_wild != -1 && (flag->width_wild == flag->precis_wild))
		{
			val_tmp[4] = flag->precis;
			val_tmp[5] = flag->precis_wild;
			flag->precis_wild = -1;
			flag->precis = -1;
		}
	}
	else if (inv == 2)
	{
		if (val_tmp[5] != -1 && flag->width_wild == val_tmp[5])
		{
			flag->precis_val = flag->width_val;
			flag->precis = val_tmp[4];
			flag->precis_wild = val_tmp[5];
		}
	}
}
