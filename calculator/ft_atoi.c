/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srigil <srigil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 09:42:04 by srigil            #+#    #+#             */
/*   Updated: 2019/02/17 20:41:44 by srigil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_atoi(char *str)
{
	int number;
	int n;
	int znak;

	n = 10;
	znak = 0;
	number = 0;
	while ((*str == ' ') || (*str == '\f') || (*str == '\n') ||
			(*str == '\r') || (*str == '\t') || (*str == '\v'))
		str++;
	if (*str == '-')
		znak = -1;
	else if (*str == '+')
		znak = 1;
	if (znak != 0)
		str++;
	while ((*str >= '0') && (*str <= '9'))
	{
		number = number * n + (*str - 48);
		str++;
	}
	if (znak == -1)
		number = -1 * number;
	return (number);
}
