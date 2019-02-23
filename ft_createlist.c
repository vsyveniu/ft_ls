/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 15:51:16 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/06/04 15:53:03 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_createlisteaccesscrutch(t_lst *dirs, t_lst *node, t_flags *flags)
{
	dirs->data = ft_strdup(node->data);
	dirs->path = ft_strdup(node->path);
	dirs->usr = NULL;
	dirs->timestr = NULL;
	dirs->group = NULL;
	dirs->gate = 1;
	dirs->next = NULL;
	flags->rflagpermcructh = 1;
}

void	ft_createlistenotdircrutch(t_lst *dirs, t_lst *node)
{
	t_lst	*tmp;

	tmp = dirs;
	dirs->data = ft_strdup(node->data);
	dirs->path = ft_strdup(node->data);
	tmp->next = NULL;
	tmp->gate = 2;
	dirs = tmp;
}

void	ft_createlstnormecrutch(DIR *dir, t_lst *node, t_lst *dirs)
{
	t_lst			*tmp;
	struct dirent	*entry;

	
	if (dir)
		closedir(dir);
	dir = opendir(node->path);
	entry = readdir(dir);
	dirs->data = ft_strdup(entry->d_name);
	tmp = dirs;
	while ((entry = readdir(dir)))
	{
		dirs->next = ft_addnodemm(entry->d_name);
		dirs = dirs->next;
	}
	dirs = tmp;
	entry = NULL;
	closedir(dir);
}

t_lst	*ft_createlst(t_lst *node, t_lst *dirs, t_flags *flags)
{
	DIR			*dir;
	struct stat	statbuf;
	t_lst		*head;

	lstat(node->path, &statbuf);
	if (!(dir = opendir(node->path)) && errno == EACCES)
	{
		ft_createlisteaccesscrutch(dirs, node, flags);
		return (dirs);
	}
	else if (!S_ISDIR(statbuf.st_mode) && errno == ENOTDIR)
	{
		ft_createlistenotdircrutch(dirs, node);
		return (dirs);
	}
	else
		ft_createlstnormecrutch(dir, node, dirs);
	head = dirs;
	while (dirs)
	{
		ft_filllistrec(node, dirs);
		dirs = dirs->next;
	}
	return (head);
}
