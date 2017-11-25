/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samad <samad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 05:09:29 by samad             #+#    #+#             */
/*   Updated: 2017/10/24 18:21:48 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	data_init(t_pdata *print, t_temp *temp)
{
	print->len = 0;
	print->flags = 0;
	print->tstart = 0;
	print->tend = 0;
	temp->i = -1;
	temp->flag = 0;
	temp->start = 0;
	temp->end = 0;
	temp->count = 0;
}

static void	ft_is_modulo(t_temp *temp)
{
	temp->flag = 1;
	temp->start = temp->i;
}

static char	ft_while(const char *str, t_temp *tp, va_list args, t_pdata *print)
{
	va_list	args_cpy;

	if (tp->flag > 0)
	{
		tp->count += (tp->flag = is_flag(str[tp->i]));
		if (tp->count >= 0 && ((tp->flag == 1 || tp->flag == 0) || str[tp->i + 1] == '\0'))
		{
			va_copy(args_cpy, args);
			flag_man(&print, tp, str, args_cpy);
			va_end(args_cpy);
			tp->i += (str[tp->i] == '%' && str[tp->i + 1] != '\0') ? 1 : 0;
		}
	}
	if (str[tp->i] == '%')
		ft_is_modulo(tp);
	return (str[tp->i]);
}

int			ft_printf(const char *str, ...)
{
	va_list	args;
	t_pdata	*print;
	t_temp	temp;

	print = (t_pdata *)malloc(sizeof(t_pdata) * 1);
	va_start(args, str);
	data_init(print, &temp);
	while (str[++temp.i])
		ft_while(str, &temp, args, print);
	print->tend = temp.i;
	if (str[temp.i] != '0' && str[(temp.i) - 1] != '%')
		data_man(print, str, print->tstart, print->tend);
	va_end(args);
	free(print);
	return (print->len);
}
