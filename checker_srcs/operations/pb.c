/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:28:09 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/05 19:46:01 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../number.h"
#include "../utils/lib.h"

void	pb(t_number *number)
{
	int		*newa;
	int		*newb;
	size_t	index;

	if (!number->a[0])
		return ;
	index = 0;
	while (number->b[index])
		index++;
	if (!(newb = malloc(sizeof(int *) * (index + 2))))
		return ;
	newb[index + 1] = 0;
	while (index--)
		newb[index + 1] = number->b[index];
	newb[0] = number->a[0];
	index = 0;
	while (number->a[index])
		index++;
	if (!(newa = malloc(sizeof(int *) * index)))
		return ;
	newa[index] = 0;
	while (--index)
		newa[index - 1] = number->a[index];
	free(number->a);
	number->a = newa;
	free(number->b);
	number->b = newb;
}