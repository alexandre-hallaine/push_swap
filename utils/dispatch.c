/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 09:12:31 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/07 18:55:31 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "../list.h"
#include "../operations/operations.h"

void	dispatch(t_number *number, char *operation)
{
	if (ft_equals(operation, "sa"))
		sa(number);
	else if (ft_equals(operation, "sb"))
		sb(number);
	else if (ft_equals(operation, "ss"))
		ss(number);
	else if (ft_equals(operation, "pa"))
		pa(number);
	else if (ft_equals(operation, "pb"))
		pb(number);
	else if (ft_equals(operation, "ra"))
		ra(number);
	else if (ft_equals(operation, "rb"))
		rb(number);
	else if (ft_equals(operation, "rr"))
		rr(number);
	else if (ft_equals(operation, "rra"))
		rra(number);
	else if (ft_equals(operation, "rrb"))
		rrb(number);
	else if (ft_equals(operation, "rrr"))
		rrr(number);
	else
		ft_putstr_fd("Error\n", 2);
}
