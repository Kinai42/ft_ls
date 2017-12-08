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

int	ft_swap2(char **s1, char **s2)
{
	char *tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
	return (1);
}

void  sort_param_opt(t_data *data, char **tab, char *path)
{
	int	i;
	int	power;
	char	*s;
	struct stat buf;
	struct stat buf2;

	power = 1;
	while (power)
	{
		power = 0;
		i = -1;
		while (++i < data->count - 1)
		{
			if (data->opt_t)
			{
				lstat((s = ft_tab(path, tab[i])), &buf);
				free (s);
				lstat((s = ft_tab(path, tab[i + 1])), &buf2);
				free (s);
			}
			if (data->opt_t ? buf.st_mtime < buf2.st_mtime : (ft_strcmp(tab[i], tab[i + 1]) > 0))
				power = ft_swap2(&tab[i], &tab[i + 1]);
		}
	}
}

void  ft_ls(t_data *data, char *path, int ac)
{
	struct dirent	*dirent;
	DIR				*dir;
	char			**tab;
	int				i;

	i = 0;
	data->count = 0;
	data->size = 0;
	if (!(dir = opendir(path)) && !stat(path, &data->file))
		return (S_ISREG(data->file.st_mode) ? 0 : (ft_error(2, path)));
	while ((dirent = readdir(dir)))
		data->count++;
	closedir(dir);
	tab = (char **)malloc(sizeof(char *) * data->count);
	dir = opendir(path);
	while ((dirent = readdir(dir)))
		if (ft_size(data, dirent->d_name))
			tab[i++] = ft_strdup(dirent->d_name);
	sort_param_opt(data, tab, path);
	ft_print(data, path, tab);
	if (data->opt_rec)
		data->opt_r ? ft_rev(data, path, tab, ac) : ft_normal(data, path, tab, ac);
	closedir(dir);
	free (tab);
	free (dirent);
}

void ft_normal(t_data *data, char *path, char **tab, int ac)
{
	char	*tmp;
	int		i;
	int count;

	i = -1;
	count = data->count;
	while (++i < count)
	{
		tmp = ft_strdup(path);
		tmp = ft_strjoin(tmp, "/");
		tmp = ft_strjoin(tmp, tab[i]);
		lstat(tmp, &data->file);
		if (S_ISDIR(data->file.st_mode) && !(S_ISLNK(data->file.st_mode)))
			if ((tab[i][0] != '.' || data->opt_a) && tab[i][1] && tab[i][1] != '.')
			{
				write(1, "\n", 1);
				ft_ls(data, tmp, ac);
			}
		free(tmp);
	}
}

void ft_rev(t_data *data, char *path, char **tab, int ac)
{
	char	*tmp;
	int		i;

	i = data->count;
	while (--i >= 0)
	{
		tmp = ft_strdup(path);
		tmp = ft_strjoin(path, "/");
		tmp = ft_strjoin(tmp, tab[i]);
		lstat(tmp, &data->file);
		if (S_ISDIR(data->file.st_mode) && !(S_ISLNK(data->file.st_mode)))
			if ((tab[i][0] != '.' || data->opt_a) && tab[i][1] && tab[i][1] != '.')
			{
				write(1, "\n", 1);
				ft_ls(data, tmp, ac);
			}
		free(tmp);
	}
}
