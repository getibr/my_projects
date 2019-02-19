/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srigil <srigil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:20:50 by srigil            #+#    #+#             */
/*   Updated: 2019/02/19 16:39:40 by srigil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_map_info	ft_params(int fd)
{
	t_map_info	list;
	int			count;
	char		buf;
	char		*first_str;

	count = 0;
	read(fd, &buf, 1);
	first_str = (char *)malloc(sizeof(char));
	*first_str = '\0';
	while ((buf != '\n') && (buf != '\0'))
	{
		first_str = ft_realloc(first_str, buf, count);
		read(fd, &buf, 1);
		count++;
	}
	list = ft_params_unpack(first_str, count);
	free(first_str);
	return (list);
}

t_map_info	ft_params_unpack(char *first_str, int i)
{
	t_map_info	list;
	char		*str_numb;
	int			j;

	j = 0;
	list.full = first_str[i - 1];
	list.obstacle = first_str[i - 2];
	list.empty = first_str[i - 3];
	str_numb = (char *)malloc(sizeof(char) * (i - 3));
	while (j < (i - 3))
	{
		str_numb[j] = first_str[j];
		j++;
	}
	str_numb[j] = '\0';
	if (ft_str_is_numeric(str_numb) == 1)
		list.len = ft_atoi(str_numb);
	free(str_numb);
	return (list);
}
