/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 08:59:30 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/07 09:24:49 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../list.h"
#include "../utils/lib.h"

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

void	sort(t_number *number)
{
	size_t	index;

	while (number->a)
	{
		index = getindex(number->a, getmin(number->a));
		while (index--)
			execute(number, "ra");
		execute(number, "pb");
	}
	while (number->b)
		execute(number, "pa");
}