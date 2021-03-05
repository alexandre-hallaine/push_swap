/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:15:48 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/05 19:49:32 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "../number.h"

void	rrb(t_number *number)
{
	int		temp;
	size_t	index;

	index = 0;
	while (number->b[index])
		index++;
	temp = number->b[--index];
	while (index--)
		number->b[index + 1] = number->b[index];
	number->b[0] = temp;
}
