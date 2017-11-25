/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nothing_printed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:34:07 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/22 22:15:53 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static t_ll	*nothing_field_proc(t_pdata *print, t_pf *flag, va_list args)
{
	t_ll	*addr;
	int		read;

	read = 0;
	addr = get_next_int_p(&read, flag->flag_arg_val, print, args);
	return (addr);
}

char		*nothing_printed(t_pdata *print, t_pf *flags, va_list args)
{
	t_ll	*addr;

	addr = nothing_field_proc(print, flags, args);
	*addr = print->len;
	return ("");
}
