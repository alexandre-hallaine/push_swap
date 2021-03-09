/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:59:37 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/09 21:31:35 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/list.h"

void	sa(t_number *number)
{
	t_item	*temp;

	if (!number->a || !number->a->next)
		return ;
	temp = number->a->next;
	number->a->next = number->a->next->next;
	temp->next = number->a;
	number->a = temp;
}
