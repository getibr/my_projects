/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srigil <srigil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 20:28:34 by srigil            #+#    #+#             */
/*   Updated: 2019/02/17 20:41:46 by srigil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_numb_prev(char *str, int i)
{
	int numb;
	int razr;

	numb = 0;
	razr = 1;
	i--;
	while (str[i] != '*' && str[i] != '/' && str[i] != '%'
	&& str[i] != '+' && str[i] != '-' && i >= 0)
	{
		numb = numb + razr * (str[i] - '0');
		razr = razr * 10;
		i--;
	}
	return (numb);
}

int		ft_numb_next(char *str, int i)
{
	int flag;

	flag = 0;
	i++;
	if (str[i] == '-')
	{
		i++;
		flag = 1;
	}
	return (ft_numb_next_2(str, i, flag));
}

int		ft_vnutr_sk_count(char *str)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (str[k] != '\0')
	{
		if (str[k] == '(')
		{
			i++;
		}
		k++;
	}
	return (i);
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
