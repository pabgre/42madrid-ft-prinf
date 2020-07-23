/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_flags.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psan-gre <psan-gre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:50:35 by psan-gre          #+#    #+#             */
/*   Updated: 2019/12/11 10:33:08 by psan-gre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FLAGS_H
# define T_FLAGS_H
# include "libraries.h"

typedef struct	s_flags
{
	bool	zeroes;
	int		spaces;
	int		prec;
	int		align;
	bool	point;
	int		i;
	int		plus;
	bool	hastag;
}				t_flags;
#endif
