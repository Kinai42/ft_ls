/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_arg_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 18:22:00 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/12 18:23:58 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

t_ll	ft_check_arg_int(t_pdata *print, va_list args)
{
	if (print->length == 104)
		return ((t_ll)va_arg(args, int));
	if (print->length == 208)
		return ((t_ll)va_arg(args, int));
	if (print->length == 108)
		return ((t_ll)va_arg(args, long int));
	if (print->length == 216)
		return ((t_ll)va_arg(args, t_ll));
	if (print->length == 106)
		return ((t_ll)va_arg(args, intmax_t));
	if (print->length == 122)
		return ((t_ll)va_arg(args, size_t));
	return ((t_ll)va_arg(args, int));
}

t_ll	get_next_int(int *read, int arg_num, t_pdata *print, va_list args)
{
	if (arg_num > -1)
	{
		while ((*read) < (arg_num - 1))
		{
			va_arg(args, size_t);
			(*read)++;
		}
		(*read)++;
		return (ft_check_arg_int(print, args));
	}
	while ((*read) < print->flags)
	{
		va_arg(args, size_t);
		(*read)++;
	}
	(*read)++;
	print->flags++;
	return (ft_check_arg_int(print, args));
}
