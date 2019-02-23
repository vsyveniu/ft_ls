/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 15:45:20 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/06/04 15:45:22 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_hobnorme(t_lst *head, t_flags *flags, int count, int cr)
{
	if (head->next != NULL)
		count = 1;
	//ft_ifsort(&head, flags);
	if (head != NULL)
	{
		if (flags->f_rec)
			ft_hendr(head, flags, count, cr);
		else
			ft_pdir(head, flags, count, cr);
	}
}

void	ft_handleobjs(t_lst *node, t_flags *flags)
{
	t_lst	*head;
	t_lst	*files;
	int		count;
	int		cr;

	count = 0;
	cr = 0;
	node = ft_alphasort(node);
	ft_ifsort(&node, flags);
	head = ft_cutthebullshit(node, flags);
	if (head)
	{
		count = ft_f(head, &files, flags, &cr);
		head = ft_cutfiles(head, flags);
		if (!head && !flags->f_l && !flags->f_one)
			write(1, "\n", 1);
		if (head)
		{
			ft_hobnorme(head, flags, count, cr);
			ft_freeall(head);
		}
	}
}

void	ft_resolvenormecrutch(t_lst **node, t_flags *flags)
{
	DIR			*dir;
	struct stat	statbuf;

	if ((*node)->data != NULL)
	{
		while ((((dir = opendir((*node)->data)) == NULL)
					&& stat((*node)->data, &statbuf) != 0))
		{
			if ((ft_memchr((*node)->data, '-', 1) == NULL)
					|| (ft_strcmp("-", (*node)->data) == 0))
				break ;
			ft_fillflags((*node)->data, flags);
			if ((*node)->next == NULL)
				break ;
			ft_freenode((*node));
			*node = (*node)->next;
		}
		if (dir != NULL)
			closedir(dir);
	}
}

void	ft_resolve(t_lst *node)
{
	t_flags		*flags;

	flags = (t_flags *)malloc(sizeof(t_flags));
	ft_flagszero(flags);
	ft_resolvenormecrutch(&node, flags);
	if (ft_memchr(node->data, '-', 1) != NULL
		&& (ft_strcmp("-", node->data) != 0))
		node->data = ".";
	ft_handleobjs(node, flags);
	free(flags);
}

int		main(int argc, char **argv)
{
	int		i;
	t_lst	*allnodes;
	t_lst	*head;

	i = 1;
	allnodes = (t_lst *)malloc(sizeof(t_lst));
	if (argc == 1)
	{
		allnodes->data = ".";
		allnodes->next = NULL;
		head = allnodes;
	}
	else
	{
		allnodes->data = argv[i];
		allnodes->next = NULL;
		head = allnodes;
		while (i++ < argc - 1)
		{
			allnodes->next = ft_addnode(argv[i]);
			allnodes = allnodes->next;
		}
	}
	ft_resolve(head);
	return (0);
}
