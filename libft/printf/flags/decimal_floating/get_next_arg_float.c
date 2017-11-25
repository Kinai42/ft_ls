/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_arg_float.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:23:48 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/12 17:26:13 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

double	get_next_float(int *read, int arg_num, t_pdata *print, va_list args)
{
	double	k;

	if (arg_num > -1)
	{
		while ((*read) < (arg_num - 1))
		{
			va_arg(args, size_t);
			(*read)++;
		}
		(*read)++;
		return (va_arg(args, double));
	}
	while ((*read) < print->flags)
	{
		va_arg(args, size_t);
		(*read)++;
	}
	(*read)++;
	k = va_arg(args, double);
	return (k);
}
