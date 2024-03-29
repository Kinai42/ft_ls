/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:02:41 by dbauduin          #+#    #+#             */
/*   Updated: 2018/01/29 15:03:27 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

char	*ft_cast_int(char s, va_list ap, long long *f)
{
	if (*f >> 7 & 1)
		return (ft_con_int(va_arg(ap, long long), f));
	if ((*f >> 8 & 1) || s == 'D')
		return (ft_con_int(va_arg(ap, long), f));
	if (*f >> 9 & 1)
		return (ft_con_int(va_arg(ap, intmax_t), f));
	if (*f >> 10 & 1)
		return (ft_con_int(va_arg(ap, size_t), f));
	if (*f >> 6 & 1)
		return (ft_con_int((short)va_arg(ap, int), f));
	if (*f >> 5 & 1)
		return (ft_con_int((signed char)va_arg(ap, int), f));
	return (ft_con_int(va_arg(ap, int), f));
}

char	*ft_cast_uns(char s, va_list ap, long long *f)
{
	if (*f >> 7 & 1)
		return (ft_con_uns(s, va_arg(ap, unsigned long long), f));
	if ((*f >> 8 & 1) || s == 'U' || s == 'O')
		return (ft_con_uns(s, va_arg(ap, unsigned long), f));
	if (*f >> 9 & 1)
		return (ft_con_uns(s, va_arg(ap, uintmax_t), f));
	if (*f >> 10 & 1)
		return (ft_con_uns(s, va_arg(ap, size_t), f));
	if (*f >> 6 & 1)
		return (ft_con_uns(s, (unsigned short)va_arg(ap, unsigned int), f));
	if (*f >> 5 & 1)
		return (ft_con_uns(s, (unsigned char)va_arg(ap, unsigned int), f));
	return (ft_con_uns(s, va_arg(ap, unsigned int), f));
}

char	*ft_cast_flo(va_list ap, long long *f)
{
	return (ft_ftoa(va_arg(ap, double), f));
}

char	*ft_cast_str(char s, va_list ap)
{
	char	*c;

	c = 0;
	if (s == 's')
		return (va_arg(ap, char*));
	if (s == 'c' && (c = ft_strnew(1)))
	{
		*c = va_arg(ap, int);
		return (c);
	}
	return (0);
}
