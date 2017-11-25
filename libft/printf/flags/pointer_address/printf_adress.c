/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_adress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 22:20:56 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/22 22:25:55 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static unsigned int	ft_digitlen_adress(t_ll n, char base)
{
	int	size;

	size = 1;
	while (n /= base)
		size++;
	return (size);
}

static int			ft_size_address(t_pf *flags, int len, t_ll dec)
{
	flags->size = 0;
		flags->size = (flags->precis_val == 0  && dec == 0) ? 0 : len;
	flags->size += flags->precis_val > flags->size ?\
			flags->precis_val - flags->size : 0;
	flags->size += flags->width_val > (flags->size + 2)?\
			flags->width_val - flags->size : 2;
	return (flags->size);
}

static char			*data_process(t_pf *flags, void *adress)
{
	char	*str;
	int		size;
	int		i;
	int		len;

	len = ft_digitlen_adress((t_ll)adress, 16);
	size = ft_size_address(flags, len, (t_ll)adress);
	if (flags->zero == 1 && flags->left_just == 0 && flags->precis == -1)
		str = ft_memset(ft_memalloc(size + 1), '0', size);
	else
		str = ft_memset(ft_memalloc(size + 1), ' ', size);
	i = size - 1;
	if (flags->left_just == 1)
		i = flags->precis_val > len ? flags->precis_val - 1 + 2 : len - 1 + 2;
	if (!(adress == 0 && flags->precis_val == 0)){
		ft_itoabase_uns((t_ll)adress, 16, flags->flag, &str[i]);
	}
	if (flags->precis_val > 0)
		str = ft_precis(flags, str, size - 1);
	i = 2;
	while (!ft_isdigit(str[i]) && flags->left_just != 1 && str[i])
		i++;
	ft_memmove(&str[i -= 2], "0x", 2);
	return (str);
}

char				*printf_address(t_pdata *print, t_pf *flags, va_list args)
{
	char *str;
	void *addr;

	addr = address_field_proc(print, flags, args);
	str = data_process(flags, addr);
	return (str);
}
