/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 18:40:48 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/06/04 18:40:52 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printone(t_lst *dirs, t_cti *cticrutch)
{
	if (cticrutch->inode)
		ft_printinode(dirs);
	if (cticrutch->color)
	{
		ft_setcolor(dirs->color);
		ft_putstr(dirs->data);
		ft_resetcolor();
	}
	else
		ft_putstr(dirs->data);	
	if (cticrutch->type)
		ft_putstr(dirs->typesymbol);
	write(1, "\n", 1);
}

void	ft_printaclxattr(t_lst *dirs, t_flags *flags)
{
	if (flags->aclcrutch)
	{
		if (dirs->acl != '0')
		{
			write(1, &dirs->acl, 1);
		}
		else if (dirs->acl == '0' && flags->aclcrutch)
			write(1, " ", 1);
		write(1, " ", 1);
	}
}
