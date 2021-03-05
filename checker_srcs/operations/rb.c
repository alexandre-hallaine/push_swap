/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:06:34 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/05 19:49:29 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "../number.h"

void	rb(t_number *number)
{
	int		temp;
	size_t	index;

	temp = number->b[0];
	index = 0;
	while (number->b[++index])
		number->b[index - 1] = number->b[index];
	number->b[index - 1] = temp;
}
