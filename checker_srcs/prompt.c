/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:37:59 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/07 18:56:53 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "checker.h"
#include "../list.h"
#include "../utils/lib.h"
#include "../operations/operations.h"

void	printnumber(t_number number)
{
	printf("\e[H\e[2J");
	printf("%11s   %s\n", "Stack A", "Stack B");
	while (number.a || number.b)
	{
		if (number.a)
		{
			printf("%11d | ", number.a->data);
			number.a = number.a->next;
		}
		else
			printf("%11s | ", "");
		if (number.b)
		{
			printf("%d", number.b->data);
			number.b = number.b->next;
		}
		printf("\n");
	}
	usleep(50000);
}

void	prompt(t_number *number, bool print)
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		dispatch(number, line);
		if (print)
			printnumber(*number);
		free(line);
	}
}
