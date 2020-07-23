/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:38:39 by psan-gre          #+#    #+#             */
/*   Updated: 2019/12/11 10:10:10 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static int	ft_nb_digit(int n)
{
	int size;

	size = 0;
	if (n == 0)
		size++;
	while (n != 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

int			ft_putnbr(unsigned int n, bool start)
{
	int out;

	out = 0;
	if (n != 0)
	{
		if (n >= 10)
			out += ft_putnbr(n / 10, false);
		n = (n % 10) + 48;
		out += write(1, &n, 1);
	}
	else if (start)
		out += write(1, "0", 1);
	return (out);
}

static int	ft_nb_lenght(int nb, t_flags flags)
{
	int aux;

	aux = ft_nb_digit(nb);
	aux = (flags.prec > aux) ? flags.prec : aux;
	aux = (nb == 0 && flags.prec == 0) ? 0 : aux;
	aux += (nb < 0) ? 1 : 0;
	aux += flags.plus ? 1 : 0;
	return (aux);
}

int			ft_putnbr_master(int n, t_flags flags)
{
	int				out;
	unsigned int	nb;
	int				nb_zeroes;
	int				nb_spaces;

	nb_spaces = flags.spaces - ft_nb_lenght(n, flags);
	out = 0;
	if (flags.align == 1 && !flags.zeroes)
		out += ft_print_spaces(nb_spaces);
	if (n < 0)
		out += write(1, "-", 1);
	else if (flags.plus == -1)
		out += write(1, " ", 1);
	else if (flags.plus == 1)
		out += write(1, "+", 1);
	nb = n < 0 ? -n : n;
	if (flags.zeroes == true)
		out += ft_print_zeroes(nb_spaces);
	nb_zeroes = flags.prec - ft_nb_digit(n);
	out += ft_print_zeroes(nb_zeroes);
	out += ft_putnbr(nb, flags.prec != 0);
	if (flags.align == -1)
		out += ft_print_spaces(nb_spaces);
	return (out);
}
