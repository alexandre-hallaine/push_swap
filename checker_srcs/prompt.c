/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:37:59 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/06 23:30:15 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "utils/lib.h"
#include "operations/operations.h"

void	printnumber(t_number number)
{
	printf("\e[H\e[2J");
	printf("%11c   %-11c\n", 'a', 'b');
	while (number.a || number.b)
	{
		if (number.a)
		{
			printf("%11d | ", number.a->data);
			number.a = number.a->next;
		}
		else
			printf("%11s | ", "");
		if (number.b)
		{
			printf("%-11d", number.b->data);
			number.b = number.b->next;
		}
		printf("\n");
	}
}

void	dispatch(t_number *number, char *str)
{
	if (ft_equals(str, "sa"))
		sa(number);
	else if (ft_equals(str, "sb"))
		sb(number);
	else if (ft_equals(str, "ss"))
		ss(number);
	else if (ft_equals(str, "pa"))
		pa(number);
	else if (ft_equals(str, "pb"))
		pb(number);
	else if (ft_equals(str, "ra"))
		ra(number);
	else if (ft_equals(str, "rb"))
		rb(number);
	else if (ft_equals(str, "rr"))
		rr(number);
	else if (ft_equals(str, "rra"))
		rra(number);
	else if (ft_equals(str, "rrb"))
		rrb(number);
	else if (ft_equals(str, "rrr"))
		rrr(number);
}

void	prompt(t_number *number, bool print)
{
	int		ret;
	char	*line;

	while (1)
	{
		ret = get_next_line(0, &line);
		dispatch(number, line);
		if (print)
			printnumber(*number);
		free(line);
		if (ret <= 0)
			break ;
	}
}
