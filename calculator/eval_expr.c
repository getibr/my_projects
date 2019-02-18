/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srigil <srigil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 21:25:15 by srigil            #+#    #+#             */
/*   Updated: 2019/02/17 20:41:45 by srigil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		eval_expr(char *str)
{
	int i;

	str = ft_bez_probelov(str);
	i = ft_vnutr_sk(str);
	while (ft_vnutr_sk_count(str) >= 0)
	{
		if (ft_vnutr_sk_count(str) == 0)
		{
			str = ft_calk(str);
			break ;
		}
		else
		{
			i = ft_vnutr_sk(str);
			str = ft_vnutr_stroka(str, i);
		}
	}
	return (ft_atoi(str));
}

char	*ft_bez_probelov(char *str)
{
	int		i;
	int		j;
	char	*str_exit;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	str_exit = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			i++;
		else
		{
			str_exit[j] = str[i];
			i++;
			j++;
		}
	}
	str_exit[j] = '\0';
	return (str_exit);
}

char	*ft_vnutr_stroka(char *str, int i)
{
	int		k;
	int		count;
	char	*str_vn;

	k = 0;
	count = 0;
	i = i + 1;
	k = i;
	while (str[k] != ')')
	{
		count++;
		k++;
	}
	k = 0;
	str_vn = (char *)malloc(sizeof(char) * (count + 1));
	while (str[i] != ')')
	{
		str_vn[k] = str[i];
		k++;
		i++;
	}
	str_vn[k] = '\0';
	str_vn = ft_calk(str_vn);
	str = ft_minus_skobki(str, str_vn, i);
	return (str);
}

char	*ft_minus_skobki(char *str, char *str_vn, int i)
{
	int j;
	int flag;

	j = 0;
	flag = 0;
	while (str[i] != '(')
	{
		str[i] = ' ';
		i--;
	}
	if ((i != 0) && (str[i - 1] == '-' && str_vn[0] == '-'))
	{
		str[i - 1] = '+';
		str_vn[0] = ' ';
		j++;
	}
	str[i] = ' ';
	while (str_vn[j] != ' ' && str_vn[j] != '\0')
	{
		str[i] = str_vn[j];
		i++;
		j++;
	}
	str = ft_bez_probelov(str);
	return (str);
}

int		ft_vnutr_sk(char *str)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (str[k] != '\0')
	{
		if (str[k] == '(')
		{
			i = k;
		}
		k++;
	}
	return (i);
}
