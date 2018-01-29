/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_uns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 16:26:17 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/22 22:31:31 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_uns_int_len(unsigned long long int nb, char comma)
{
	int len;

	len = 1;
	while (nb /= 10)
		len++;
	len += comma == 1 ? (len - 1) / 3 : 0;
	return (len);
}

void		ft_ftoa_uns(double floa, unsigned char *str, char comma, int precis_val)
{
	t_ull		i_part;
	long double	f_part;
	int			i;

	i_part = (unsigned long long int)floa;
	f_part = floa - (long double)i_part;
	i = ft_uns_int_len(i_part, comma) - 1;
	//ft_itoabase_uns(i_part, 10, comma, &str[i]);
	if (precis_val != 0)
	{
		str[++i] = '.';
		while (precis_val-- > 0)
		{
			i_part = (unsigned long long)(f_part *= 10);
			str[++i] = f_part + '0';
			f_part -= (long double)i_part;
		}
	}
	if ((int)(f_part * 10) % 10 > 4)
	{
		while (str[i] == '9' || str[i] == '.')
			str[i] == '9' ? str[i--] = '0' : str[i--];
		str[i] += 1;
	}
}
