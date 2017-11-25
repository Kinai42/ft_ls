/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_scientific.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:35:15 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/22 22:26:31 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int		ft_size_scientific(t_pf *flags, float floa, char *sign)
{
	flags->size = 0;
	flags->size += 1;
	if (flags->precis_val != 0)
		flags->size += 1;
	flags->size += flags->precis_val;
	*sign = floa < 0 ? 1 : 0;
	if (*sign == 1 || flags->num_sign == 1 || flags->space == 1)
		flags->size += flags->width_val > flags->size ? 0 : 1;
	flags->size += 4;
	flags->size += flags->width_val > flags->size ?\
		flags->width_val - flags->size : 0;
	return (flags->size);
}

static char		*ft_exposant(t_pf *flags, double floa, char *str, int size)
{
	int	index;
	int	len;

	index = size - 1;
	len = 1;
	while (!ft_isdigit(str[index]) && str[index])
		index--;
	str[++index] = flags->flag >= 'a' ? 'e' : 'E';
	str[++index] = floa >= 1 || floa == 0 ? '+' : '-';
	floa *= floa < 0 ? -1 : 1;
	while ((floa < 1 || floa >= 10) && floa != 0)
	{
		len += 1;
		floa *= floa < 1 ? 10 : 0.1;
	}
	len--;
	str[index += 2] = len % 10 + '0';
	str[--index] = len / 10 >= 9 ? 9 + '0' : len / 10 + '0';
	return (str);
}

char			*data_process_e(t_pf *flags, double floa)
{
	char	*str;
	int		size;
	char	sign;
	int		index;
	double	tmp;

	tmp = floa < 0 ? floa * -1 : floa * 1;
	size = ft_size_scientific(flags, floa, &sign);
	if (flags->zero == 1 && flags->left_just == 0)
		str = ft_memset(ft_memalloc(size + 1), '0', size);
	else
		str = ft_memset(ft_memalloc(size + 1), ' ', size);
	index = size - (flags->precis_val + (flags->precis_val == 0 ? 5 : 6));
	flags->left_just == 1 ? index = 0 : 1;
	if (sign == 1 || flags->num_sign == 1 || flags->space == 1)
		index += flags->left_just == 1 ? 1 : 0;
	while ((tmp < 1 || tmp >= 10) && floa != 0)
		tmp *= tmp < 1 ? 10 : 0.1;
	ft_ftoa_uns(tmp, &str[index], 0, flags->precis_val);
	if (flags->space == 1 || sign == 1 || flags->num_sign == 1)
		str[0] = ' ';
	if (sign == 1 || flags->num_sign == 1)
		str = ft_sign(flags, str, sign);
	str = ft_exposant(flags, floa, str, size);
	return (str);
}

char			*printf_scientific(t_pdata *print, t_pf *flags, va_list args)
{
	char	*str;
	double	dec;

	flags->precis_val = flags->precis == -1 ? 6 : flags->precis_val;
	dec = scientific_field_proc(print, flags, args);
	str = data_process_e(flags, dec);
	return (str);
}
