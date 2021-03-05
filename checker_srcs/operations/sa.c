/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:59:37 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/05 19:49:36 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../number.h"

void	sa(t_number *number)
{
	int	temp;

	if (!number->a[0] || !number->a[1])
		return ;
	temp = number->a[0];
	number->a[0] = number->a[1];
	number->a[1] = temp;
}
