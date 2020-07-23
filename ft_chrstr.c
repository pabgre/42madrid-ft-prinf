/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:19:48 by psan-gre          #+#    #+#             */
/*   Updated: 2019/11/28 15:31:31 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

bool	ft_chrstr(char c, char *str)
{
	bool	out;
	int		i;

	out = false;
	i = 0;
	while (!out && str[i] != '\0')
	{
		out = (str[i] == c);
		i++;
	}
	return (out);
}
