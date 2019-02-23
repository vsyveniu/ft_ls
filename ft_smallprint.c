/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smallprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 19:07:57 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/06/05 15:53:51 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printinode(t_lst *dirs)
{
	int	pad;
	int	i;

	i = 0;
	pad = dirs->inodepad - ft_getintlen(dirs->inode);
	while (i++ < pad)
		write(1, " ", 1);
	ft_putlongnbr(dirs->inode);
	write(1, " ", 1);
}

void	ft_printblocks(long long eachblk, long long blkpad)
{
	long long pad;
	long long i;

	i = 0;
	pad = blkpad - ft_getintlen(eachblk);
	write(1, " ", 1);
	while (i < pad)
	{
		write(1, " ", 1);
		i++;
	}
	ft_putnbr(eachblk);
	write(1, " ", 1);
}

void	ft_printlinkcount(t_lst *meta, t_flags *flags)
{
	int	pad;
	int	i;

	i = 0;
	pad = meta->linkpad - ft_getintlen(meta->links);
	if (flags->aclcrutch)
	{
		while (i++ < pad)
			write(1, " ", 1);
		ft_putnbr(meta->links);
		write(1, " ", 1);
	}
	else
	{
		write(1, "  ", 2);
		i = 0;
		while (i++ < pad)
		{
			write(1, " ", 1);
			//write(1, "$", 1);
		}
		ft_putnbr(meta->links);
		write(1, " ", 1);
	}
}

void	ft_printusr(t_lst *meta)
{
	size_t pad;
	size_t i;

	i = 0;
	pad = meta->usrpad - ft_strlen(meta->usr);
	write(1, meta->usr, ft_strlen(meta->usr));
	while (i < pad)
	{
		write(1, " ", 1);
		i++;
	}
	write(1, "  ", 2);
}

void	ft_printgroup(t_lst *meta)
{
	size_t pad;
	size_t i;

	i = 0;
	pad = meta->gpad - ft_strlen(meta->group);
	write(1, meta->group, ft_strlen(meta->group));
	while (i < pad)
	{
		write(1, " ", 1);
		i++;
	}
	write(1, "  ", 2);
}
