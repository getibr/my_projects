/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srigil <srigil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:00:54 by lminta            #+#    #+#             */
/*   Updated: 2019/02/19 19:04:51 by srigil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h>

typedef struct	s_max_square
{
	int		size;
	int		i;
	int		j;
}				t_max_square;

typedef struct	s_map_info
{
	int		len;
	int 	width;
	char	empty;
	char	obstacle;
	char	full;
}				t_map_info;

char		*ft_realloc(char *str, char simv, int count);
int			ft_strlen(char *str);
int			ft_min(int a, int b, int c);
t_map_info	ft_params(int fd);
t_map_info	ft_params_unpack(char *first_str, int i);
int			ft_atoi(char *str);
int			ft_str_is_numeric(char *str);
void		ft_putchar(char c);
void		sq_sq(int i, int j, int size, t_max_square *bsq);
void	ft_print(int **mas, t_max_square list, t_map_info info);

#endif
