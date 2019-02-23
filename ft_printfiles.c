/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 18:51:28 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/06/04 18:51:31 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_dividenormeonemoredumbcrutch(char *data, t_flags *flags)
{
	DIR			*dir;
	struct stat	statbuf;

	if (((((dir = opendir(data)) == NULL)
				&& ((stat(data, &statbuf) == 0)
					|| lstat(data, &statbuf) == 0)) && errno != EACCES)
		|| ft_checksymdir(data, flags))
	{
		if (dir)
			closedir(dir);
		return (1);
	}
	if (dir)
		closedir(dir);
	return (0);
}

void	ft_dividenormecrutch(t_lst *head, t_lst **files, int *anothercrutch, t_flags *flags)
{
	struct stat	statbuf;
	t_lst		*headf;

	lstat(head->data, &statbuf);
	if (!S_ISDIR(statbuf.st_mode))
	{
		(*files) = ft_addnodemm(head->data);
		headf = (*files);
		head = head->next;
		while (head)
		{
			if (ft_dividenormeonemoredumbcrutch(head->data, flags))
			{
				(*files)->next = ft_addnodemm(head->data);
				*files = (*files)->next;
			}
			head = head->next;
		}
		(*files) = headf;
	}
	else
		(*anothercrutch) = 1;
}

int		ft_checksymdir(char *data, t_flags *flags)
{
	int end;

	end = ft_strlen(data) - 1;
	if (ft_checkiflink(data) && data[end] != '/' && flags->f_l)
	{
		return (1);
	}
	return (0);	
}


void	ft_divide(t_lst *node, t_lst **files, int *anothercrutch, t_flags *flags)
{
	t_lst		*head;
	DIR			*dir;

	head = node;
	while ((head != NULL && ((dir = opendir(head->data)) != NULL) && !ft_checksymdir(head->data, flags))
			|| (head != NULL
				&& ((dir = opendir(head->data)) == NULL) && errno == EACCES))
	{
		if (dir != NULL)
			closedir(dir);
		head = head->next;
	}
	if (head)
	{
		ft_dividenormecrutch(head, files, anothercrutch, flags);
	}
	else
		*files = NULL;
}

void	ft_printfilesonly(t_lst *files, t_flags *flags)
{
	t_lst	*head;
	t_lst	*shead;
	t_lst	*sshead;

	if (flags->f_t || flags->f_r)
		ft_ifsort(&files, flags);
	head = files;
	shead = files;
	sshead = files;
	while (files)
	{
		ft_fillfiles(files);
		files = files->next;
	}
	while (head)
	{
		ft_getpadding(shead, head, flags);
		head = head->next;
	}
	ft_getaclcrutch(flags, shead);
	ft_printcat(shead, flags, 0);
	ft_freedirs(sshead);
}

int		ft_f(t_lst *node, t_lst **files, t_flags *flags, int *cr)
{
	t_lst		*head;
	t_lst		*headfiles;
	int			countcrutch;
	int			anothercrutch;

	countcrutch = 0;
	anothercrutch = 0;
	head = node;
	ft_divide(head, files, &anothercrutch, flags);
	headfiles = (*files);
	while ((*files))
	{
		ft_filllist((*files));
		*files = (*files)->next;
	}
	if (headfiles)
	{
		countcrutch = 1;
		*cr = 1;
	}
	ft_printfilesonly(headfiles, flags);
	return (countcrutch);
}
