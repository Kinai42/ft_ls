/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_wchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:47:48 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/12 17:49:23 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

wchar_t	get_next_wchar(int *read, int arg_num, t_pdata *print, va_list args)
{
	if (arg_num > -1)
	{
		while ((*read) < (arg_num - 1))
		{
			va_arg(args, size_t);
			(*read)++;
		}
		(*read)++;
		return (va_arg(args, wchar_t));
	}
	while (*read < print->flags)
	{
		va_arg(args, size_t);
		(*read)++;
	}
	(*read)++;
	print->flags++;
	return (va_arg(args, wchar_t));
}
