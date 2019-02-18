/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srigil <srigil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:16:51 by srigil            #+#    #+#             */
/*   Updated: 2019/02/17 20:41:39 by srigil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H

# define FT_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putnbr(int nb);
int		ft_perv_umn(char *str);
char	*ft_deistvie(char *str, int i);
char	*ft_slozhen(char *str);
int		ft_numb_prev(char *str, int i);
int		ft_numb_next(char *str, int i);
int		ft_numb_next_2(char *str, int i, int flag);
int		ft_operats(char *str, int n1, int n2, int i);
char	*ft_minus_skobki(char *str, char *str_vn, int i);
int		ft_vnutr_sk_count(char *str);
int		eval_expr(char *str);
char	*ft_bez_probelov(char *str);
char	*ft_vnutr_stroka(char *str, int i);
char	*ft_calk(char *str_vn);
int		ft_vnutr_sk(char *str);
char	*ft_del_numb(char *str, int i, int nbr);
void	ft_putstr(char *str);
char	*ft_putnbr_str(int nb, char *str, int i);
void	ft_putchar(char c);
int		ft_count_znak(char *str);
int		ft_atoi(char *str);
char	*ft_znak_s_minusom(char *str);
char	*ft_plus_minus(char *str);
int		ft_count_numb(char *str);
char	*ft_summa(char *str);
char	*ft_summa_2(char *str, int i, int n1, int n2);
char	*ft_summa_number(char *str, int i, int nbr);
char	*ft_ubir_perv_plus(char *str);
char	*ft_null(char *str);

#endif
