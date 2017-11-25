/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_verif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 18:15:38 by dbauduin          #+#    #+#             */
/*   Updated: 2017/10/23 14:47:45 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		any_flag(t_pf *flag)
{
	if (flag->left_just == 1 || flag->num_sign == 1\
			|| flag->space == 1 || flag->num_type == 1\
			|| flag->zero == 1)
		return (1);
	return (0);
}

int		check_flag_arg(t_pf *flag, const char *str, int start, int end)
{
	int i;

	i = start;
	if (ft_isdigit(str[i]) && str[i] != '0')
	{
		flag->flag_arg_val = 0;
		while (i != end && ft_isdigit(str[i]))
		{
			flag->flag_arg_val = (flag->flag_arg_val * 10) + (str[i] - '0');
			i++;
		}
		if (str[i] == '$')
		{
			flag->flag_arg = 1;
			return (i + 1);
		}
		else
			flag->flag_arg_val = -1;
	}
	return (start);
}

int		check_flag(t_pf *flag, const char *str, int start, int end)
{
	int i;

	i = start;
	while (str[i] && i != end)
	{
		if (str[i] == '-')
			flag->left_just = 1;
		else if (str[i] == '+')
			flag->num_sign = 1;
		else if (str[i] == ' ')
			flag->space = 1;
		else if (str[i] == '#')
			flag->num_type = 1;
		else if (str[i] == '0')
			flag->zero = 1;
		else if (str[i] == 39)
			flag->comma = 1;
		else
			return (i);
		i++;
	}
	return (i);
}

int		format_verif(t_pf **flag, const char *str, t_temp *tp, int *len)
{
	int	i;
	int	end;

	i = tp->start + 1;
	end = tp->i;
	i = check_flag_arg(*flag, str, i, end);
	i = check_flag(*flag, str, i, end);
	i = check_width(*flag, str, i, end);
	i = check_flag_arg(*flag, str, i, end);
	i = check_precis(*flag, str, i, end);
	i = check_lenth(*flag, str, i, end);
	if (is_flag(str[i]) == 1 || is_flag(str[i]) == 0)
	{
		(*flag)->flag = str[i];
		*len = (i - (tp->start + 1)) + 1;
		return (1);
	}
	return (0);
}
