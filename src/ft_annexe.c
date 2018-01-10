/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annexe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:48:27 by dbauduin          #+#    #+#             */
/*   Updated: 2017/11/22 16:54:48 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_count(char *path)
{
	int count;
	struct dirent	*dirent;
	DIR				*dir;

	count = 0;
	dir = opendir(path);
	while ((dirent = readdir(dir)))
		count++;
	closedir(dir);
	return (count);
}

char  ft_is_flag(char c)
{
	if (c == 'a' || c == 'l' || c == 'r' || c == 't' || c == 'R')
		return (1);
	return (0);
}

int ft_option(t_data *data, char c)
{
  if (!ft_is_flag(c))
    return (0);
  if (c == 'a')
    data->opt_a = 1;
  else if (c == 'l')
    data->opt_l = 1;
  else if (c == 'r')
    data->opt_r = 1;
  else if (c == 't')
    data->opt_t = 1;
  else if (c == 'R')
    data->opt_rec = 1;
  return (1);
}

char	*ft_tab(char *path, char *tab)
{
	char	*tmp;
	char	*s;

	s = NULL;
	tmp = ft_strjoin(path, "/");
	tmp = ft_strjoin(tmp, tab);
	s = tmp;
	free (tmp);
	return (s);
}

void		print_link(char *path)
{
	char	buff[1000];
	int		rd;

	if ((rd = readlink(path, buff, 1000)) > 0)
	{
		write(1, " -> ", 4);
		write(1, buff, rd);
	}
}
