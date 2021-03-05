/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:43:28 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/05 19:45:58 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../number.h"

void	pa(t_number *number)
{
	int		*newa;
	int		*newb;
	size_t	index;

	if (!number->b[0])
		return ;
	index = 0;
	while (number->a[index])
		index++;
	if (!(newa = malloc(sizeof(int *) * (index + 2))))
		return ;
	newa[index + 1] = 0;
	while (index--)
		newa[index + 1] = number->a[index];
	newa[0] = number->b[0];
	index = 0;
	while (number->b[index])
		index++;
	if (!(newb = malloc(sizeof(int *) * index)))
		return ;
	newb[index] = 0;
	while (--index)
		newb[index - 1] = number->b[index];
	free(number->a);
	number->a = newa;
	free(number->b);
	number->b = newb;
}