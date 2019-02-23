/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:57:26 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/06/04 18:38:57 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printblk(t_lst *dirs)
{
	int	pad;
	int	i;

	i = 0;
	pad = dirs->blkpad - ft_getintlen(dirs->eachblk);
	i = 0;
	while (i++ < pad)
	{
		write(1, " ", 1);
	}
	ft_putnbr(dirs->eachblk);
	write(1, " ", 1);

}


void	ft_printv(t_lst *dirs, t_cti *cticrutch, t_flags *flags)
{
	int i;

	i = 3;
	(cticrutch->inode) ? ft_printinode(dirs) : 0;
	if (flags->f_s)
		ft_printblk(dirs);
	ft_printfiletypev2(dirs);
	ft_printfilepermissionsv2(dirs);
	if (flags->aclcrutch)
		ft_printaclxattr(dirs, flags);
	ft_printlinkcount(dirs, flags);
	ft_printusr(dirs);
	ft_printgroup(dirs);
	(dirs->gate != 7 && dirs->gate != 9) ? ft_printsize(cticrutch, dirs) : 0;
	(dirs->gate == 7 || dirs->gate == 9) ? ft_printminmaj(dirs) : 0;
	ft_printtime(dirs);
	ft_printfile(dirs->data, dirs, cticrutch);
	(cticrutch->type) ? ft_printtypesym(dirs) : 0;
	if (dirs->islink)
		ft_printlink(dirs);
	write(1, "\n", 1);
}

void	ft_printlessv2(t_lst *dirs, t_cti *cticrutch)
{
	if (cticrutch->inode)
		ft_printinode(dirs);
	if (cticrutch->color)
	{
		ft_setcolor(dirs->color);
		ft_putstr(dirs->data);
		ft_resetcolor();
	}
	else
		ft_putstr (dirs->data);
	if (cticrutch->type)
		ft_putstr(dirs->typesymbol);
	write(1, "  ", 2);
}

void	ft_printcatcrutch(t_lst *dirs, t_cti *cticrutch, t_flags *flags)
{
	if (!flags->f_a && dirs->data[0] == '.')
		;
	else if (flags->f_one && !flags->f_l)
		ft_printone(dirs, cticrutch);
	else if (flags->f_l)
		ft_printv(dirs, cticrutch, flags);
	else
		ft_printlessv2(dirs, cticrutch);
}

void	ft_printcat(t_lst *dirs, t_flags *flags, int count)
{
	t_cti	*cticrutch;
	t_lst	*dumbpadctutch;
	t_lst	*head;

	dumbpadctutch = dirs;
	cticrutch = malloc(sizeof(t_cti));
	ft_fillnullcticrutch(cticrutch);
	(flags->f_color) ? cticrutch->color = 1 : 0;
	(flags->f_type) ? cticrutch->type = 1 : 0;
	(flags->f_i) ? cticrutch->inode = 1 : 0;
	while (dumbpadctutch)
	{
		if (dumbpadctutch->gate == 9 || dumbpadctutch->gate == 7)
			cticrutch->minmajpadcrutch = 1;
		dumbpadctutch = dumbpadctutch->next;
	}
	head = dirs;
	while (dirs)
	{
		ft_printcatcrutch(dirs, cticrutch, flags);
		dirs = dirs->next;
	}
	if (count == 1)
		write(1, "\n", 1);
	free(cticrutch);
}
