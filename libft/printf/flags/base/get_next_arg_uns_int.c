/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_arg_uns_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:34:32 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/22 22:00:58 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static t_ull	ft_check_arg_unsint(t_pdata *print, va_list args)
{
	if (print->length == 104)
		return ((t_ull)va_arg(args, unsigned int));
	if (print->length == 208)
		return ((t_ull)va_arg(args, unsigned int));
	if (print->length == 108)
		return ((t_ull)va_arg(args, unsigned long int));
	if (print->length == 216)
		return ((t_ull)va_arg(args, t_ll));
	if (print->length == 106)
		return ((t_ull)va_arg(args, uintmax_t));
	if (print->length == 122)
		return ((t_ull)va_arg(args, size_t));
	return ((t_ull)va_arg(args, unsigned int));
}

t_ull			get_next_uns(int *rd, int arg_n, t_pdata *pt, va_list args)
{
	if (arg_n > -1)
	{
		while ((*rd) < (arg_n - 1))
		{
			va_arg(args, size_t);
			(*rd)++;
		}
		(*rd)++;
		return (ft_check_arg_unsint(pt, args));
	}
	while ((*rd) < pt->flags)
	{
		va_arg(args, size_t);
		(*rd)++;
	}
	(*rd)++;
	pt->flags++;
	return (ft_check_arg_unsint(pt, args));
}
