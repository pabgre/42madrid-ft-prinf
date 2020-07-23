/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:34:07 by psan-gre          #+#    #+#             */
/*   Updated: 2019/11/29 08:37:53 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	ft_atoi(const char *str, t_flags *flags)
{
	int					i;
	unsigned long long	num;

	i = 0;
	num = 0;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		if (num > __LONG_LONG_MAX__ || i >= 19)
			return (-1);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	flags->i += i - 1;
	return (num);
}
