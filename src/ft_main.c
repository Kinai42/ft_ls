/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:22:01 by dbauduin          #+#    #+#             */
/*   Updated: 2018/02/01 14:51:39 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/ioctl.h>

void	data_init(t_data *data)
{
	struct winsize sz;

	data->opt_a = 0;
	data->opt_g = 0;
	data->opt_l = 0;
	data->opt_r = 0;
	data->opt_t = 0;
	data->opt_rec = 0;
	data->arg = 0;
	ioctl(0, TIOCGWINSZ, &sz);
	data->width = sz.ws_col;
}

int		ft_size(t_data *data, char *name)
{
	if (data->size < (int)ft_strlen(name) && (data->opt_a || name[0] != '.'))
		data->size = ft_strlen(name);
	return (1);
}

int		main(int ac, char **av)
{
	int		index;
	int		arg;
	t_data	data[1];

	data_init(data);
	ac > 1 ? format_verif_ls(data, av, ac) : 1;
	index = 0;
	arg = 1;
	while (av[++index] && data->arg)
	{
		if (stat(av[index], &data->file) != -1 && (data->file.st_mode & S_IRGRP
					|| S_ISREG(data->file.st_mode)))
		{
			if (data->arg > 1 && S_ISDIR(data->file.st_mode))
				ft_printf("%s :\n", av[index]);
			ft_ls(data, av[index], S_ISDIR(data->file.st_mode) ? 1 : 0);
			if (arg < data->arg)
				ft_printf("\n");
		}
		if (av[index][0] != '-')
			arg++;
	}
	if (!data->arg)
		ft_ls(data, ".", 1);
	return (0);
}
