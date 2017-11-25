/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_man.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 18:09:52 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/22 20:41:58 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	flag_init(t_pf *flag)
{
	flag->left_just = 0;
	flag->num_sign = 0;
	flag->space = 0;
	flag->num_type = 0;
	flag->zero = 0;
	flag->comma = 0;
	flag->width = 0;
	flag->width_wild = -1;
	flag->width_val = -1;
	flag->precis = -1;
	flag->precis_wild = -1;
	flag->precis_val = -1;
	flag->length = 0;
	flag->flag = 0;
	flag->flag_arg = -1;
	flag->flag_arg_val = -1;
}

void		arg_man(va_list args, int i)
{
	int	j;

	j = -1;
	while (++j != i)
		va_arg(args, size_t);
}

char	*(*(g_param_event[21]))(t_pdata *print, t_pf *flag, va_list args) =
{
	printf_wchar,
	printf_int,
	printf_scientific,
	printf_float,
	printf_short_represent,
	printf_base,
	printf_wstring,
	printf_base,
	printf_base,
	printf_char,
	printf_int,
	printf_scientific,
	printf_float,
	printf_short_represent,
	printf_int,
	nothing_printed,
	printf_base,
	printf_address,
	printf_string,
	printf_base,
	printf_base,
};

int			func_man(t_pdata *print, t_pf *flag, va_list args)
{
	char	*str;
	int		i;
	char	count;

	i = 0;
	count = 65;
	if (flag->flag == '%')
		str = data_process_modulo(flag);
	else if (is_flag(flag->flag) == 0)
		str = char_data_process(flag, flag->flag);
	else
	{
		while (flag->flag != '%' && count < flag->flag)
			if (is_flag(count++) == 1)
				i++;
		str = (*g_param_event[i])(print, flag, args);
	}
	if (str)
		data_man(print, str, 0, flag->size);
	free(str);
	return (0);
}

int			flag_man(t_pdata **prt, t_temp *tp, const char *str, va_list args)
{
	int		nstart;
	t_pf	*flag;

	flag = (t_pf *)malloc(sizeof(t_pf) * 1);
	flag_init(flag);
	if (format_verif(&flag, str, tp, &nstart) == 1)
	{
		data_man(*prt, str, (*prt)->tstart, tp->start);
		(*prt)->tstart = (tp->start) + nstart + 1;
		func_man(*prt, flag, args);
		tp->flag = 0;
	}
	tp->flag = 0;
	free(flag);
	return (0);
}
