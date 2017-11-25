/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_arg_int_p.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:32:35 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/22 22:11:39 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static t_ll	*ft_check_arg_int_p(t_pdata *print, va_list args)
{
	if (print->length == 204)
		return ((t_ll *)va_arg(args, int*));
	if (print->length == 104)
		return ((t_ll *)va_arg(args, int*));
	if (print->length == 108)
		return ((t_ll *)va_arg(args, long int*));
	if (print->length == 216)
		return ((t_ll *)va_arg(args, t_ll*));
	if (print->length == 106)
		return ((t_ll *)va_arg(args, intmax_t*));
	if (print->length == 122)
		return ((t_ll *)va_arg(args, size_t*));
	return ((t_ll *)va_arg(args, int*));
}

t_ll		*get_next_int_p(int *read, int num, t_pdata *print, va_list args)
{
	if (num > -1)
	{
		while ((*read) < (num - 1))
		{
			va_arg(args, size_t);
			(*read)++;
		}
		(*read)++;
		return (ft_check_arg_int_p(print, args));
	}
	while ((*read) < print->flags)
	{
		va_arg(args, size_t);
		(*read)++;
	}
	(*read)++;
	print->flags++;
	return (ft_check_arg_int_p(print, args));
}
