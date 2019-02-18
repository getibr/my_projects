/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srigil <srigil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 16:45:45 by srigil            #+#    #+#             */
/*   Updated: 2019/02/17 20:41:43 by srigil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_calk(char *str)
{
	int i;
	int count_znak;

	count_znak = 0;
	str = ft_ubir_perv_plus(str);
	count_znak = ft_count_znak(str);
	i = ft_perv_umn(str);
	while (i != 0)
	{
		str = ft_deistvie(str, i);
		str = ft_plus_minus(str);
		i = ft_perv_umn(str);
		str = ft_ubir_perv_plus(str);
	}
	while ((ft_count_numb(str) != 1 && str[0] == '-')
	|| (str[0] != '-' && ft_count_numb(str) != 0))
	{
		str = ft_summa(str);
		str = ft_plus_minus(str);
	}
	str = ft_null(str);
	str = ft_bez_probelov(str);
	return (str);
}

char	*ft_plus_minus(char *str)
{
	int i;

	i = 0;
	while (str[i + 1] != '\0')
	{
		if (str[i] == '-' && str[i + 1] == '-')
		{
			str[i] = '+';
			str[i + 1] = ' ';
		}
		if (str[i] == '+' && str[i + 1] == '-')
		{
			str[i] = '-';
			str[i + 1] = ' ';
		}
		i++;
	}
	str = ft_bez_probelov(str);
	return (str);
}

char	*ft_deistvie(char *str, int i)
{
	int n1;
	int n2;
	int n3;

	n1 = ft_numb_prev(str, i);
	n2 = ft_numb_next(str, i);
	n3 = ft_operats(str, n1, n2, i);
	str = ft_del_numb(str, i, n3);
	str = ft_bez_probelov(str);
	return (str);
}

char	*ft_del_numb(char *str, int i, int nbr)
{
	str[i] = ' ';
	i++;
	if (str[i] == '-')
	{
		str[i] = ' ';
		i++;
	}
	while (str[i] != '*' && str[i] != '/' && str[i] != '%' &&
	str[i] != '+' && str[i] != '-' && str[i] != '\0')
	{
		str[i] = ' ';
		i++;
	}
	i--;
	while (str[i] != '*' && str[i] != '/' && str[i] != '%' &&
	str[i] != '+' && str[i] != '-' && i >= 0)
	{
		str[i] = ' ';
		i--;
	}
	i++;
	str = ft_putnbr_str(nbr, str, i);
	return (str);
}

int		ft_operats(char *str, int n1, int n2, int i)
{
	if (str[i] == '+')
		return (n1 + n2);
	if (str[i] == '-')
		return (n1 - n2);
	if (str[i] == '/')
		return (n1 / n2);
	if (str[i] == '*')
		return (n1 * n2);
	if (str[i] == '%')
		return (n1 % n2);
	return (0);
}
