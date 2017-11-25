/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_verif_lenth.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 14:11:50 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/23 14:11:54 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		check_lenth(t_pf *flag, const char *str, int start, int end)
{
	int i;

	i = start;
	end++;
	if (str[i + 1])
	{
		if ((str[i] == 'h' && str[i + 1] == 'h') || (str[i] == 'l' &&\
					str[i + 1] == 'l'))
		{
			flag->length = (str[i + 1] + str[i]);
			return (i + 2);
		}
	}
	if (str[i] == 'h' || str[i] == 'j' || str[i] == 'l' || str[i] == 'L' ||\
			str[i] == 't' || str[i] == 'z')
	{
		flag->length = str[i];
		return (++i);
	}
	return (i);
}
