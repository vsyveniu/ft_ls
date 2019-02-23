/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:14:47 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/06/04 16:15:52 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_justnormecrutch(t_lst *meta, struct stat statbuf)
{
	if (S_ISDIR(statbuf.st_mode))
	{
		meta->type = 'd';
		meta->color = COLOR_BLUE;
		meta->typesymbol = "/";
	}
	else if (S_ISLNK(statbuf.st_mode))
	{
		meta->type = 'l';
		meta->color = COLOR_MAGENTA;
		meta->typesymbol = "@";
	}
	else if (S_ISSOCK(statbuf.st_mode))
	{
		meta->type = 's';
		meta->color = COLOR_GREEN;
		meta->typesymbol = "=";
	}
	else if (S_ISFIFO(statbuf.st_mode))
	{
		meta->type = 'p';
		meta->color = COLOR_BROWN;
		meta->typesymbol = "|";
	}
}

void	ft_fillcolortype(t_lst *meta, struct stat statbuf)
{
	if (S_ISREG(statbuf.st_mode))
	{
		meta->type = '-';
		meta->color = "\x1b[0m";
		meta->typesymbol = NULL;
		if (statbuf.st_mode & S_IXUSR)
		{
			meta->color = COLOR_RED;
			meta->typesymbol = "*";
		}
	}
	else if (S_ISBLK(statbuf.st_mode))
	{
		meta->type = 'b';
		meta->color = COLOR_BLUE;
	}
	else if (S_ISCHR(statbuf.st_mode))
	{
		meta->type = 'c';
		meta->color = COLOR_BLUE;
	}
	else
		ft_justnormecrutch(meta, statbuf);
}
