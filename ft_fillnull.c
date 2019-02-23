/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillnull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:17:23 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/06/04 16:23:37 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_expandfilldirswithnull(t_lst *dirs)
{
	dirs->islink = 0;
	dirs->blkpad = 0;
	dirs->eachblk = 0;
	dirs->timemark = 0;
	dirs->major = 0;
	dirs->minor = 0;
	dirs->majorpad = 0;
	dirs->minorpad = 0;
	dirs->inodepad = 0;
	dirs->first = 0;
	dirs->revnum = 0;
	dirs->acl = 0;
}

void	ft_filldirswithnull(t_lst *dirs)
{
	dirs->stm = 0;
	dirs->gate = 0;
	dirs->timemark = 0;
	dirs->isfile = 0;
	dirs->first = 0;
	dirs->inode = 0;
	dirs->links = 0;
	dirs->usr = NULL;
	dirs->group = NULL;
	dirs->size = 0;
	dirs->time = 0;
	dirs->timestr = 0;
	dirs->color = NULL;
	dirs->typesymbol = NULL;
	dirs->gpad = 0;
	dirs->usrpad = 0;
	dirs->linkpad = 0;
	dirs->sizepad = 0;
	ft_expandfilldirswithnull(dirs);
}

void	ft_fillnullcticrutch(t_cti *cticrutch)
{
	cticrutch->color = 0;
	cticrutch->inode = 0;
	cticrutch->type = 0;
	cticrutch->minmajpadcrutch = 0;
}

void	ft_fillnull(t_info *meta)
{
	meta->size = 0;
	meta->gpad = 0;
	meta->usrpad = 0;
	meta->linkpad = 0;
	meta->sizepad = 0;
	meta->blkpad = 0;
	meta->majorpad = 0;
	meta->minorpad = 0;
	meta->inodepad = 0;
}

void	ft_flagszero(t_flags *flags)
{
	flags->f_rec = 0;
	flags->f_one = 0;
	flags->f_r = 0;
	flags->f_l = 0;
	flags->f_t = 0;
	flags->f_a = 0;
	flags->f_i = 0;
	flags->f_color = 0;
	flags->isfile = 0;
	flags->f_type = 0;
	flags->f_ddash = 0;
	flags->aclcrutch = 0;
	flags->voiddircrutch = 0;
	flags->rflagpermcructh = 0;
	flags->f_s = 0;
}
