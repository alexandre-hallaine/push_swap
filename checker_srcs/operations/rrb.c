/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:15:48 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/05 23:01:54 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list.h"

void	rrb(t_number *number)
{
	t_item	*last;
	t_item	*temp;

	last = number->b;
	while (last->next->next)
		last = last->next;
	temp = last->next;
	last->next = 0;
	number->b = temp;
}
