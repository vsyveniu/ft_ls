/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:21:54 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/06/04 17:24:37 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

long long	ft_gettotal(t_lst *head, t_flags *flags, int *totalcrutch)
{
	struct stat	statbuf;
	long long	total;

	total = 0;
	if (head->data[0] == '.' && head->next->next == NULL && !flags->f_a)
		*totalcrutch = 1;
	while (head)
	{
		if (!flags->f_a && head->data[0] == '.')
			;
		else
		{
			lstat(head->path, &statbuf);
			total = total + statbuf.st_blocks;
		}
		head = head->next;
	}
	return (total);
}

void		ft_compare(t_lst *meta, t_info *padding)
{
	if (meta->usrpad < padding->usrpad)
		meta->usrpad = padding->usrpad;
	if (meta->gpad < padding->gpad)
		meta->gpad = padding->gpad;
	if (meta->linkpad < padding->linkpad)
		meta->linkpad = padding->linkpad;
	if (meta->sizepad < padding->sizepad)
		meta->sizepad = padding->sizepad;
	if (meta->blkpad < padding->blkpad)
		meta->blkpad = padding->blkpad;
	if (meta->majorpad < padding->majorpad)
		meta->majorpad = padding->majorpad;
	if (meta->minorpad < padding->minorpad)
		meta->minorpad = padding->minorpad;
	if (meta->inodepad < padding->inodepad)
		meta->inodepad = padding->inodepad;
}


void 		ft_getminmajpad(t_lst *head, t_info *padding)
{
	padding->majorpad = ft_getintlen(head->major);
	padding->minorpad = ft_getintlen(head->minor);

}

void		ft_getpadding(t_lst *head, t_lst *node, t_flags *flags)
{
	t_info			*padding;

	padding = (t_info *)malloc(sizeof(t_info));
	ft_fillnull(padding);
	while (head)
	{
		if (!flags->f_a && head->data[0] == '.')
			head = head->next;
		else
		{
			padding->usrpad = ft_strlen(head->usr);
			padding->gpad = ft_strlen(head->group);
			padding->linkpad = ft_getintlen(head->links);
			padding->sizepad = ft_getintlen(head->size);
			padding->blkpad = ft_getintlen(head->eachblk);
			padding->inodepad = ft_getintlen(head->inode);
			if (head->gate == 9 || head->gate == 7)
				ft_getminmajpad(head, padding);
			ft_compare(node, padding);
			head = head->next;
		}
	}
	free(padding);
}

int			ft_getintlen(long long num)
{
	int i;

	i = 0;
	if (num == 0)
		return (i = 1);
	//printf("%lld\n", num);
	while (num)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

void		ft_getnum(t_lst *head)
{
	int	num;

	num = 0;
	while (head)
	{
		head->revnum = num;
		num += 1;
		head = head->next;
	}
}
