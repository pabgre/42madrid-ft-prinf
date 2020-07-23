/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:59:48 by psan-gre          #+#    #+#             */
/*   Updated: 2019/12/11 10:38:39 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static int	ft_hex_digit(int x)
{
	int size;

	size = 0;
	if (x < 0)
		return (8);
	else if (x == 0)
		return (1);
	while (x != 0)
	{
		size++;
		x = x / 16;
	}
	return (size);
}

static int	ft_puthex(unsigned int value, bool isupper, bool start)
{
	int out;
	int upper;

	out = 0;
	upper = isupper ? -32 : 0;
	if (value != 0)
	{
		out += ft_puthex(value / 16, isupper, false);
		if (value % 16 >= 10)
			out += ft_putchar('a' + upper + value % 16 % 10);
		else
			out += ft_putchar('0' + value % 16);
	}
	else if (start)
		out += write(1, "0", 1);
	return (out);
}

static int	ft_hex_lenght(unsigned int x, t_flags flags)
{
	int aux;

	aux = ft_hex_digit(x);
	aux = flags.prec > aux ? flags.prec : aux;
	if (x == 0 && flags.prec == 0)
		aux--;
	if (flags.hastag)
		aux += 2;
	return (aux);
}

int			ft_puthex_master(int x, bool isupper, t_flags flags)
{
	int out;
	int nb_zeroes;
	int nb_spaces;

	nb_spaces = flags.spaces - ft_hex_lenght(x, flags);
	out = 0;
	if (flags.align == 1 && !flags.zeroes)
		out += ft_print_spaces(nb_spaces);
	if (flags.hastag)
	{
		isupper ? (out += write(1, "0X", 2)) : (out += write(1, "0x", 2));
	}
	if (flags.zeroes == true)
		out += ft_print_zeroes(nb_spaces);
	nb_zeroes = flags.prec - ft_hex_digit(x);
	out += ft_print_zeroes(nb_zeroes);
	out += ft_puthex(x, isupper, (flags.prec != 0));
	if (flags.align == -1)
		out += ft_print_spaces(nb_spaces);
	return (out);
}
