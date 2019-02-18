/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srigil <srigil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 20:26:26 by srigil            #+#    #+#             */
/*   Updated: 2019/02/17 20:41:47 by srigil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_summa(char *str)
{
	int n1;
	int n2;
	int i;

	i = 0;
	n1 = 0;
	n2 = 0;
	n1 = ft_atoi(str);
	if (str[0] == '-')
		i++;
	while (str[i] != '-' && str[i] != '+' && str[i] != '\0')
		i++;
	if (str[i] != '\0')
		i++;
	return (ft_summa_2(str, i, n1, n2));
}

char	*ft_summa_2(char *str, int i, int n1, int n2)
{
	int razr;
	int n3;

	razr = 1;
	while (str[i] != '+' && str[i] != '-' && str[i] != '\0')
		i++;
	i--;
	while ((str[i] != '+' && str[i] != '-' && i != 0))
	{
		n2 = n2 + razr * (str[i] - '0');
		razr = razr * 10;
		i--;
	}
	n3 = ft_operats(str, n1, n2, i);
	str = ft_summa_number(str, 0, n3);
	str = ft_bez_probelov(str);
	return (str);
}

char	*ft_summa_number(char *str, int i, int nbr)
{
	if (str[i] == '-')
	{
		str[i] = ' ';
		i++;
	}
	while (str[i] != '+' && str[i] != '-' && str[i] != '\0')
	{
		str[i] = ' ';
		i++;
	}
	if (str[i] != '\0')
	{
		str[i] = ' ';
		i++;
	}
	while (str[i] != '+' && str[i] != '-' && str[i] != '\0')
	{
		str[i] = ' ';
		i++;
	}
	str = ft_putnbr_str(nbr, str, 0);
	return (str);
}

char	*ft_ubir_perv_plus(char *str)
{
	if (str[0] == '+')
	{
		str[0] = ' ';
	}
	str = ft_bez_probelov(str);
	return (str);
}

char	*ft_null(char *str)
{
	if (str[0] == '-' && str[1] == '0')
		str[0] = ' ';
	return (str);
}
