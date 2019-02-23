/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 19:03:10 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/06/04 19:03:12 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_checkexpand(struct stat statbuf)
{
	int ret;

	ret = 0;
	(S_ISCHR(statbuf.st_mode)) ? ret = 7 : 0;
	(S_ISBLK(statbuf.st_mode)) ? ret = 9 : 0;
	(S_ISLNK(statbuf.st_mode)) ? ret = 3 : 0;
	(S_ISREG(statbuf.st_mode)) ? ret = 4 : 0;
	(S_ISSOCK(statbuf.st_mode)) ? ret = 5 : 0;
	(S_ISFIFO(statbuf.st_mode)) ? ret = 6 : 0;
	return (ret);
}

int		ft_check(t_lst *dirs)
{
	DIR			*dir;
	int			ret;
	struct stat	statbuf;

	ret = 0;
	lstat(dirs->path, &statbuf);
	if (S_ISDIR(statbuf.st_mode))
	{
		if ((dir = opendir(dirs->path)) == NULL)
		{
			if (errno == ENOTDIR)
				return (dirs->gate = 11);
			if (errno == EACCES)
				return (dirs->gate = 1);
			return (dirs->gate = 8);
		}
		if (dir)
			closedir(dir);
		return (dirs->gate = 2);
	}
	ret = ft_checkexpand(statbuf);
	return (dirs->gate = ret);
}

void	ft_recursionexpand(t_lst *head, t_flags *flags)
{
	while (head)
	{
		if (head->gate == 1 || head->gate == 0)
			ft_printpermden(head, flags, 0);
		if (head->gate == 2 && ft_strcmp(head->data, ".") != 0
				&& ft_strcmp(head->data, "..") != 0)
		{
			if (head->data[0] == '.' && flags->f_a == 0)
				;
			else
			{
				head->isfile = 0;
				head->first = 0;
				ft_recursion(head, flags);
			}
			head = head->next;
		}
		else
			head = head->next;
	}
}

void	ft_recursion(t_lst *node, t_flags *flags)
{
	t_lst *dirs;
	t_lst *head;
	t_lst *tmp;

	dirs = NULL;
	dirs = (t_lst *)malloc(sizeof(t_lst));
	dirs = ft_createlst(node, dirs, flags);
	head = dirs;

	head = ft_alphasort(head);
	ft_ifsort2(&head, flags);
	if (node->first == 0)
		write(1, "\n", 1);
	if (!node->isfile)
	{
		ft_putstr(node->path);
		write(1, ":", 1);
		write(1, "\n", 1);
	}
	if (dirs->gate != 1)
		ft_printdeep(head, flags, 0);
	tmp = head;

	ft_recursionexpand(head, flags);
	ft_freedirs(tmp);
}

void	ft_hendr(t_lst *node, t_flags *flags, int countcrutch, int ocr)
{
	t_lst *head;

	if (ocr)
		write(1, "\n", 1);
	node->isfile = 0;
	node->first = 1;
	head = node;
	if (countcrutch == 0)
		node->isfile = 1;
	while (node)
	{
		node->path = ft_strdup(node->data);
		ft_recursion(node, flags);
		node->first = 0;
		node = node->next;
	}
	while (head)
	{
		free(head->path);
		head = head->next;
	}
}
