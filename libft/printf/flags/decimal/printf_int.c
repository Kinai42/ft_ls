/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:04:22 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/22 22:07:49 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static unsigned int	ft_digitlen(t_pf *flags, t_ll dec, char *sign)
{
	int	size;

	size = 1;
	*sign = dec < 0 ? 1 : 0;
	while (dec /= 10)
		size++;
	size += flags->comma == 1 ? (size - 1) / 3 : 0;
	return (size);
}

static int			ft_size(t_pf *fg, t_ll dec, char *sign)
{
	fg->size = 0;
	if (fg->precis_val != 0)
		fg->size += dec == 0 ? 1 : 0;
	while (dec)
	{
		fg->size++;
		dec /= 10;
	}
	fg->size += fg->comma == 1 ? (fg->size - 1) / 3 : 0;
	if (fg->precis_val > fg->size || fg->width_val > fg->size ||\
			*sign == 1 || fg->num_sign == 1 || fg->space == 1)
	{
		fg->size += fg->precis_val > fg->size ? fg->precis_val - fg->size : 0;
		if (*sign == 1 || fg->num_sign == 1 || fg->space == 1)
			fg->size += fg->width_val > fg->size ? 0 : 1;
		fg->size += fg->width_val > fg->size ? fg->width_val - fg->size : 0;
	}
	return (fg->size);
}

static char			*data_process(t_pf *flags, t_ll dec)
{
	char	*str;
	int		size;
	char	sign;
	t_ll	len;

	len = ft_digitlen(flags, dec, &sign);
	size = ft_size(flags, dec, &sign);
	if (flags->zero == 1 && flags->left_just == 0 && flags->precis == -1)
		str = ft_memset(ft_memalloc(size + 1), '0', size);
	else
		str = ft_memset(ft_memalloc(size + 1), ' ', size);
	size -= 1;
	if (flags->left_just == 1)
		size = flags->precis_val > (int)len ? flags->precis_val - 1 : len - 1;
	if (sign == 1 || flags->num_sign == 1 || flags->space == 1)
		size += flags->left_just == 1 ? 1 : 0;
	len = dec < 0 ? (t_ll)(dec * -1) : (t_ll)dec;
	if (dec != 0 || flags->precis_val != 0)
		ft_itoabase_uns((t_ll)len, 10, flags->comma, &str[size]);
	if (flags->precis > 0 && flags->precis_val > 0)
		str = ft_precis(flags, str, size);
	flags->space == 1 ? str[0] = ' ' : 1;
	if (sign == 1 || flags->num_sign == 1)
		str = ft_sign(flags, str, sign);
	return (str);
}

char				*printf_int(t_pdata *print, t_pf *flags, va_list args)
{
	char	*str;
	t_ll	dec;

	print->length = flags->length;
	if (flags->flag == 'D')
		print->length = 108;
	dec = int_field_proc(print, flags, args);
	if (print->length == 208)
		str = data_process(flags, (char)dec);
	else if (print->length == 104)
		str = data_process(flags, (short)dec);
	else
		str = data_process(flags, dec);
	return (str);
}
