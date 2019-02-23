/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mergesort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 17:26:00 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/06/04 17:38:57 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_restside(t_lst *side, t_lst **node)
{
	while (side)
	{
		(*node)->next = side;
		(*node) = (*node)->next;
		side = side->next;
	}
}

void	ft_exactlysort(t_lst **node, t_lst *lside, t_lst *rside)
{
	while (lside && rside)
	{
		if (ft_strcmp(lside->data, rside->data) > 0)
		{
			(*node)->next = lside;
			lside = lside->next;
		}
		else
		{
			(*node)->next = rside;
			rside = rside->next;
		}
		(*node) = (*node)->next;
	}
	if (lside)
		ft_restside(lside, node);
	if (rside)
		ft_restside(rside, node);
}

void	ft_merge(t_lst **node, t_lst *lside, t_lst *rside)
{
	t_lst tmp;

	*node = NULL;
	if (lside == NULL || rside == NULL)
	{
		ft_mergeexpand(node, lside, rside);
		return ;
	}
	if (ft_strcmp(lside->data, rside->data) > 0)
	{
		*node = lside;
		lside = lside->next;
	}
	else
	{
		*node = rside;
		rside = rside->next;
	}
	tmp.next = *node;
	ft_exactlysort(node, lside, rside);
	*node = tmp.next;
}

void	ft_splitm(t_lst *node, t_lst **lside, t_lst **rside)
{
	t_lst *onestep;
	t_lst *twostep;

	onestep = NULL;
	twostep = NULL;
	if (node == NULL || node->next == NULL)
	{
		(*lside) = node;
		(*rside) = NULL;
		return ;
	}
	onestep = node;
	twostep = node->next;
	while (twostep != NULL)
	{
		twostep = twostep->next;
		if (twostep != NULL)
		{
			twostep = twostep->next;
			onestep = onestep->next;
		}
	}
	(*lside) = node;
	(*rside) = onestep->next;
	onestep->next = NULL;
}

void	ft_mergesort(t_lst **node)
{
	t_lst *lside;
	t_lst *rside;

	lside = NULL;
	rside = NULL;
	if (*node == NULL || ((*node)->next == NULL))
		return ;
	ft_splitm(*node, &lside, &rside);
	ft_mergesort(&lside);
	ft_mergesort(&rside);
	ft_merge(node, lside, rside);
}
