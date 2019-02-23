/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlongnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 15:04:56 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/06/05 15:05:32 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlongnbr(unsigned long long n)
{
	unsigned long long	i;

	i = n;
	if (i > 9)
	{
		ft_putlongnbr(i / 10);
		ft_putlongnbr(i % 10);
	}
	else
	{
		ft_putchar(i + '0');
	}
}
