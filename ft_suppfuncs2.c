

#include "ft_ls.h"

void	ft_ifsort(t_lst **dirs, t_flags *flags)
{
	if (flags->f_t)
	{
		ft_sortbytime(dirs);
		ft_reverse(dirs);
	}
	if (flags->f_r)
		ft_reverse(dirs);
}


int		ft_cutsymdir(char *data, t_flags *flags)
{
	DIR *dir;
	int end;

	end = ft_strlen(data) - 1;
	if((dir = opendir(data)) != NULL && ft_checkiflink(data) && data[end] != '/' && flags->f_l)
	{
		if(dir)
			closedir(dir);
		return (1);
	}
	if(dir)
		closedir(dir);
	return(0);	
}

int		ft_keepsymdir(char *data, t_flags *flags)
{
	DIR *dir;
	int end;

	end = ft_strlen(data) - 1;
	if((dir = opendir(data)) != NULL && ft_checkiflink(data) && data[end] != '/' && !flags->f_l)
	{
		if(dir)
			closedir(dir);
		return (1);
	}
	if(dir)
		closedir(dir);
	return(0);	
}