/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alphasort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 15:47:30 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/06/05 15:03:52 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_reverse(t_lst **node)
{
	t_lst *prev;
	t_lst *curr;
	t_lst *next;

	prev = NULL;
	curr = *node;
	next = NULL;
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*node = prev;
}

t_lst	*ft_alphasort(t_lst *node)
{
	ft_mergesort(&node);
	ft_reverse(&node);
	return (node);
}

void	ft_mergeexpand(t_lst **node, t_lst *lside, t_lst *rside)
{
	if (lside == NULL)
	{
		*node = rside;
		return ;
	}
	if (rside == NULL)
	{
		*node = lside;
		return ;
	}
}

t_lst	*ft_addnodemm(char *str)
{
	t_lst	*tmp;
	size_t	i;

	i = 0;
	if (str)
	{
		tmp = malloc(sizeof(t_lst));
		tmp->data = ft_strdup(str);
		tmp->next = NULL;
		return (tmp);
	}
	return (NULL);
}
