/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:56:29 by dbauduin          #+#    #+#             */
/*   Updated: 2017/11/22 16:57:00 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_total(t_data *data, char *path, char **tab)
{
	static int		total;
	int		i;
	char	*s;
	int		count;

	total = 0;
	i = 0;
	count = data->count;
	while (i < count && i >= 0)
	{
		s = ft_strdup(path);
		s = ft_strjoin(s, "/");
		s = ft_strjoin(s, tab[i++]);
		lstat(s, &data->file);
		total += data->file.st_blocks;
		free(s);
	}
	ft_printf("total %d\n", total);
}

void  ft_print(t_data *data, char *path, char **tab)
{
	int	i;
	int	count;
	int	size;

	count = data->count;
	i = data->opt_r ? data->count - 1 : 0;
	size = -data->size;
	data->opt_rec ? ft_printf("%s:\n",  path) : 1;
	data->opt_l ? print_total (data, path, tab) : 1;
	while (i < count && i >= 0)
	{
		if (data->opt_l && (data->opt_a || tab[i][0] != '.'))
			ft_print_opt_l(data, path, tab[i]);
		else if (data->opt_a || tab[i][0] != '.')
		{
		  if ((size += (data->size + 1)) >= (data->width - data->size))
			{
				write(1, "\n", 1);
				size = 0;
			}
		  ft_printf("%-*s", (data->size + 1), tab[i]);
		}
		data->opt_r ? i-- : i++;
	}
		!data->opt_l ? write(1,"\n", 1) : 1;
}

void	ft_print_opt_l(t_data *data, char *path, char *file)
{
	char	*tmp;

	tmp = ft_strjoin(path, "/");
	tmp = ft_strjoin(tmp, file);
	lstat(tmp, &data->file);
	ft_print_rights(data);
	ft_print_time(data);
	ft_printf("%s", file);
	print_link(tmp);
	write(1, "\n", 1);
	free (tmp);
}

void	ft_print_rights(t_data *data)
{
	if (S_ISREG((*data).file.st_mode))
		write(1, "-", 1);
	else if (S_ISDIR((*data).file.st_mode))
		write(1, "d", 1);
	else if (S_ISCHR((*data).file.st_mode))
		write(1, "c", 1);
	else if (S_ISBLK((*data).file.st_mode))
		write(1, "b", 1);
	else if (S_ISFIFO((*data).file.st_mode))
		write(1, "p", 1);
	else if (S_ISLNK((*data).file.st_mode))
		write(1, "l", 1);
	else if (S_ISSOCK((*data).file.st_mode))
		write(1, "s", 1);
	write(1, (*data).file.st_mode & S_IRUSR ? "r" : "-", 1);
	write(1, (*data).file.st_mode & S_IWUSR ? "w" : "-", 1);
	write(1, (*data).file.st_mode & S_IXUSR ? "x" : "-", 1);
	write(1, (*data).file.st_mode & S_IRGRP ? "r" : "-", 1);
	write(1, (*data).file.st_mode & S_IWGRP ? "w" : "-", 1);
	write(1, (*data).file.st_mode & S_IXGRP ? "x" : "-", 1);
	write(1, (*data).file.st_mode & S_IROTH ? "r" : "-", 1);
	write(1, (*data).file.st_mode & S_IWOTH ? "w" : "-", 1);
	write(1, (*data).file.st_mode & S_IXOTH ? "x" : "-", 1);
}

void	ft_print_time(t_data *data)
{
	char			*tmp;
	struct passwd	*pwd;
	struct group	*grp;

	tmp = ctime(&data->file.st_mtime);
	pwd = getpwuid(data->file.st_uid);
	grp = getgrgid(data->file.st_gid);
	ft_printf(" %4hu", data->file.st_nlink);
	ft_printf(" %s	%s", pwd->pw_name, grp->gr_name);
	ft_printf(" %8lld", data->file.st_size);
	ft_printf(" %-14.12s", &tmp[4]);
}
