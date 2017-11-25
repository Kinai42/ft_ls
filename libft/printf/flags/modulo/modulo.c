/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 18:08:50 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/22 22:10:52 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int		ft_size_modulo(t_pf *flags)
{
	flags->size = 1;
	flags->size += flags->width_val > flags->size ?\
		flags->width_val - flags->size : 0;
	return (flags->size);
}

char			*data_process_modulo(t_pf *flags)
{
	char	*str;
	int		size;

	size = ft_size_modulo(flags);
	if (flags->zero == 1 && flags->left_just == 0)
		str = ft_memset(ft_memalloc(size + 1), '0', size);
	else
		str = ft_memset(ft_memalloc(size + 1), ' ', size);
	if (flags->left_just == 1)
		str[0] = '%';
	else
		str[size - 1] = '%';
	return (str);
}
