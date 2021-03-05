/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:37:59 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/05 23:47:38 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"
#include "utils/lib.h"
#include "operations/operations.h"

void	print(t_number number, char *str)
{
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('a', 1);
	while (number.a)
	{
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(number.a->data, 1);
		number.a = number.a->next;
	}
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('b', 1);
	while (number.b)
	{
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(number.b->data, 1);
		number.b = number.b->next;
	}
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('\n', 1);
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

void	prompt(t_number *number)
{
	int		ret;
	char	*line;

	while (1)
	{
		ret = get_next_line(0, &line);
		dispatch(number, line);
		free(line);
		if (ret <= 0)
			break ;
	}
}
