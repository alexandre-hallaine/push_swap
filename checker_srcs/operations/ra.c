/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:47:36 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/05 19:49:27 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "../number.h"

void	ra(t_number *number)
{
	int		temp;
	size_t	index;

	temp = number->a[0];
	index = 0;
	while (number->a[++index])
		number->a[index - 1] = number->a[index];
	number->a[index - 1] = temp;
}
