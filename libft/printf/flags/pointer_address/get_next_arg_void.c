/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_arg_void.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 22:17:18 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/22 22:20:45 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	*get_next_void(int *read, int arg_num, t_pdata *print, va_list args)
{
	if (arg_num > -1)
	{
		while ((*read) < (arg_num - 1))
		{
			va_arg(args, void *);
			(*read)++;
		}
		(*read)++;
		return (va_arg(args, void *));
	}
	while ((*read) < print->flags)
	{
		va_arg(args, void *);
		(*read)++;
	}
	(*read)++;
	print->flags++;
	return (va_arg(args, void *));
}
