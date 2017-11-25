/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:31:25 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/22 22:09:39 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_precis(t_pf *flags, char *str, int size)
{
	int i;

	i = size - flags->precis_val + 1;
	if (flags->left_just == 1 && flags->width == 1)
		i = 0;
	if (flags->precis > 0 && flags->precis_val > 0)
		while (!ft_isalnum(str[i]) && str[i])
			str[i++] = '0';
	return (str);
}

char	*ft_sign(t_pf *flags, char *str, char sign)
{
	int i;

	i = 0;
	while (!ft_isdigit(str[i]) && str[i])
		i++;
	if ((str[i] == '\0' || i == 0) && (flags->num_sign == 1 || sign == 1))
		str[0] = sign == 1 ? '-' : '+';
	else
		str[--i] = sign == 1 ? '-' : '+';
	return (str);
}

char	*ft_num_type(char *str, int base, char maj)
{
	int	i;

	i = 0;
	while (!ft_isalnum(str[i]) && str[i])
		i++;
	i = i == 0 ? 2 : i;
	if (base == 16 && maj == 'x')
		ft_memmove(&str[i -= 2], "0x", 2);
	else if (base == 16 && maj == 'X')
		ft_memmove(&str[i -= 2], "0X", 2);
	else
		ft_memmove(&str[--i], "0", 1);
	return (str);
}

int		ft_position(t_pf *flags, int size, int len)
{
	int i;

	i = size - 1;
	if (flags->left_just == 1)
		i = flags->precis_val > (int)len ? flags->precis_val - 1 : len - 1;
	i += flags->num_type == 1 && (flags->flag == 'x' || flags->flag == 'X')\
		&& flags->left_just == 1 ? 2 : 0;
	i += flags->num_type == 1 && (flags->flag == 'o' || flags->flag == 'O')\
		&& flags->left_just == 1 ? 1 : 0;
	return (i);
}
