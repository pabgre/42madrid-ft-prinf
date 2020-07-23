/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:31:22 by psan-gre          #+#    #+#             */
/*   Updated: 2019/11/29 08:32:02 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static int		ft_uns_digit(unsigned int n)
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

static int		ft_putuns(unsigned int n, bool start)
{
	int out;

	out = 0;
	if (n != 0)
	{
		if (n >= 10)
			out += ft_putuns(n / 10, false);
		n = (n % 10) + 48;
		out += write(1, &n, 1);
	}
	else if (start)
		out += write(1, "0", 1);
	return (out);
}

static int		ft_uns_lenght(int nb, t_flags flags)
{
	int aux;

	aux = ft_uns_digit(nb);
	aux = (flags.prec > aux) ? flags.prec : aux;
	aux = (nb == 0 && flags.prec == 0) ? 0 : aux;
	return (aux);
}

int				ft_putuns_master(unsigned int n, t_flags flags)
{
	int out;
	int nb_zeroes;
	int nb_spaces;

	nb_spaces = flags.spaces - ft_uns_lenght(n, flags);
	out = 0;
	if (flags.align == 1 && !flags.zeroes)
		out += ft_print_spaces(nb_spaces);
	if (flags.zeroes == true)
		out += ft_print_zeroes(nb_spaces);
	nb_zeroes = flags.prec - ft_uns_digit(n);
	out += ft_print_zeroes(nb_zeroes);
	out += ft_putuns(n, (flags.prec != 0));
	if (flags.align == -1)
		out += ft_print_spaces(nb_spaces);
	return (out);
}
