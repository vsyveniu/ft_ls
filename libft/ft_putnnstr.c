/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnnstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 15:06:36 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/06/05 15:06:38 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnnstr(const char *str, int start)
{
	while (str[start] != '\0')
	{
		ft_putchar(str[start]);
		start++;
	}
}
