/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:06:34 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/05 22:58:04 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list.h"

void	rb(t_number *number)
{
	t_item	*temp;
	t_item	*last;

	temp = number->b;
	number->b = number->b->next;
	last = number->b;
	while (last->next)
		last = last->next;
	last->next = temp;
}
