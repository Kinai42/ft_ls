/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:56:29 by dbauduin          #+#    #+#             */
/*   Updated: 2018/01/17 10:01:23 by Damien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_total(t_data *data, char *path, char **tab, int count)
{
	static int		total;
	int		i;
	char	*s;

	total = 0;
	i = -1;
	while (++i < count)
	{
		s = ft_strdup(path);
		s = ft_strjoin(s, "/");
		s = ft_strjoin(s, tab[i]);
		lstat(s, &data->file);
		total += data->file.st_blocks;
		free(s);
	}
	ft_printf("total %d\n", total);
}

void  ft_print(t_data *data, char *path, char **tab, int count)
{
	int	i;
	int	size;

	i = data->opt_r ? count - 1 : 0;
	size = -data->size;
	data->opt_l ? print_total(data, path, tab, count) : 1;
	while (i < count && i >= 0)
	{
		if (data->opt_l && (data->opt_a || tab[i][0] != '.'))
			ft_print_opt_l(data, path, tab[i]);
		else if (data->opt_a || tab[i][0] != '.')
		{
		  if ((size += (data->size + 1)) >= (data->width - data->size))
			{
				ft_printf("\n");
				size = 0;
			}
		  ft_printf("%s%-*s%s", data->opt_G == 1 ? ft_color_file(path, tab[i]) : DEFAULT, (data->size + 1), tab[i], DEFAULT);
		}
		data->opt_r ? i-- : i++;
	}
	if ((count > 2 || data->opt_a) && !data->opt_l)
		ft_printf("\n");
}

void	ft_print_opt_l(t_data *data, char *path, char *file)
{
	char	*tmp;

	tmp = ft_strjoin(path, "/");
	tmp = ft_strjoin(tmp, file);
	lstat(tmp, &data->file);
	ft_print_rights(data);
	ft_print_time(data);
	ft_printf("%s%s%s", data->opt_G == 1 ? ft_color_file(path, file) : DEFAULT, file, DEFAULT);
	print_link(tmp);
	ft_printf("\n");
	free (tmp);
}

void	ft_print_rights(t_data *data)
{
	if (S_ISREG((*data).file.st_mode))
		ft_printf("-");
	else if (S_ISDIR((*data).file.st_mode))
		ft_printf("d");
	else if (S_ISCHR((*data).file.st_mode))
		ft_printf("c");
	else if (S_ISBLK((*data).file.st_mode))
		ft_printf("b");
	else if (S_ISFIFO((*data).file.st_mode))
		ft_printf("p");
	else if (S_ISLNK((*data).file.st_mode))
		ft_printf("l");
	else if (S_ISSOCK((*data).file.st_mode))
		ft_printf("s");
	ft_printf("%s", (*data).file.st_mode & S_IRUSR ? "r" : "-");
	ft_printf("%s", (*data).file.st_mode & S_IWUSR ? "w" : "-");
	ft_printf("%s", (*data).file.st_mode & S_IXUSR ? "x" : "-");
	ft_printf("%s", (*data).file.st_mode & S_IRGRP ? "r" : "-");
	ft_printf("%s", (*data).file.st_mode & S_IWGRP ? "w" : "-");
	ft_printf("%s", (*data).file.st_mode & S_IXGRP ? "x" : "-");
	ft_printf("%s", (*data).file.st_mode & S_IROTH ? "r" : "-");
	ft_printf("%s", (*data).file.st_mode & S_IWOTH ? "w" : "-");
	ft_printf("%s", (*data).file.st_mode & S_IXOTH ? "x" : "-");
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
	ft_printf(" %5s	%5s", pwd->pw_name, grp->gr_name);
	ft_printf(" %8lld", data->file.st_size);
	ft_printf(" %-14.12s", &tmp[4]);
}
