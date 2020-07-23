/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:32:48 by psan-gre          #+#    #+#             */
/*   Updated: 2019/11/29 08:38:26 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	ft_print_spaces(int nb_spaces)
{
	int out;

	out = 0;
	while (nb_spaces > 0)
	{
		out += write(1, " ", 1);
		nb_spaces--;
	}
	return (out);
}

int	ft_print_zeroes(int nb_zeroes)
{
	int out;

	out = 0;
	while (nb_zeroes > 0)
	{
		out += write(1, "0", 1);
		nb_zeroes--;
	}
	return (out);
}
