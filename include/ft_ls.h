#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/include/ft_printf.h"
# include "../libft/include/libft.h"
# include <unistd.h>
# include <stdio.h>
#include <stdlib.h>

# include <dirent.h>
# include <sys/types.h>
# include <sys/dir.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
#include <pwd.h>
#include <grp.h>


typedef struct s_data
{
	int				opt;
	char			opt_a;
	char			opt_l;
	char			opt_r;
	char			opt_t;
	char			opt_rec;
	int				size;
	int				count;
	struct stat		file;
	char			time[12];
	int				width;
}				t_data;


int	  main(int ac, char **av);
int 	ft_option(t_data *data, char c);
void  ft_ls(t_data *data, char *path, int ac);
void  sort_parm_opt(t_data *data, char **tab, char *path);
char	*ft_tab(char *path, char *tab);
void  ft_print(t_data *data, char *path, char **tab);
void  ft_print_rights(t_data *data);
void  ft_print_opt_l(t_data *data, char *path, char *file);
void  ft_print_time(t_data *data);
void  ft_error(t_data **data, char index, char *path);
int		ft_size(t_data *data, char *name);
void 	ft_normal(t_data *data, char *path, char **tab, int ac);
void 	ft_rev(t_data *data, char *path, char **tab, int ac);
void	print_link(char *path);

#endif
