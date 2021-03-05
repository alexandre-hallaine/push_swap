/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:05:01 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/05 22:49:09 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list.h"

void	sb(t_number *number)
{
	t_item	*temp;

	if (!number->b || !number->b->next)
		return ;
	temp = number->b->next;
	number->b->next = number->b->next->next;
	temp->next = number->b;
	number->b = temp;
}
