/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srigil <srigil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 10:59:14 by srigil            #+#    #+#             */
/*   Updated: 2019/02/17 20:41:41 by srigil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putnbr(int nb)
{
	int				count;
	unsigned int	nb_long;

	count = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb_long = -nb;
	}
	else
	{
		nb_long = nb;
	}
	while (nb_long / count >= 10)
	{
		count = count * 10;
	}
	while (count > 0)
	{
		ft_putchar(nb_long / count + 48);
		nb_long = nb_long % count;
		count = count / 10;
	}
}
