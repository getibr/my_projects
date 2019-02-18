/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srigil <srigil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 10:59:14 by srigil            #+#    #+#             */
/*   Updated: 2019/02/17 20:41:41 by srigil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_putnbr_str(int nb, char *str, int i)
{
	int				count;
	unsigned int	nb_long;

	count = 1;
	if (nb < 0)
	{
		str[i] = ('-');
		nb_long = -nb;
		i++;
	}
	else
	{
		nb_long = nb;
	}
	while (nb_long / count >= 10)
		count = count * 10;
	while (count > 0)
	{
		str[i] = (nb_long / count + 48);
		nb_long = nb_long % count;
		count = count / 10;
		i++;
	}
	return (str);
}
