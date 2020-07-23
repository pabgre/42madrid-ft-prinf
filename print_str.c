/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:39:58 by psan-gre          #+#    #+#             */
/*   Updated: 2019/11/28 18:55:27 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static int		ft_putstrn(char *s, int n)
{
	int i;
	int out;

	out = 0;
	i = 0;
	while (s[i] != '\0' && i != n)
	{
		out += write(1, &s[i], 1);
		i++;
	}
	return (out);
}

static int		ft_str_lenght(char *s, t_flags flags)
{
	int aux;

	aux = s != NULL ? ft_strlen(s) : 6;
	aux = (flags.prec < aux && flags.prec != -1) ? flags.prec : aux;
	return (aux);
}

int				ft_putstr_master(char *s, t_flags flags)
{
	int out;
	int nb_zeroes;
	int nb_spaces;

	if (s == NULL)
		s = "(null)";
	nb_spaces = flags.spaces - ft_str_lenght(s, flags);
	out = 0;
	if (flags.align == 1 && !flags.zeroes)
		out += ft_print_spaces(nb_spaces);
	if (flags.zeroes == true)
		out += ft_print_zeroes(nb_spaces);
	nb_zeroes = flags.prec - ft_strlen(s);
	out += ft_putstrn(s, flags.prec);
	if (flags.align == -1)
		out += ft_print_spaces(nb_spaces);
	return (out);
}
