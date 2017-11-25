/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_shortest_representation.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:40:17 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/22 22:27:23 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static t_ll	iterative_power(float nb, int power)
{
	int tmp;

	tmp = nb;
	if (power == 0 || nb == 1)
	{
		return (1);
	}
	else if (power < 0 || nb == 0)
	{
		return (0);
	}
	while (power > 1)
	{
		nb = nb * tmp;
		power--;
	}
	return (nb);
}

static char	*data_process(t_pf *flags, double floa, char *str)
{
	int		expo;
	double	tmp;
	t_ll	int_tmp;
	int		len;

	expo = 0;
	tmp = floa < 0 ? floa * -1 : floa;
	while ((tmp < 1 || tmp >= 10) && floa != 0.)
	{
		expo += tmp < 1 ? -1 : 1;
		tmp *= tmp < 1 ? 10 : 0.1;
	}
	int_tmp = tmp * iterative_power(10, flags->precis_val);
	len = 1;
	while ((int_tmp /= 10) % 10 == 0)
		len++;
	if (expo < -4 || expo >= flags->precis_val)
	{
		flags->precis_val -= len;
		str = data_process_e(flags, floa);
		return (str);
	}
	flags->precis_val = flags->precis_val - (expo + 1);
	str = data_process_f(flags, floa);
	return (str);
}

char		*printf_short_represent(t_pdata *print, t_pf *flags, va_list args)
{
	char	*str;
	double	floa;

	str = NULL;
	flags->precis_val = flags->precis == -1 ? 6 : flags->precis_val;
	flags->precis_val = flags->precis_val == 0 ? 1 : flags->precis_val;
	floa = float_field_proc(print, flags, args);
	str = data_process(flags, floa, str);
	return (str);
}
