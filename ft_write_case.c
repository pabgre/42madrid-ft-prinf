/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_case.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 09:05:49 by psan-gre          #+#    #+#             */
/*   Updated: 2019/12/11 09:41:09 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	ft_write_case(char c_type, va_list argsptr, t_flags f, int out)
{
	if (c_type == 'i' || c_type == 'd')
		return (ft_putnbr_master(va_arg(argsptr, int), f));
	else if (c_type == 'u')
		return (ft_putuns_master(va_arg(argsptr, unsigned int), f));
	else if (c_type == 'c')
		return (ft_putchar_master(va_arg(argsptr, int), f));
	else if (c_type == 's')
		return (ft_putstr_master(va_arg(argsptr, char*), f));
	else if (c_type == '%')
		return (ft_putchar_master('%', f));
	else if (c_type == 'x')
		return (ft_puthex_master(va_arg(argsptr, unsigned int), false, f));
	else if (c_type == 'X')
		return (ft_puthex_master(va_arg(argsptr, unsigned int), true, f));
	else if (c_type == 'p')
		return (ft_putmem_master(va_arg(argsptr, unsigned long), f));
	else if (c_type == 'n')
	{
		*va_arg(argsptr, int *) = out;
		return (0);
	}
	return (0);
}
