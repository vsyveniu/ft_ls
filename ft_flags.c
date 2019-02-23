/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:13:44 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/06/04 17:15:06 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_fillfullflag(char *str, t_flags *flags)
{
	if (ft_strcmp(str, "-R") == 0)
		flags->f_rec = 1;
	else if (ft_strcmp(str, "-r") == 0)
		flags->f_r = 1;
	else if (ft_strcmp(str, "-l") == 0)
		flags->f_l = 1;
	else if (ft_strcmp(str, "-t") == 0)
		flags->f_t = 1;
	else if (ft_strcmp(str, "-a") == 0)
		flags->f_a = 1;
	else if (ft_strcmp(str, "-i") == 0)
		flags->f_i = 1;
	else if (ft_strcmp(str, "-s") == 0)
		flags->f_s = 1;
	else if (ft_strcmp(str, "-1") == 0)
		flags->f_one = 1;
	else if (ft_strcmp(str, "-G") == 0)
		flags->f_color = 1;
	else if (ft_strcmp(str, "-F") == 0)
		flags->f_type = 1;
	else if (ft_strcmp(str, "--") == 0)
		flags->f_ddash = 1;
	else
		ft_flagerror(str);
}

int		ft_flagcheck(char c)
{
	if (c == 'r')
		return (1);
	else if (c == 'l')
		return (1);
	else if (c == 'R')
		return (1);
	else if (c == 't')
		return (1);
	else if (c == 'a')
		return (1);
	else if (c == '1')
		return (1);
	else if (c == 'G')
		return (1);
	else if (c == 'i')
		return (1);
	else if (c == 'F')
		return (1);
	else if (c == 's')
		return (1);
	else
		return (0);
}

void	ft_flagset(char *str, int i, t_flags *flags)
{
	if (str[i] == 'r')
		flags->f_r = 1;
	else if (str[i] == 'l')
		flags->f_l = 1;
	else if (str[i] == 'R')
		flags->f_rec = 1;
	else if (str[i] == 't')
		flags->f_t = 1;
	else if (str[i] == 'a')
		flags->f_a = 1;
	else if (str[i] == '1')
		flags->f_one = 1;
	else if (str[i] == 'G')
		flags->f_color = 1;
	else if (str[i] == 'i')
		flags->f_i = 1;
	else if (str[i] == 'F')
		flags->f_type = 1;
	else if (str[i] == 's')
		flags->f_s = 1;
}

void	ft_fillset(char *str, t_flags *flags)
{
	int i;

	i = 1;
	while (str[i] != '\0')
	{
		if (ft_flagcheck(str[i]))
			ft_flagset(str, i, flags);
		else
			ft_flagerrorchar(str[i]);
		i++;
	}
}

void	ft_fillflags(char *str, t_flags *flags)
{
	if (ft_strlen(str) > 2)
	{
		ft_fillset(str, flags);
	}
	else
	{
		ft_fillfullflag(str, flags);
	}
}
