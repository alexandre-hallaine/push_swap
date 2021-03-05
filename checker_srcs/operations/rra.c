/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:10:12 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/05 19:49:31 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "../number.h"

void	rra(t_number *number)
{
	int		temp;
	size_t	index;

	index = 0;
	while (number->a[index])
		index++;
	temp = number->a[--index];
	while (index--)
		number->a[index + 1] = number->a[index];
	number->a[0] = temp;
}
