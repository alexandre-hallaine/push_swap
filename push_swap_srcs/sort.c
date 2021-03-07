/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 08:59:30 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/07 16:07:35 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../list.h"
#include "../utils/lib.h"

size_t	getlen(t_item *item)
{
	int	len;

	len = 0;
	while (item)
	{
		len++;
		item = item->next;
	}
	return (len);
}

ssize_t	gettotal(t_item *item)
{
	ssize_t	total;

	total = 0;
	while (item)
	{
		total += item->data;
		item = item->next;
	}
	return (total);
}

int		getmin(t_item *item)
{
	int	min;

	min = item->data;
	while (item->next)
	{
		item = item->next;
		if (item->data < min)
			min = item->data;
	}
	return (min);
}

int		getmax(t_item *item)
{
	int	max;

	max = item->data;
	while (item->next)
	{
		item = item->next;
		if (item->data > max)
			max = item->data;
	}
	return (max);
}

size_t	getindex(t_item *item, int nbr)
{
	size_t	index;

	index = 0;
	while (item)
	{
		if (item->data == nbr)
			return (index);
		index++;
		item = item->next;
	}
	return (0);
}

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

void	sort_b(t_number *number)
{
	size_t	len;
	size_t	index;
	size_t	min;
	size_t	max;
	bool	ismin;
	size_t	top;

	len = getlen(number->b);
	top = 0;
	while (number->b)
	{
		min = getindex(number->b, getmin(number->b));
		max = getindex(number->b, getmax(number->b));
		index = bestindex(min, max, len);
		ismin = index == min;
		if (index < len / 2)
			while (index--)
				execute(number, "rb");
		else
			while (index++ < len)
				execute(number, "rrb");
		execute(number, "pa");
		if (ismin)
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
	size_t	len;

	len = getlen(number->a) - indexmax;
	while (number->a && indexmax--)
		if (number->a->data <= pivot)
			execute(number, "pb");
		else
			execute(number, "ra");
	if (len < getlen(number->a))
		while (len--)
			execute(number, "ra");
	len = getlen(number->b);
	sort_b(number);
	return (len);
}

void	sort(t_number *number)
{
	size_t	len;
	size_t	division;
	size_t	total;
	size_t	index;
	size_t	indexmax;
	size_t	max;

	len = getlen(number->a);
	division = len / 50;
	if (len > len / 50 * 50)
		division++;
	total = gettotal(number->a);
	indexmax = len;
	max = getmax(number->a);
	index = 0;
	while (index++ < division)
		indexmax -= sort_partition(number, indexmax,
			max - ((division - index) * (total / len / division * 2)));
}
