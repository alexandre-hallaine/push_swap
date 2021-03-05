/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:59:49 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/05 20:01:05 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../number.h"

void	update(t_number *number, int *a, int *b)
{
	free(number->a);
	number->a = a;
	free(number->b);
	number->b = b;
}
