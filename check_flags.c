/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:13:12 by psan-gre          #+#    #+#             */
/*   Updated: 2019/12/11 10:38:11 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

static	int		is_flag(char c)
{
	return (ft_chrstr(c, "-0.*123456789+ #"));
}

static	t_flags	ft_init_flags(t_flags *flags)
{
	flags->zeroes = false;
	flags->spaces = 0;
	flags->prec = -1;
	flags->align = 1;
	flags->point = false;
	flags->i = 0;
	flags->plus = 0;
	flags->hastag = false;
	return (*flags);
}

t_flags			refresh_flags(t_flags f)
{
	if (f.spaces < 0)
	{
		f.align = -1;
		f.spaces = -1 * (f.spaces);
		f.zeroes = false;
	}
	if (f.prec < 0)
		f.prec = -1;
	if (f.point)
	{
		f.zeroes = false;
	}
	(f.i)++;
	return (f);
}

static	t_flags	set_flags(const char *str, va_list argptr, t_flags f)
{
	if ((str[f.i] == '*' || ('0' < str[f.i] && str[f.i] <= '9'))\
	&& !f.point)
		f.spaces = (str[f.i] == '*') ? va_arg(argptr, int) :
		ft_atoi(&str[f.i], &f);
	else if ((str[f.i] == '*' || ('0' <= str[f.i] && str[f.i] <= '9'))\
	&& f.point)
		f.prec = (str[f.i] == '*') ? va_arg(argptr, int) :
		ft_atoi(&str[f.i], &f);
	else if (str[f.i] == '0' && f.align != -1)
		f.zeroes = true;
	else if (str[f.i] == '-')
		f.align = -1;
	else if (str[f.i] == '.')
	{
		f.prec = 0;
		f.point = true;
	}
	else if (str[f.i] == '+')
		f.plus = 1;
	else if (str[f.i] == ' ')
		f.plus = -1;
	else if (str[f.i] == '#')
		f.hastag = true;
	return (f);
}

t_flags			check_flags(const char *str, va_list argptr)
{
	t_flags f;

	f = ft_init_flags(&f);
	while (str[f.i] != '\0' && is_flag(str[f.i]))
	{
		f = set_flags(str, argptr, f);
		f = refresh_flags(f);
	}
	return (f);
}
