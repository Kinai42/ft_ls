/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbauduin <dbauduin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:32:37 by dbauduin          #+#    #+#             */
/*   Updated: 2018/02/01 14:45:57 by dbauduin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/include/printf.h"
# include "../libft/include/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/dir.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <sys/types.h>

# define DEFAULT "\e[38;5;252m"
# define GREEN "\e[38;5;82m"
# define RED "\e[38;5;196m"
# define ORANGE "\e[38;5;202m"
# define YELLOW "\e[38;5;226m"
# define BLUE "\e[38;5;69m"
# define CYAN "\e[38;5;123m"
# define WHITE "\e[38;5;15m"
# define BROWN "\e[38;5;202m"
# define VIOLET "\e[38;5;5m"
# define LEMON "\e[38;5;190m"

typedef struct		s_data
{
	int				opt;
	char			opt_a;
	char			opt_g;
	char			opt_l;
	char			opt_r;
	char			opt_t;
	char			opt_rec;
	int				size;
	int				arg;
	struct stat		file;
	char			time[12];
	int				width;
}					t_data;

int					main(int ac, char **av);
int					ft_option(t_data *data, char c);
void				ft_ls(t_data *data, char *path, int ac);
void				sort_parm_opt(t_data *data, char **tab, char *path);
char				*ft_tab(char *path, char *tab);
int					ft_count(char *path);
void				ft_print(t_data *data, char *path, char **tab, int count);
void				ft_print_rights(t_data *data);
void				ft_print_opt_l(t_data *data, char *path, char *file);
void				ft_print_time(t_data *data);
void				ft_error(char index, char *path);
int					ft_size(t_data *data, char *name);
void				ft_normal(t_data *data, char *path, char **tab, int ac);
void				ft_rev(t_data *data, char *path, char **tab, int ac);
void				print_link(char *path);
int					format_verif_ls(t_data *data, char **av, int ac);
char				*ft_c_file(char *path, char *file);

#endif
