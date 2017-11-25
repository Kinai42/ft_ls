/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:26:40 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/22 22:08:20 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static unsigned int	ft_digitlen(t_pf *flags, double floa, char *sign)
{
	int		size;
	t_ll	nb;

	size = 1;
	nb = (t_ll)floa;
	*sign = floa < 0 ? 1 : 0;
	while (nb /= 10)
		size++;
	size += flags->comma == 1 ? (size - 1) / 3 : 0;
	return (size);
}

static int			ft_size_float(t_pf *fg, float floa, char *sign)
{
	fg->size = 0;
	fg->size += ft_digitlen(fg, floa, sign);
	if (fg->precis_val != 0)
		fg->size += 1;
	fg->size += fg->precis_val;
	if (*sign == 1 || fg->num_sign == 1 || fg->space == 1)
		fg->size += fg->width_val > fg->size ? 0 : 1;
	fg->size += fg->width_val > fg->size ? fg->width_val - fg->size : 0;
	return (fg->size);
}

char				*data_process_f(t_pf *flags, double floa)
{
	char	*str;
	int		size;
	char	sign;
	int		index;
	int		len;

	len = ft_digitlen(flags, floa, &sign);
	size = ft_size_float(flags, floa, &sign);
	if (flags->zero == 1 && flags->left_just == 0)
		str = ft_memset(ft_memalloc(size + 1), '0', size);
	else
		str = ft_memset(ft_memalloc(size + 1), ' ', size);
	index = size - (flags->precis_val + len + (flags->precis_val == 0 ? 0 : 1));
	flags->left_just == 1 ? index = 0 : 1;
	if (sign == 1 || flags->num_sign == 1 || flags->space == 1)
		index += flags->left_just == 1 ? 1 : 0;
	floa *= floa < 0 ? -1 : 1;
	ft_ftoa_uns(floa, &str[index], flags->comma, flags->precis_val);
	if (flags->space == 1 || sign == 1 || flags->num_sign == 1)
		str[0] = ' ';
	if (sign == 1 || flags->num_sign == 1)
		str = ft_sign(flags, str, sign);
	return (str);
}

char				*printf_float(t_pdata *print, t_pf *flags, va_list args)
{
	char	*str;
	double	dec;

	flags->precis_val = flags->precis == -1 ? 6 : flags->precis_val;
	dec = float_field_proc(print, flags, args);
	str = data_process_f(flags, dec);
	return (str);
}
