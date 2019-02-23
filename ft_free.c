/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:45:19 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/06/05 13:45:22 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_freedirs(t_lst *dirs)
{
	t_lst *tmp;

	while (dirs != NULL)
	{
		tmp = dirs;
		tmp->data = dirs->data;
		tmp->path = dirs->path;
		tmp->group = dirs->group;
		tmp->usr = dirs->usr;
		tmp->timestr = dirs->timestr;
		dirs = dirs->next;
		free(tmp->data);
		free(tmp->path);
		free(tmp->group);
		free(tmp->usr);
		free(tmp->timestr);
		free(tmp);
	}
}

void	ft_freenode(t_lst *node)
{
	t_lst *tmp;

	if (node != NULL)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
}

void	ft_freeall(t_lst *nodes)
{
	t_lst *tmp;

	while (nodes != NULL)
	{
		tmp = nodes;
		nodes = nodes->next;
		free(tmp);
	}
}
