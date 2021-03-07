/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:28:09 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/05 22:54:27 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../list.h"

void	pb(t_number *number)
{
	t_item	*temp;

	if (!number->a)
		return ;
	temp = number->a->next;
	number->a->next = number->b;
	number->b = number->a;
	number->a = temp;
}
