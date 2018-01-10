/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:54:55 by dbauduin          #+#    #+#             */
/*   Updated: 2017/11/22 16:55:37 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void  ft_error(char index, char *path)
{
	if (index == 1)
	{
		printf("ls: illegal option -- %c\nusage: ls [-Ralrt] [file ...]\n", *path);
		exit (0);
	}
  if (index == 2)
		printf("ls: %s: No such file or directory\n", path);
}

int		format_verif_ls(t_data *data, char **av, int ac)
{
	int	index;
  int i;

	index = 0;
	while (++index < (ac) && av[index][0] == '-')
  {
    i = 1;
    while (av[index][i])
    {
      if (!ft_option(data, av[index][i]))
        ft_error(1, &av[index][i]);
      i++;
    }
  }
  while (index < (ac) && av[index])
	{
    stat(av[index], &data->file);
		if (!(S_ISDIR(data->file.st_mode)) && !(S_ISREG(data->file.st_mode)))
      ft_error(2, av[index]);
    index++;
    data->arg++;
	}
	return (0);
}
