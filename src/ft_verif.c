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
		ft_printf("ls: illegal option -- %c\nusage: ls [-Ralrt] [file ...]\n", *path);
		exit (0);
	}
  if (index == 2 && path)
		ft_printf("ls: %s: No such file or directory\n", path);
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
    if (stat(av[index], &data->file) == -1)
			 ft_error(2, av[index]);
		data->arg++;
    index++;
	}
	return (0);
}

char	*ft_color_file(char *path, char *file)
{
	struct stat sb;
	char	*tmp;

	tmp = ft_strjoin(path, "/");
	tmp = ft_strjoin(tmp, file);
	lstat(tmp, &sb);
	free (tmp);
	if (S_ISLNK(sb.st_mode))
		return(CYAN);
	if (S_ISDIR(sb.st_mode))
			return(BLUE);
	if (sb.st_mode & S_IXUSR)
		return(GREEN);
	if (S_ISSOCK(sb.st_mode))
			return(VIOLET);
	if (S_ISBLK(sb.st_mode) || S_ISFIFO(sb.st_mode))
			return(YELLOW);
	return(DEFAULT);
}
