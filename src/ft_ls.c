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

void  sort_param_opt(t_data *data, char **tab, char *path, int count)
{
	int	i;
	int	power;
	struct stat buf;
	struct stat buf2;

	power = 1;
	while (power)
	{
		power = 0;
		i = -1;
		while (++i < (count - 1))
		{
			if (data->opt_t)
			{
				lstat((ft_tab(path, tab[i])), &buf);
				lstat((ft_tab(path, tab[i + 1])), &buf2);
			}
			if (data->opt_t ? buf.st_mtime < buf2.st_mtime : (ft_strcmp(tab[i], tab[i + 1]) > 0))
				power = ft_swap2(&tab[i], &tab[i + 1]);
		}
	}
}

void  ft_ls(t_data *data, char *path, int dof)
{
	struct dirent	*dirent;
	DIR				*dir;
	char			**tab;
	int				count;
	int				i;

	data->size = 0;
	if (dof == 0)
		printf("%s\n", path);
	else
	{
		i = 0;
		tab = (char **)malloc(sizeof(char *) * (count = ft_count(path)));
		dir = opendir(path);
		while ((dirent = readdir(dir)))
			if (ft_size(data, dirent->d_name))
				tab[i++] = ft_strdup(dirent->d_name);
		sort_param_opt(data, tab, path, count);
		ft_print(data, path, tab, count);
		if (data->opt_rec)
			data->opt_r ? ft_rev(data, path, tab, count) : ft_normal(data, path, tab, count);
		closedir(dir);
		free (tab);
	}
}

void ft_normal(t_data *data, char *path, char **tab, int count)
{
	char	*tmp;
	int		i;

	i = -1;
	while (++i < count)
	{
		tmp = ft_strdup(path);
		tmp = ft_strjoin(tmp, "/");
		tmp = ft_strjoin(tmp, tab[i]);
		lstat(tmp, &data->file);
		if (S_ISDIR(data->file.st_mode) && !(S_ISLNK(data->file.st_mode)))
			if ((((tab[i][0] != '.' || data->opt_a) && tab[i][1]) || tab[i][0] != '.') && tab[i][1] != '.')
			{
				printf("%s", !data->opt_l ? "\n" : "");
				printf("\n%s:%s", tmp, count > 2 ? "\n" : "");
				ft_ls(data, tmp, 1);
			}
		free(tmp);
	}
}

void ft_rev(t_data *data, char *path, char **tab, int count)
{
	char	*tmp;

	while (--count >= 0)
	{
		tmp = ft_strdup(path);
		tmp = ft_strjoin(path, "/");
		tmp = ft_strjoin(tmp, tab[count]);
		lstat(tmp, &data->file);
		if (S_ISDIR(data->file.st_mode) && !(S_ISLNK(data->file.st_mode)))
			if ((((tab[i][0] != '.' || data->opt_a) && tab[i][1]) || tab[i][0] != '.') && tab[i][1] != '.')
			{
				printf("%s", !data->opt_l ? "\n" : "");
				printf("\n%s:%s", tmp, count > 2 ? "\n" : "");
				ft_ls(data, tmp, 1);
			}
		free(tmp);
	}
}
