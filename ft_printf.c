/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:33:52 by psan-gre          #+#    #+#             */
/*   Updated: 2019/12/11 09:35:19 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	ft_printf(const char *str, ...)
{
	int		out;
	int		i;
	va_list	argsptr;
	t_flags flags;

	out = 0;
	i = 0;
	va_start(argsptr, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			flags = check_flags(&(str[++i]), argsptr);
			i += flags.i;
			if (str[i] != '\0' && ft_is_data_type(str[i]))
				out = ft_write_case(str[i], argsptr, flags, out) + out;
		}
		else
			out += write(1, &str[i], 1);
		if (str[i] != '\0')
			i++;
	}
	va_end(argsptr);
	return (out);
}
