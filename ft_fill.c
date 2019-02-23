/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:11:13 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/06/04 16:13:37 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_expandfillfiles(t_lst *dirs, struct stat statbuf)
{
	struct passwd	*getpw;
	struct group	*getgid;
	time_t			sec;

	dirs->stm = statbuf.st_mode;
	dirs->gate = ft_check(dirs);
	dirs->time = statbuf.st_mtimespec.tv_sec;
	getgid = getgrgid(statbuf.st_gid);
	getpw = getpwuid(statbuf.st_uid);
	dirs->group = ft_strdup(getgid->gr_name);
	dirs->usr = ft_strdup(getpw->pw_name);
	sec = time(NULL);
	ft_fillcolortype(dirs, statbuf);
	dirs->inode = statbuf.st_ino;
	dirs->links = statbuf.st_nlink;
	dirs->size = statbuf.st_size;
	dirs->timestr = ft_strdup(ctime(&statbuf.st_mtimespec.tv_sec));
	dirs->eachblk = statbuf.st_blocks;
	if (dirs->gate == 9 || dirs->gate == 7)
	{
		dirs->minor = (minor(statbuf.st_rdev));
		dirs->major = (major(statbuf.st_rdev));
	}
	if (dirs->time < (sec - 15778800))
		dirs->timemark = 1;
}

void	ft_fillfiles(t_lst *dirs)
{
	struct stat statbuf;

	ft_filldirswithnull(dirs);
	if (ft_checkiflink(dirs->path))
	{
		lstat(dirs->path, &statbuf);
		readlink(dirs->path, dirs->linkval, 4095);
		dirs->linkval[4095] = '\0';
		dirs->islink = 1;
	}
	else
		stat(dirs->path, &statbuf);
	dirs->acl = ft_getacl(dirs->path);
	ft_expandfillfiles(dirs, statbuf);
}

void	ft_filllist(t_lst *node)
{
	struct stat	statbuf;

	node->path = ft_strdup(node->data);
	lstat(node->path, &statbuf);
	node->stm = statbuf.st_mode;
	node->time = statbuf.st_mtime;
}

void	ft_expandfilllistrec(t_lst *dirs, struct stat statbuf)
{
	time_t			sec;
	struct passwd	*getpw;
	struct group	*getgid;

	dirs->stm = statbuf.st_mode;
	dirs->gate = ft_check(dirs);
	dirs->time = statbuf.st_mtime;
	getgid = getgrgid(statbuf.st_gid);
	getpw = getpwuid(statbuf.st_uid);
	dirs->group = ft_strdup(getgid->gr_name);
	dirs->usr = ft_strdup(getpw->pw_name);
	sec = time(NULL);
	ft_fillcolortype(dirs, statbuf);
	dirs->inode = statbuf.st_ino;
	dirs->links = statbuf.st_nlink;
	dirs->size = statbuf.st_size;
	dirs->timestr = ft_strdup(ctime(&statbuf.st_mtime));
	dirs->eachblk = statbuf.st_blocks;
	if (dirs->gate == 9 || dirs->gate == 7)
	{
		dirs->minor = (minor(statbuf.st_rdev));
		dirs->major = (major(statbuf.st_rdev));
	}
	if (dirs->time < (sec - 15778800))
		dirs->timemark = 1;
}

void	ft_filllistrec(t_lst *node, t_lst *dirs)
{
	struct stat	statbuf;
	char		*joinbuf;
	char		*joinbuf2;

	ft_filldirswithnull(dirs);
	joinbuf = NULL;
	if (ft_strcmp(node->data, "/") == 0)
		joinbuf2 = ft_strdup(node->path);
	else
		joinbuf2 = ft_strjoin(node->path, "/");
	joinbuf = ft_strjoin(joinbuf2, dirs->data);
	dirs->path = ft_strdup(joinbuf);
	if (ft_checkiflink(dirs->path))
	{
		lstat(dirs->path, &statbuf);
		readlink(dirs->path, dirs->linkval, 4095);
		dirs->linkval[4095] = '\0';
		dirs->islink = 1;
	}
	else
		lstat(dirs->path, &statbuf);
	dirs->acl = ft_getacl(dirs->path);
	ft_expandfilllistrec(dirs, statbuf);
	free(joinbuf2);
	free(joinbuf);
}
