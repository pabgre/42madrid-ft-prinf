/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:39:48 by psan-gre          #+#    #+#             */
/*   Updated: 2019/11/29 08:34:14 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static int	ft_mem_digit(unsigned long p)
{
	if (p != 0)
		return (1 + ft_mem_digit(p / 16));
	else
		return (2);
}

static int	ft_print_mem(unsigned long value, bool start)
{
	int out;

	out = 0;
	if (value != 0)
	{
		out += ft_print_mem(value / 16, false);
		if (value % 16 >= 10)
			out += ft_putchar('a' + value % 16 % 10);
		else
			out += ft_putchar('0' + value % 16);
	}
	else if (start)
		out += write(1, "0", 1);
	return (out);
}

static int	ft_mem_lenght(unsigned long p, t_flags flags)
{
	int aux;

	aux = ft_mem_digit(p);
	aux = flags.prec > aux ? flags.prec : aux;
	aux += p == 0 ? 1 : 0;
	aux = flags.prec == 0 ? 2 : aux;
	return (aux);
}

int			ft_putmem_master(unsigned long p, t_flags flags)
{
	int out;
	int nb_zeroes;
	int nb_spaces;

	nb_spaces = flags.spaces - ft_mem_lenght(p, flags);
	out = 0;
	if (flags.align == 1 && !flags.zeroes)
		out += ft_print_spaces(nb_spaces);
	out += write(1, "0x", 2);
	if (flags.zeroes == true)
		out += ft_print_zeroes(nb_spaces);
	nb_zeroes = flags.prec - ft_mem_digit(p);
	out += ft_print_zeroes(nb_zeroes);
	out += ft_print_mem(p, flags.prec != 0);
	if (flags.align == -1)
		out += ft_print_spaces(nb_spaces);
	return (out);
}
