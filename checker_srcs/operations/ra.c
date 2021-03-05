/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:47:36 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/05 22:58:11 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list.h"

void	ra(t_number *number)
{
	t_item	*temp;
	t_item	*last;

	temp = number->a;
	number->a = number->a->next;
	last = number->a;
	while (last->next)
		last = last->next;
	last->next = temp;
}
