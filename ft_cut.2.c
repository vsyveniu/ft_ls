/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut.2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 15:55:07 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/06/04 15:57:21 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lst	*ft_findheadfiles(t_lst *node, t_flags *flags)
{
	DIR			*dir;
	t_lst		*tmp;
	struct stat	statbuf;

	dir = NULL;
	while (
		(((dir = opendir(node->data)) == NULL) && errno != EACCES
			&& (stat(node->data, &statbuf) == 0
				|| lstat(node->data, &statbuf) == 0)
			&& node->next != NULL) || (ft_cutsymdir(node->data, flags) && node->next))
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	if (dir != NULL)
		closedir(dir);
	return (node);
}

t_lst	*ft_findhead(t_lst *node)
{
	DIR			*dir;
	struct stat	statbuf;

	dir = NULL;
	while (node != NULL && ((((dir = opendir(node->data)) == NULL)
					&& (lstat(node->data, &statbuf) != 0))))
	{
		ft_printnosuchfile(node);
		node = node->next;
	}
	if (dir != NULL)
		closedir(dir);
	return (node);
}
