/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 15:59:02 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/06/05 13:47:50 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_cutdumbcrutch(char *data, t_flags *flags)
{
	DIR			*dir;
	struct stat	statbuf;

	if (((dir = opendir(data)) == NULL) && (stat(data, &statbuf) != 0)
			&& (lstat(data, &statbuf) != 0))
	{
		flags->voiddircrutch = 1;
		if (dir)
			closedir(dir);
		return(1);
	}
	if (dir)
		closedir(dir);
	return (0);
}

void	ft_cutthebullshitnormecrutch(t_lst **node, t_flags *flags)
{
	t_lst	*tmp;
	t_lst	*prev;

	if ((*node))
	{
		while ((*node)->next)
		{
			prev = (*node);
			if (ft_cutdumbcrutch((*node)->next->data, flags) != 0)
			{
				*node = (*node)->next;
				ft_printnosuchfile((*node));
				tmp = (*node);
				(*node) = prev;
				(*node)->next = tmp->next;
				free(tmp);
				tmp = NULL;
			}
			else if ((*node)->next)
			{
				*node = (*node)->next;
				prev = (*node);
			}
		}
	}
}

t_lst	*ft_cutthebullshit(t_lst *node, t_flags *flags)
{
	t_lst *head;

	node = ft_findhead(node);
	head = node;
	ft_cutthebullshitnormecrutch(&node, flags);
	if (head)
		return (head);
	return (NULL);
}


void	ft_cutnormecrutch(t_lst **node, t_flags *flags)
{
	t_lst	*tmp;
	t_lst	*prev;
	DIR		*dir;

	prev = (*node);
	while ((*node))
	{
		if ((((dir = opendir((*node)->data)) == NULL) && errno != EACCES) || ft_cutsymdir((*node)->data, flags))
		{
			tmp = (*node);
			(*node) = prev;
			(*node)->next = tmp->next;
			ft_freenode(tmp);
			tmp = NULL;
			*node = (*node)->next;
		}
		else
		{
			if (dir != NULL)
				closedir(dir);
			prev = (*node);
			*node = (*node)->next;
		}
	}
}

t_lst	*ft_cutfiles(t_lst *node, t_flags *flags)
{
	t_lst		*head;
	struct stat	statbuf;

	node = ft_findheadfiles(node, flags);
	head = node;
	ft_cutnormecrutch(&node, flags);
	lstat(head->data, &statbuf);
	if (head->next == NULL && (((!S_ISDIR(statbuf.st_mode) && !ft_keepsymdir(head->data, flags)) || ft_cutsymdir(head->data, flags))))
		return (NULL);
	return (head);
}
