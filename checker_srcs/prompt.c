/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:37:59 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/08 11:17:38 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "checker.h"
#include "../list.h"
#include "../utils/lib.h"
#include "../operations/operations.h"

void	printnumber(t_number number, char *str, size_t count)
{
	printf("\e[H\e[2J");
	printf("%-8s%7s   %s %8zu\n", str, "Stack A", "Stack B", count);
	while (number.a || number.b)
	{
		if (number.a)
		{
			printf("%15d | ", number.a->data);
			number.a = number.a->next;
		}
		else
			printf("%15s | ", "");
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
	size_t	count;

	count = 0;
	if (print)
		printnumber(*number, "", count);
	while (1)
	{
		ret = get_next_line(0, &line);
		if (ret > 0)
		{
			dispatch(number, line);
			if (print)
				printnumber(*number, line, count++);
		}
		free(line);
		if (ret <= 0)
			break ;
	}
}
