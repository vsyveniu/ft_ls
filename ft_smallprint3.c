/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smallprint3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:56:56 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/06/05 14:00:25 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printfilepermissionsv2(t_lst *meta)
{
	(meta->stm & S_IRUSR) ? write(1, "r", 1) : write(1, "-", 1);
	(meta->stm & S_IWUSR) ? write(1, "w", 1) : write(1, "-", 1);
	(meta->stm & S_IXUSR && (!(meta->stm & S_ISUID))) ? write(1, "x", 1) : 0;
	(!(meta->stm & S_IXUSR) && (!(meta->stm & S_ISUID))) ? write(1, "-", 1) : 0;
	(!(meta->stm & S_IXUSR) && ((meta->stm & S_ISUID))) ? write(1, "S", 1) : 0;
	((meta->stm & S_IXUSR) && ((meta->stm & S_ISUID))) ? write(1, "s", 1) : 0;
	(meta->stm & S_IRGRP) ? write(1, "r", 1) : write(1, "-", 1);
	(meta->stm & S_IWGRP) ? write(1, "w", 1) : write(1, "-", 1);
	(meta->stm & S_IXGRP && (!(meta->stm & S_ISGID))) ? write(1, "x", 1) : 0;
	(!(meta->stm & S_IXGRP) && (!(meta->stm & S_ISGID))) ? write(1, "-", 1) : 0;
	(!(meta->stm & S_IXGRP) && ((meta->stm & S_ISGID))) ? write(1, "S", 1) : 0;
	((meta->stm & S_IXGRP) && ((meta->stm & S_ISGID))) ? write(1, "s", 1) : 0;
	(meta->stm & S_IROTH) ? write(1, "r", 1) : write(1, "-", 1);
	(meta->stm & S_IWOTH) ? write(1, "w", 1) : write(1, "-", 1);
	(meta->stm & S_IXOTH && (!(meta->stm & S_ISVTX))) ? write(1, "x", 1) : 0;
	(!(meta->stm & S_IXOTH) && (!(meta->stm & S_ISVTX))) ? write(1, "-", 1) : 0;
	(!(meta->stm & S_IXOTH) && ((meta->stm & S_ISVTX))) ? write(1, "T", 1) : 0;
	((meta->stm & S_IXOTH) && ((meta->stm & S_ISVTX))) ? write(1, "t", 1) : 0;
}

void	ft_printtotal(long long total, t_flags *flags)
{
	if (!flags->isfile)
	{
		write(1, "total ", 6);
		ft_putnbr(total);
		write(1, "\n", 1);
	}
}

void	ft_printminmaj(t_lst *meta)
{
	int majpad;
	int minpad;
	int i;

	i = 0;
	majpad = meta->majorpad - ft_getintlen(meta->major);
	minpad = meta->minorpad - ft_getintlen(meta->minor);
	write(1, " ", 1);
	while (i < majpad)
	{
		write(1, " ", 1);
		i++;
	}
	ft_putnbr(meta->major);
	write(1, ", ", 2);
	i = 0;
	while (i < minpad)
	{
		write(1, " ", 1);
		i++;
	}
	ft_putnbr(meta->minor);
	write(1, " ", 1);
}

void	ft_printfiletypev2(t_lst *dirs)
{
	write(1, &dirs->type, 1);
}
