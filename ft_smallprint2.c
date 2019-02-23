/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smallprint2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:49:02 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/06/05 13:56:05 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printsize(t_cti *cticrutch, t_lst *meta)
{
	int p;
	int i;

	i = 0;
	if (!cticrutch->minmajpadcrutch)
	{
		p = meta->sizepad - ft_getintlen(meta->size);
		i = 0;
		while (i++ < p)
			write(1, " ", 1);
		ft_putnbr(meta->size);
		write(1, " ", 1);
	}
	else if (cticrutch->minmajpadcrutch)
	{
		p = ((meta->majorpad + 2) + meta->minorpad - ft_getintlen(meta->size));
		write(1, " ", 1);
		while (i++ < p)
			write(1, " ", 1);
		ft_putnbr(meta->size);
		write(1, " ", 1);
	}
}

void	ft_printtime(t_lst *meta)
{
	int i;

	i = 0;
	if (meta->timemark == 1)
	{
		ft_putnnnstr(meta->timestr, 4, 10);
		write(1, "  ", 2);
		ft_putnnnstr(meta->timestr, 20, 24);
	}
	else
		ft_putnnnstr(meta->timestr, 4, 16);
}

void	ft_printfile(char *str, t_lst *meta, t_cti *cticrutch)
{
	write(1, " ", 1);
	if (cticrutch->color)
	{
		ft_setcolor(meta->color);
		write(1, str, ft_strlen(str));
		ft_resetcolor();
	}
	else
		write(1, str, ft_strlen(str));
}

void	ft_printtypesym(t_lst *meta)
{
	if (meta->typesymbol)
	{
		write(1, meta->typesymbol, 1);
		write(1, " ", 1);
	}
}

void	ft_printlink(t_lst *meta)
{
	write(1, " -> ", 4);
	ft_putstr(meta->linkval);
}
