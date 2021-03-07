/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:01:23 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/07 09:04:35 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include "../utils/lib.h"

void	freenumber(t_number number)
{
	t_item	*temp;

	while (number.a)
	{
		temp = number.a->next;
		free(number.a);
		number.a = temp;
	}
	while (number.b)
	{
		temp = number.b->next;
		free(number.b);
		number.b = temp;
	}
}

int		main(int argc, char **argv)
{
	t_number	number;

	(void)argc;
	argv++;
	number = (t_number){0, 0};
	if (*argv)
		number.a = parse(argv);
	if (number.a)
		sort(&number);
	else
		ft_putstr_fd("Error\n", 2);
	freenumber(number);
	return (0);
}
