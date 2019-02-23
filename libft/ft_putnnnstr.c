/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnnnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 15:06:10 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/06/05 15:06:12 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnnnstr(const char *str, int start, int end)
{
	while (start < end)
	{
		ft_putchar(str[start]);
		start++;
	}
}
