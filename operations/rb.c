/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:06:34 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/09 21:31:54 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/list.h"

void	rb(t_number *number)
{
	t_item	*temp;
	t_item	*last;

	if (!number->b)
		return ;
	temp = number->b;
	number->b = number->b->next;
	temp->next = 0;
	if (number->b)
	{
		last = number->b;
		while (last && last->next)
			last = last->next;
		last->next = temp;
	}
	else
		number->b = temp;
}
