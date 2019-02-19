/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srigil <srigil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:54:02 by srigil            #+#    #+#             */
/*   Updated: 2019/02/19 19:15:08 by srigil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_print_str(int **mas, t_max_square list, t_map_info info, int i)
{
	int j;

	j = 0;
	while (j < info.width)
	{
		if (((mas[i][j]) != 0) && !(((i > list.i - list.size) &&
		(i <= list.i)) && ((j > list.j - list.size) && (j <= list.j))))
			ft_putchar(info.empty);
		else if ((mas[i][j]) == 0)
			ft_putchar(info.obstacle);
		else if (((i > list.i - list.size) && (i <= list.i)) &&
		((j > list.j - list.size) && (j <= list.j)))
			ft_putchar(info.full);
		j++;
	}
}

void	ft_print(int **mas, t_max_square list, t_map_info info)
{
	int i;

	i = 0;
	while (i < info.len)
	{
		ft_print_str(mas, list, info, i);
		ft_putchar('\n');
		i++;
	}
}
