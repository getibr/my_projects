/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_fn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srigil <srigil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 15:48:42 by lminta            #+#    #+#             */
/*   Updated: 2019/02/19 19:35:05 by srigil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_min(int a, int b, int c)
{
	if (a < b)
	{
		if (a < c)
			return (a);
		else
			return (c);
	}
	else
	{
		if (b < c)
			return (b);
		else
			return (c);
	}
	return (0);
}

void	sq_sq(int i, int j, int size, t_max_square *bsq)
{
	bsq->size = size;
	bsq->i = i;
	bsq->j = j;
}

int	ft_str_is_numeric(char *str)
{
	int i;
	int flag;

	flag = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < '0') || (str[i] > '9'))
			flag = 0;
		i++;
	}
	return (flag);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_realloc(char *str, char simv, int count)
{
	char	*str_new;
	int		i;

	i = 0;
	str_new = (char *)malloc(sizeof(char) * (count + 2));
	while ((str[i] != '\0'))
	{
		str_new[i] = str[i];
		i++;
	}
	str_new[i] = simv;
	i++;
	str_new[i] = '\0';
	free(str);
	return (str_new);
}
