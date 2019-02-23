/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resetcolor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 19:05:16 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/06/04 19:05:24 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_setcolor(char *str)
{
	char *tmp;

	tmp = ft_strjoin(str, "");
	write(1, tmp, ft_strlen(tmp));
	free(tmp);
}

void	ft_resetcolor(void)
{
	char *tmp;

	tmp = ft_strjoin("\033[0m", "");
	write(1, tmp, ft_strlen(tmp));
	free(tmp);
}
