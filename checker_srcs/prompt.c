/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:37:59 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/05 18:36:13 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "number.h"
#include "utils/lib.h"
#include "operations/operations.h"

void	print(t_number number)
{
	size_t	index;

	ft_putchar_fd('a', 1);
	index = 0;
	while (number.a[index])
	{
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(number.a[index++], 1);
	}
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('b', 1);
	index = 0;
	while (number.b[index])
	{
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(number.b[index++], 1);
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
		print(*number);
		free(line);
		if (ret <= 0)
			break;
	}
}