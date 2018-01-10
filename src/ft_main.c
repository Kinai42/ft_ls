/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:13:50 by dbauduin          #+#    #+#             */
/*   Updated: 2017/11/22 17:14:58 by dbauduin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ls.h"
#include <sys/ioctl.h>

static void	data_init(t_data *data)
{
	struct winsize sz;

	data->opt_a = 0;
	data->opt_l = 0;
	data->opt_r = 0;
	data->opt_t = 0;
	data->opt_rec = 0;
	data->arg = 0;
	ioctl(0, TIOCGWINSZ, &sz);
	data->width = sz.ws_col;
}

int	ft_size(t_data *data, char *name)
{
	if (data->size < (int)ft_strlen(name) && (data->opt_a || name[0] != '.'))
		data->size = ft_strlen(name);
	return (1);
}

int			main(int ac, char **av)
{
	int		index;
	int		arg;
	t_data data[1];

	data_init(data);
	if (ac > 1)
		format_verif_ls(data, av, ac);
	index = 0;
	arg = 1;
	while (av[++index] && data->arg)
		{
			if (av[index][0] != '-')
				{
					stat(av[index], &data->file);
					if (data->arg > 1 && S_ISDIR(data->file.st_mode))
						printf("%s :\n", av[index]);
					ft_ls(data, av[index], S_ISDIR(data->file.st_mode) ? 1 : 0);
					if (arg++ < data->arg)
						printf("\n");
				}
		}
	if (!data->arg)
		ft_ls(data, ".", 1);
	printf("\n");
	return (0);
}
