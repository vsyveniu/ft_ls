/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:43:43 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/06/04 17:43:45 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printpure(t_lst *dirs, t_flags *flags, int count)
{
	t_lst		*head;
	long long	total;
	int			totalcrutch;

	total = 0;
	totalcrutch = 0;
	head = dirs;
	while (dirs)
	{
		ft_getpadding(head, dirs, flags);
		dirs = dirs->next;
	}
	if (head->gate != 0) ////not sure !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! delete gate 9 and 7
		total = ft_gettotal(head, flags, &totalcrutch);
	if (flags->f_l && !totalcrutch)
			ft_printtotal(total, flags);
	ft_printcat(head, flags, count);
	if (!flags->f_l && !flags->f_one && !totalcrutch)
		write(1, "\n", 1);
}

void	ft_printdeep(t_lst *dirs, t_flags *flags, int count)
{
		if (flags->f_t && !flags->f_rec)
		{
			ft_sortbytime2(&dirs);
			ft_reverse(&dirs);
		}
		if (flags->f_r && !flags->f_rec)
			ft_reverse(&dirs);
		ft_getaclcrutch(flags, dirs);
		ft_printpure(dirs, flags, count);
		if (!flags->f_rec)
			ft_freedirs(dirs);
	}

void	ft_printdirlittlenormecrutch(t_lst *node, int count, t_flags *flags)
{
	if (count == 1 || count == 2 || flags->voiddircrutch)
	{
		ft_putstr(node->data);
		write(1, ":\n", 2);
	}
}

void	ft_printdirnormecrutch(int onemorecrutch, t_flags *flags)
{
	if (onemorecrutch && !flags->f_l && !flags->f_one)
		write(1, "\n\n", 2);
	else if (onemorecrutch && !flags->f_l && flags->f_one)
		write(1, "\n", 1);
	else if (onemorecrutch && flags->f_l)
		write(1, "\n", 1);
}

void	ft_pdir(t_lst *node, t_flags *flags, int count, int ocr)
{
	t_lst *dirs;

	ft_printdirnormecrutch(ocr, flags);
	if (node)
	{
		while (node)
		{
			if (node->next == NULL && count != 0)
				count = 2;
			dirs = malloc(sizeof(t_lst));
			node->path = ft_strdup(node->data);
			dirs = ft_createlst(node, dirs, flags);
			dirs = ft_alphasort(dirs);
			if (dirs->gate == 1)
				ft_printpermden(dirs, flags, count);
			else
			{
				ft_printdirlittlenormecrutch(node, count, flags);
				ft_printdeep(dirs, flags, count);
			}
			free(node->path);
			node = node->next;
		}
	}
}
