/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 08:59:30 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/08 17:01:54 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../utils/lib.h"

size_t	bestindex(size_t index1, size_t index2, size_t len)
{
	size_t	index1_mov;
	size_t	index2_mov;

	if (index1 < len / 2)
		index1_mov = index1;
	else
		index1_mov = len - index1;
	if (index2 < len / 2)
		index2_mov = index2;
	else
		index2_mov = len - index2;
	if (index1_mov > index2_mov)
		return (index2);
	return (index1);
}

void	update_b(t_number *number, size_t index, size_t len)
{
	if (index < len / 2)
		while (index--)
			execute(number, "rb");
	else
		while (index++ < len)
			execute(number, "rrb");
	execute(number, "pa");
}

void	sort_b(t_number *number)
{
	size_t	len;
	size_t	index;
	size_t	min;
	size_t	top;

	len = getlen(number->b);
	top = 0;
	while (number->b)
	{
		min = getindex(number->b, getmin(number->b));
		index = bestindex(min, getindex(number->b, getmax(number->b)), len);
		update_b(number, index, len);
		if (index == min)
			execute(number, "ra");
		else
			top++;
		len--;
	}
	while (top--)
		execute(number, "ra");
}

size_t	sort_partition(t_number *number, size_t indexmax, ssize_t pivot)
{
	size_t	len_total;
	size_t	len;

	len = getlen(number->a) - indexmax;
	while (number->a && indexmax--)
		if (number->a->data <= pivot)
			execute(number, "pb");
		else
			execute(number, "ra");
	len_total = getlen(number->a);
	if (len < len_total)
	{
		if (len < len_total / 2)
			while (len--)
				execute(number, "ra");
		else
			while (len++ < len_total)
				execute(number, "rra");
	}
	len = getlen(number->b);
	sort_b(number);
	return (len);
}

void	sort(t_number *number)
{
	size_t	len;
	size_t	division;
	size_t	index;
	size_t	indexmax;

	len = getlen(number->a);
	division = len / 50;
	if (len > len / 50 * 50)
		division++;
	indexmax = len;
	index = 0;
	while (index++ < division)
		indexmax -= sort_partition(number, indexmax,
			getpivot(*number, index, division));
}
