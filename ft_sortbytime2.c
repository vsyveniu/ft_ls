/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortbytime2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:42:03 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/06/05 13:42:53 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_gettime2(char *s1, char *s2)
{
	struct stat	statbufs1;
	struct stat	statbufs2;
	time_t		rawtimes1;
	time_t		rawtimes2;

	lstat(s1, &statbufs1);
	rawtimes1 = statbufs1.st_mtimespec.tv_sec;
	lstat(s2, &statbufs2);
	rawtimes2 = statbufs2.st_mtimespec.tv_sec;
	if (rawtimes1 == rawtimes2 )
	{
		rawtimes1 = statbufs1.st_mtimespec.tv_nsec;
		rawtimes2 = statbufs2.st_mtimespec.tv_nsec;
	}
	if (rawtimes1 < rawtimes2)
		return (1);
	return (0);
}

void	ft_exactlysortbytime2(t_lst **node, t_lst *lside, t_lst *rside)
{
	while (lside && rside)
	{
		if (ft_gettime2(lside->path, rside->path) == 1)
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

void	ft_mergeexpandsortbytime2(t_lst **node, t_lst *lside, t_lst *rside)
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

void	ft_mergebytime2(t_lst **node, t_lst *lside, t_lst *rside)
{
	t_lst tmp;

	*node = NULL;
	if (lside == NULL || rside == NULL)
	{
		ft_mergeexpandsortbytime2(node, lside, rside);
		return ;
	}
	if (ft_gettime2(lside->path, rside->path) == 1)
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
	ft_exactlysortbytime2(node, lside, rside);
	*node = tmp.next;
}

void	ft_sortbytime2(t_lst **node)
{
	t_lst *lside;
	t_lst *rside;

	lside = NULL;
	rside = NULL;
	if (*node == NULL || ((*node)->next == NULL))
		return ;
	ft_splitm(*node, &lside, &rside);
	ft_sortbytime2(&lside);
	ft_sortbytime2(&rside);
	ft_mergebytime2(node, lside, rside);
}
