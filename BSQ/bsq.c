/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srigil <srigil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:17:32 by lminta            #+#    #+#             */
/*   Updated: 2019/02/19 20:02:50 by srigil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int				*char_to_int(t_map_info *info, char *buff, t_max_square *bsq)
{
	int		i;
	int		*str;

	str = (int*)malloc(sizeof(int) * info->width);
	i = 0;
	while (buff[i])
	{
		if (buff[i] == info->empty)
		{
			str[i] = 1;
			if (str[i] > bsq->size)
					sq_sq(0, i, 1, bsq);
		}
		else if (buff[i] == info->obstacle)
			str[i] = 0;
		else
			return (0);
		i++;
	}
	free(buff);
	return (str);
}

int				*first_line(t_map_info *info, int fd, t_max_square *bsq)
{
	char	c;
	char	*buff;

	buff = (char*)malloc(sizeof(char));
	*buff = '\0';
	info->width = 0;
	if (read(fd, &c, 1) == -1)
		return (0);
	while (c != '\n')
	{
		buff = ft_realloc(buff, c, info->width);
		read(fd, &c, 1);
		info->width++;
	}
	buff[info->width] = '\0';
	return (char_to_int(info, buff, bsq));
}

int				fill_map(int fd, int ***map, t_map_info *info, t_max_square *bsq)
{
	int 	i;
	int 	j;
	char	*buff;

	i = 1;
	buff = (char*)malloc(sizeof(char) * (info->width + 1));
	while (i < info->len)
	{
		j = 0;
		read(fd, buff, info->width + 1);
		while (j < info->width)
		{
			if (j == 0 && buff[j] == info->empty)
				map[0][i][j] = 1;
			else if (buff[j] == info->obstacle)
					map[0][i][j] = 0;
			else if(buff[j] == info->empty)
				map[0][i][j] = ft_min(map[0][i-1][j], map[0][i][j-1], map[0][i-1][j-1]) + 1;
			else
				return (-1);
			if (map[0][i][j] > bsq->size)
				sq_sq(i, j, map[0][i][j], bsq);
			j++;
		}
		i++;
	}
	return (0);
}

void				ft_bsq(int fd, t_map_info info)
{
	t_max_square	bsq;
	int				i;
	int				**map;

	bsq.i = -1;
	bsq.j = -1;
	bsq.size = 0;
	map = (int **)malloc(sizeof(int*) * info.len);
	map[0] = first_line(&info, fd, &bsq);
	i = 1;
	while (i < info.len)
	{
		map[i] = (int *)malloc(sizeof(int) * info.width);
		i++;
	}
	fill_map(fd, &map, &info, &bsq);
	ft_print(map, bsq, info);
	//return (0);
}

int main(int argc, char **argv)
{
	int fd;
	int i;

	i = 1;
	fd = 0;
	if (argc < 2)
		ft_bsq(fd, ft_params(fd));
	else
	{
		while (i < argc)
		{
			if ((fd = open(argv[i], O_RDONLY)) == -1)
			{
				write(2, "map error\n", 10);
				break ;
			}
			ft_bsq(fd, ft_params(fd));
			i++;
		}
	}
	return (0);
}
