/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srigil <srigil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 20:27:26 by srigil            #+#    #+#             */
/*   Updated: 2019/02/17 20:41:46 by srigil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_numb_next_2(char *str, int i, int flag)
{
	int numb;
	int razr;

	razr = 1;
	numb = 0;
	while (str[i] != '*' && str[i] != '/' && str[i] != '%'
	&& str[i] != '+' && str[i] != '-' && str[i] != '\0')
		i++;
	i--;
	while (str[i] != '*' && str[i] != '/' && str[i] != '%'
	&& str[i] != '+' && str[i] != '-' && i != 0)
	{
		numb = numb + razr * (str[i] - '0');
		razr = razr * 10;
		i--;
	}
	if (flag == 1)
		return (-numb);
	return (numb);
}

char	*ft_znak_s_minusom(char *str)
{
	int n1;
	int n2;
	int n3;
	int i;

	i = 0;
	n2 = 0;
	n1 = ft_atoi(str);
	i++;
	while ((str[i] != '+' && str[i] != '-') && str[i] != '\0')
		i++;
	n2 = ft_numb_next(str, i);
	n3 = ft_operats(str, n1, n2, i);
	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ' ';
		i++;
	}
	i = 0;
	str = ft_putnbr_str(n3, str, i);
	str = ft_bez_probelov(str);
	return (str);
}

int		ft_perv_umn(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '*' || str[i] == '/' || str[i] == '%')
			return (i);
		i++;
	}
	return (0);
}

int		ft_count_znak(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '*' || str[i] == '/' ||
		str[i] == '%' || str[i] == '+' || str[i] == '-')
			count++;
		i++;
	}
	return (count);
}

int		ft_count_numb(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0')
			count++;
		i++;
	}
	return (count);
}
