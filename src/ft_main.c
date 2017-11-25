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

static void	data_init(t_data *data, char **path)
{
	//struct winsize sz;

	data->opt_a = 0;
	data->opt_l = 0;
	data->opt_r = 0;
	data->opt_t = 0;
	data->opt_rec = 0;
	data->count = 0;
	*path = NULL;
	//ioctl(0, TIOCGWINSZ, &sz);
	data->width = 200;//sz.ws_col;
}

int	ft_size(t_data *data, char *name)
{
	if (data->size < (int)ft_strlen(name) && (data->opt_a || name[0] != '.'))
		data->size = ft_strlen(name);
	return (1);
}

static char		format_verif_ls(t_data *data, char **path, char *av)
{
	int	index;

	index = 0;
	if (av[index] == '-' && data->opt < 1 && av[index + 1])
	{
		while (av[++index])
		{
			if (!ft_option(data, av[index]))
				ft_error(&data, 1, &av[index]);
		}
		return (2);
	}
	else
	{
		data->opt += 1;
		*path = ft_strdup(av);
		return (1);
	}
	return (0);
}

int			main(int ac, char **av)
{
	char	*path;
	int		count;
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data) * 1);
	data_init(data, &path);
	count = 0;
	while (++count < ac)
		if (format_verif_ls(data, &path, av[count]) == 1)
		{
			if (stat(path, &data->file) != -1)
				ft_printf("%c%s%c\n", data->opt > 1 ? '\n' : 0, path, S_ISREG(data->file.st_mode) == 0 ? ':' : 0);
			ft_ls(data, path, ac);
			free (path);
		}
	data->opt == 0 ? ft_ls(data, ".", ac) : 1;
	free(data);
	return (0);
}
