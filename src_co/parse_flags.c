/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 20:29:10 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/01 17:51:53 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

/*
** Function parse the array of args for the presence of flags.
** And movement the pointer to a position other than flags.
** Returns a bit field:
** 						0000 0001 -> f
**						0000 0010 -> v
**						0000 0100 -> d
**						0000 1000 -> h
*/

char				parse_flags(int *ac, char ***av)
{
	int				i;
	char			flag;

	i = 0;
	flag = 0;
	while (--*ac)
		if ((*(++*av))[i] == '-')
		{
			while ((**av)[++i])
				if ((**av)[i] == 'f')
					flag |= 1;
				else if ((**av)[i] == 'v')
					flag |= 2;
				else if ((**av)[i] == 'd')
					flag |= 4;
				else if ((**av)[i] == 'h')
					flag |= 8;
				else
					return (0);
			i = 0;
		}
		else
			break ;
	return (flag);
}
