/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:06:12 by psan-gre          #+#    #+#             */
/*   Updated: 2019/11/29 09:39:03 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	ft_putchar(int c)
{
	char aux;

	aux = (char)c;
	return (write(1, &aux, 1));
}

int	ft_putchar_master(int c, t_flags flags)
{
	int out;
	int nb_zeroes;
	int nb_spaces;

	nb_spaces = flags.spaces - 1;
	out = 0;
	if (flags.align == 1 && !flags.zeroes)
		out += ft_print_spaces(nb_spaces);
	if (flags.zeroes == true)
		out += ft_print_zeroes(nb_spaces);
	nb_zeroes = flags.prec - 1;
	out += ft_print_zeroes(nb_zeroes);
	out += ft_putchar(c);
	if (flags.align == -1)
		out += ft_print_spaces(nb_spaces);
	return (out);
}
