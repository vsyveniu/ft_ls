/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_suppfuncs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 13:46:20 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/06/05 13:46:23 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lst	*ft_addnode(char *str)
{
	t_lst *tmp;

	if (!(tmp = (t_lst *)malloc(sizeof(t_lst))))
		return (0);
	tmp->data = str;
	tmp->next = NULL;
	return (tmp);
}

int		ft_checkiflink(char *str)
{
	struct stat	statbuf;

	if (str != NULL)
	{
		lstat(str, &statbuf);
		if (S_ISLNK(statbuf.st_mode))
			return (1);
	}
	return (0);
}

void	ft_ifsort2(t_lst **dirs, t_flags *flags)
{
	if (flags->f_t)
	{
		ft_sortbytime2(dirs);
		ft_reverse(dirs);
	}
	if (flags->f_r)
		ft_reverse(dirs);
}

char	ft_getacl(char *path)
{
	ssize_t			size;
	acl_t			acl;
	acl_entry_t		aclp;
	char			res;
	int				aclval;

	size = 0;
	aclval = 42;
	size = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
	acl = acl_get_file(path, ACL_TYPE_EXTENDED);
	aclval = acl_get_entry(acl, ACL_FIRST_ENTRY, &aclp);
	if (size > 0)
		res = '@';
	else if (aclval == 0)
		res = '+';
	else
		res = '0';
	acl_free(acl);
	return (res);
}

void	ft_getaclcrutch(t_flags *flags, t_lst *dirs)
{
	t_lst *head;

	head = dirs;
	while (head)
	{
		if (head->acl != '0')
			flags->aclcrutch = 1;
		head = head->next;
	}
}
