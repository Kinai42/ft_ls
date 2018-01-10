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
	printf("total %d\n", total);
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
			ft_print_opt_l(data, path, tab[i], (i == count - 1) ? 0 : 1);
		else if (data->opt_a || tab[i][0] != '.')
		{
		  if ((size += (data->size + 1)) >= (data->width - data->size))
			{
				printf("\n");
				size = 0;
			}
		  printf("%-*s", (data->size + 1), tab[i]);
		}
		data->opt_r ? i-- : i++;
	}
}

void	ft_print_opt_l(t_data *data, char *path, char *file, int n)
{
	char	*tmp;

	tmp = ft_strjoin(path, "/");
	tmp = ft_strjoin(tmp, file);
	lstat(tmp, &data->file);
	ft_print_rights(data);
	ft_print_time(data);
	printf("%s", file);
	print_link(tmp);
	printf("%s", n ? "\n" : "");
	free (tmp);
}

void	ft_print_rights(t_data *data)
{
	if (S_ISREG((*data).file.st_mode))
		printf("-");
	else if (S_ISDIR((*data).file.st_mode))
		printf("d");
	else if (S_ISCHR((*data).file.st_mode))
		printf("c");
	else if (S_ISBLK((*data).file.st_mode))
		printf("b");
	else if (S_ISFIFO((*data).file.st_mode))
		printf("p");
	else if (S_ISLNK((*data).file.st_mode))
		printf("l");
	else if (S_ISSOCK((*data).file.st_mode))
		printf("s");
	printf("%s", (*data).file.st_mode & S_IRUSR ? "r" : "-");
	printf("%s", (*data).file.st_mode & S_IWUSR ? "w" : "-");
	printf("%s", (*data).file.st_mode & S_IXUSR ? "x" : "-");
	printf("%s", (*data).file.st_mode & S_IRGRP ? "r" : "-");
	printf("%s", (*data).file.st_mode & S_IWGRP ? "w" : "-");
	printf("%s", (*data).file.st_mode & S_IXGRP ? "x" : "-");
	printf("%s", (*data).file.st_mode & S_IROTH ? "r" : "-");
	printf("%s", (*data).file.st_mode & S_IWOTH ? "w" : "-");
	printf("%s", (*data).file.st_mode & S_IXOTH ? "x" : "-");
}

void	ft_print_time(t_data *data)
{
	char			*tmp;
	struct passwd	*pwd;
	struct group	*grp;

	tmp = ctime(&data->file.st_mtime);
	pwd = getpwuid(data->file.st_uid);
	grp = getgrgid(data->file.st_gid);
	printf(" %4hu", data->file.st_nlink);
	printf(" %5s	%5s", pwd->pw_name, grp->gr_name);
	printf(" %8lld", data->file.st_size);
	printf(" %-14.12s", &tmp[4]);
}
