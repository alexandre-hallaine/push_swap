/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:05:01 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/05 16:05:21 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../number.h"

void	sb(t_number *number)
{
	int	temp;

	if (!number->b[0] || !number->b[1])
		return ;
	temp = number->b[0];
	number->b[0] = number->b[1];
	number->b[1] = temp;
}