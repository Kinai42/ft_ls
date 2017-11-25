/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_verif_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 14:07:17 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/23 14:07:19 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		check_width_r(t_pf *flag, const char *str, int start, int end)
{
	int i;

	i = start;
	flag->width_val = 0;
	while (i < end && ft_isdigit(str[i]))
	{
		flag->width_val = (flag->width_val * 10) + (str[i] - '0');
		i++;
	}
	if (i != start || flag->width_val)
		flag->width = 1;
	else
		flag->width_val = -1;
	return (i);
}

int		check_width(t_pf *flag, const char *str, int start, int end)
{
	int i;

	i = start;
	if (str[i] == '*')
	{
		flag->width = 2;
		i++;
		if (ft_isdigit(str[i]))
		{
			flag->width_wild = 0;
			flag->width_val = 0;
			while (i < end && ft_isdigit(str[i]))
			{
				flag->width_wild = (flag->width_wild * 10) + (str[i] - '0');
				i++;
			}
			if (str[i] == '$')
				return (i + 1);
			flag->width_wild = -1;
			flag->width_val = -1;
			return (-1);
		}
		return (i);
	}
	return (check_width_r(flag, str, start, end));
}
