/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:50:40 by psan-gre          #+#    #+#             */
/*   Updated: 2019/12/11 09:34:42 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H
# include "t_flags.h"
# include "libraries.h"

int		ft_print_spaces(int nb_spaces);
int		ft_print_zeroes(int nb_zeroes);
t_flags	check_flags(const char *str, va_list argptr);
bool	ft_is_data_type(const char c);
int		ft_write_case(char c_type, va_list argsptr, t_flags f, int out);
int		ft_putnbr_master(int n, t_flags flags);
int		ft_putnbr(unsigned int n, bool start);
int		ft_putchar_master(int c, t_flags flags);
int		ft_putchar(int c);
int		ft_putstr_master(char *s, t_flags flags);
int		ft_puthex_master(int x, bool isupper, t_flags flags);
int		ft_putuns_master(unsigned int n, t_flags flags);
int		ft_putmem_master(unsigned long p, t_flags flags);
int		ft_putfloat_master(float x, t_flags flags);
bool	ft_chrstr(char c, char *str);
int		ft_atoi(const char *str, t_flags *flags);
#endif
