/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:33:46 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/09 21:24:16 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../utils/lib.h"

void	sort_three(t_number *number)
{
	size_t	index;

	if (!number->a || !number->a->next || check(number->a))
		return ;
	index = getindex(number->a, getmax(number->a));
	if (index == 0)
		execute(number, "ra");
	else if (index == 1)
		execute(number, "rra");
	if (number->a->data > number->a->next->data)
		execute(number, "sa");
}

void	sort_small(t_number *number)
{
	size_t	index;
	size_t	len;

	while ((len = getlen(number->a)) > 3)
	{
		index = getindex(number->a, getmin(number->a));
		if (index < len / 2)
			while (index--)
				execute(number, "ra");
		else
			while (index++ < len)
				execute(number, "rra");
		execute(number, "pb");
	}
	sort_three(number);
	while (number->b)
		execute(number, "pa");
}
