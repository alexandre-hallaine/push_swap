/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 23:45:15 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/06 18:22:34 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "list.h"

bool	check(t_number number)
{
	t_item	*current;

	if (number.b)
		return (false);
	current = number.a;
	while (current->next)
	{
		if (current->data > current->next->data)
			return (false);
		current = current->next;
	}
	return (true);
}
