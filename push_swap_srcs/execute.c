/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 09:13:48 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/07 09:25:28 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include "../list.h"
#include "../utils/lib.h"

void	execute(t_number *number, char *operation)
{
	dispatch(number, operation);
	ft_putstr_fd(operation, 1);
	ft_putchar_fd('\n', 1);
}