/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:15:48 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/06 18:37:32 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list.h"

void	rrb(t_number *number)
{
	t_item	*last;
	t_item	*temp;

	if (!number->b || !number->b->next)
		return ;
	last = number->b;
	while (last->next && last->next->next)
		last = last->next;
	temp = last->next;
	last->next = 0;
	temp->next = number->b;
	number->b = temp;
}
