/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:10:12 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/06 18:36:42 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list.h"

void	rra(t_number *number)
{
	t_item	*last;
	t_item	*temp;

	if (!number->a || !number->a->next)
		return ;
	last = number->a;
	while (last->next && last->next->next)
		last = last->next;
	temp = last->next;
	last->next = 0;
	temp->next = number->a;
	number->a = temp;
}
