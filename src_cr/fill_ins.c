/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:54:22 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/02 23:12:15 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#define ALL(x, self) ((x) == 'a' || (x) == 'b' || (x) == (self))

/*
** The function returns the number of characters to split
*/

static int			len_split_str(char *str, char c)
{
	int				len;

	len = 0;
	while (*str && *str++ != c)
		len++;
	return (len);
}

/*
** Function checks the validity of instructions and returns code instructions:
** 0 swap
** 1 put
** 2 rotate
** 3 reverse rotate
** -1 in case error
*/

static int			valid_ins(char *ins, int len)
{
	if (len == 2 || len == 3)
	{
		if (*ins == 's' && ALL(ins[1], 's') && ins[2] == '\n')
			return (0);
		if (*ins == 'p' && (ins[1] == 'a' || ins[1] == 'b') && ins[2] == '\n')
			return (1);
		if (*ins == 'r' && ALL(ins[1], 'r') && ins[2] == '\n')
			return (2);
		if (*ins == 'r' && ins[1] == 'r' && ALL(ins[2], 'r') && ins[3] == '\n')
			return (3);
	}
	return (-1);
}

/*
** The function fill ins takes a strings that contains instructions
** returns 0 if successful, otherwise returns 1
** NOTE: the function is not protected
*/

static int			fill_ins2instructions(t_list **ins, char *vals)
{
	t_list			*lst;
	size_t			code;
	int				len;

	len = 0;
	while (*vals && ((len = len_split_str(vals, 10)) + 1))
		if ((code = valid_ins(vals, len)) != -1)
		{
			*(vals + len) = 0;
			if ((lst = ft_lstnew(vals, len + 1)))
			{
				lst->content_size = code;
				ft_lstaddlast(ins, lst);
			}
			else
				return (1);
			vals += len + 1;
		}
		else
			break ;
	return (*vals);
}

/*
** The function filled list ins with an instructions and add code ins
** In case of invalid input, the function clears the stack and return -1
*/

int					fill_ins(t_list **ins, char *vals)
{
	if (fill_ins2instructions(ins, vals))
	{
		ft_lstdel(ins, del_content);
		return (-1);
	}
	return (0);
}
