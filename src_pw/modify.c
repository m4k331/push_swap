/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:09:56 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/01 15:55:36 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

/*
** Reduces the number of instructions
*/

void			modify_instruction(t_ps *ps)
{
	papb(ps);
	rarra_rbrrb(ps);
	rr(ps);
	rrr(ps);
	ss(ps);
	ft_lstrev(&ps->ins);
}
