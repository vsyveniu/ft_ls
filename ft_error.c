/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:07:15 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/06/04 16:09:47 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_flagerror(char *str)
{
	int i;

	i = 0;
	write(1, "ft_ls:", 6);
	write(1, " illegal option --  ", 19);
	write(1, &str[1], 1);
	write(1, "\n", 1);
	write(1, "usage: ft_ls [-RFGalrti1s] [file ...]\n", 38);
	exit(1);
}

void	ft_flagerrorchar(char c)
{
	write(1, "ft_ls:", 6);
	write(1, " illegal option --  ", 19);
	write(1, &c, 1);
	write(1, "\n", 1);
	write(1, "usage: ft_ls [-RFGalrti1s] [file ...]\n", 38);
	exit(1);
}

void	ft_printnosuchfile(t_lst *node)
{
	DIR			*dir;
	struct stat	statbuf;

	if (node)
	{
		write(1, "ft_ls: ", 7);
		write(1, node->data, ft_strlen(node->data));
		write(1, ": ", 2);
		stat(node->path, &statbuf);
		if (!(dir = opendir(node->data)) && errno == ENOTDIR)
			write(1, "Not a directory", 15);
		else if (!(dir = opendir(node->data)) && errno == EBADF)
		{
			write(1, "Bad file descriptor", 19);
		}
		else
			write(1, "No such file or directory", 25);
		write(1, "\n", 1);
	}
}

void	ft_printpermdenrec(t_lst *dirs)
{
	int end;

	end = ft_strlen(dirs->data) - 1;
	if (dirs->data[end] != '/')
	{
		write(1, "ft_ls: ", 7);
		ft_putstr(dirs->path);
		write(1, ": ", 2);
		write(1, "Permission denied\n", 18);
	}
	else
	{
		write(1, "ft_ls: ", 7);
		write(1, ": ", 2);
		write(1, "Permission denied\n", 18);

	}
}

int		ft_getcountpermdenied(t_lst *dirs)
{
	int res;

	res = 0;
	if (!dirs->next)
		res = 1;
	return (res);
}


void	ft_printpermdensimple(t_lst *dirs, int count)
{
	int end;

	end = ft_strlen(dirs->data) - 1;
	if (dirs->data[end] != '/')
	{
		if (count != 0)
		{
			ft_putstr(dirs->data);
			write(1, ":\n", 2);
		}
		write(1, "ft_ls: ", 7);
		ft_putstr(dirs->path);
		write(1, ": Permission denied\n", 20);
	}
	else
	{
		if (count != 0)
		{
			ft_putstr(dirs->data);
			write(1, ":\n", 2);
		}
		write(1, "ft_ls: ", 7);
		write(1, ": Permission denied\n", 20);

	}
}

void	ft_printpermden(t_lst *dirs, t_flags *flags, int count)
{
	if (flags->f_rec)
	{
		if (flags->rflagpermcructh)
			ft_printpermdenrec(dirs);
		else
		{
			write(1, "\n", 1);
			ft_putstr(dirs->path);
			write(1, ":\n", 2);
			write(1, "ft_ls: ", 7);
			ft_putstr(dirs->data);
			write(1, ": ", 2);
			if (dirs->gate == 0)
				write(1, "Not a directory\n", 16);
			else
			{
				write(1, "Permission denied\n", 18);
		}
		}
	}
	else
		ft_printpermdensimple(dirs, count);
}
