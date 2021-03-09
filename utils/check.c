/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 23:45:15 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/09 21:35:40 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "../utils/list.h"

bool	check(t_item *item)
{
	while (item && item->next)
	{
		if (item->data > item->next->data)
			return (false);
		item = item->next;
	}
	return (true);
}
