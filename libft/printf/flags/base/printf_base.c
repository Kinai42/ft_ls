/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:38:48 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/22 22:04:50 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	ft_digitlen_base(t_pf *flags, t_ll dec, char base)
{
	int	len;

	len = 1;
	while (dec /= base)
		len++;
	len += flags->comma == 1 ? (len - 1) / 3 : 0;
	return (len);
}

static int	ft_base(t_pf *flags)
{
	if (flags->flag == 'o' || flags->flag == 'O')
	{
		flags->comma = flags->flag;
		return (8);
	}
	else if (flags->flag == 'x' || flags->flag == 'X')
	{
		flags->comma = flags->flag;
		return (16);
	}
	else
		return (10);
}

static int	ft_size_base(t_pf *fg, t_ull dec, int base)
{
	t_ull	tmp;

	fg->size = 0;
	tmp = dec;
	fg->size += dec == 0 && fg->precis_val != 0 ? 1 : 0;
	while (tmp)
	{
		fg->size++;
		tmp /= base;
	}
	tmp = fg->num_type;
	if (fg->flag == 'u' || fg->flag == 'U')
		fg->size += fg->comma == 1 ? (fg->size - 1) / 3 : 0;
	if (fg->precis_val > fg->size || fg->width_val > fg->size || tmp == 1)
	{
		if (!(dec == 0 && fg->precis_val != 0))
		fg->size += tmp == 1 && (fg->flag == 'o' || fg->flag == 'O') ? 1 : 0;
		fg->size += fg->precis_val > fg->size ? fg->precis_val - fg->size : 0;
		fg->size += tmp == 1  && dec != 0 && base == 16 ? 2 : 0;
		fg->size += fg->width_val > fg->size ? fg->width_val - fg->size : 0;
	}
	return (fg->size);
}

static char	*data_process(t_pf *flags, t_ll dec)
{
	char				*str;
	int					size;
	int					i;
	int					base;
	unsigned int		len;

	base = ft_base(flags);
	len = ft_digitlen_base(flags, dec, base);
	size = ft_size_base(flags, dec, base);
	if (flags->zero == 1 && flags->left_just == 0 && flags->precis == -1)
		str = ft_memset(ft_memalloc(size + 1), '0', size);
	else
		str = ft_memset(ft_memalloc(size + 1), ' ', size);
	i = ft_position(flags, size, len);
	if (dec != 0 || flags->precis_val != 0 || (flags->num_type == 1 &&\
		(flags->flag == 'o' || flags->flag == 'O')))
		ft_itoabase_uns(dec, base, flags->comma, &str[i]);
	if (flags->precis_val > 0)
		str = ft_precis(flags, str, size - 1);
	if (flags->num_type == 1 && !(flags->flag == 'u' || flags->flag == 'U'))
		str = dec != 0 ? ft_num_type(str, base, flags->flag) : str;
	return (str);
}

char		*printf_base(t_pdata *print, t_pf *flags, va_list args)
{
	char	*str;
	t_ull	dec;

	print->length = flags->length;
	print->length = flags->flag < 'X' ? 108 : print->length;
	dec = base_field_proc(print, flags, args);
	if (print->length == 208)
			return (str = data_process(flags, flags->flag >= 'a' ||\
				flags->flag == 'X'? (unsigned char)dec : (unsigned short)dec));
	else if (print->length == 104)
			return (str = data_process(flags, (unsigned short)dec));
	return (str = data_process(flags, dec));
}
