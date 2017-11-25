/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_verif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 18:15:38 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/23 14:04:50 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		check_precis_norme(t_pf *flag, const char *str, int start, int end)
{
	int i;

	i = start + 1;
	flag->precis_val = 0;
	while (ft_isdigit(str[i]) && i < end)
	{
		flag->precis_val = (flag->precis_val * 10) + (str[i] - '0');
		i++;
	}
	if (i != start)
		flag->precis = 1;
	else
		flag->precis_val = -1;
	return (i);
}

int		check_precis(t_pf *fg, const char *str, int start, int end)
{
	int i;

	i = start;
	if (str[i] == '.')
	{
		if (str[++i] == '*')
		{
			fg->precis = 2;
			if (ft_isdigit(str[++i]))
			{
				fg->precis_wild = 0;
				fg->precis_val = 0;
				while (i < end && ft_isdigit(str[i]))
					fg->precis_wild = (fg->precis_wild * 10) + str[i++] - 48;
				if (str[i] == '$')
					return (i + 1);
				fg->precis_wild = -1;
				fg->precis_val = -1;
				return (-1);
			}
			return (i);
		}
		i = check_precis_norme(fg, str, start, end);
	}
	return (i);
}
