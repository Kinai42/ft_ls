/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_man.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 18:06:05 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/12 18:06:38 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	data_man(t_pdata *print, const char *src, int start, int end)
{
	print->len += (end - start);
	write(1, &src[start], (end - start));
}
