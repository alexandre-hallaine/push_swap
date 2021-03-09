/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:37:59 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/09 21:33:59 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "checker.h"
#include "../utils/lib.h"

char	*nbrtostr(int nbr, int min, int max)
{
	size_t	amount;
	char	*ret;

	if (max - min == 0)
		amount = 25;
	else
		amount = 25 * (nbr - min) / (max - min);
	if (!(ret = malloc(sizeof(char *) * (amount + 1))))
		return (NULL);
	ret[amount] = 0;
	while (amount-- > 0)
		ret[amount] = '|';
	return (ret);
}

void	printitem(t_item *item, size_t min, size_t max)
{
	char	*str;

	if (item)
	{
		str = nbrtostr(item->data, min, max);
		printf("%3d %-25s", item->data, str);
		free(str);
	}
	else
		printf("%29s", "");
}

void	print(t_number number, char **operations, size_t count)
{
	size_t	index;
	int		min_a;
	int		max_a;
	int		min_b;
	int		max_b;

	min_a = getmin(number.a);
	max_a = getmax(number.a);
	min_b = getmin(number.b);
	max_b = getmax(number.b);
	printf("\e[2J\e[H");
	index = 0;
	while (index++ < 50)
	{
		printf("%3s| ", count > 0 ? operations[--count] : "");
		printitem(number.a, min_a, max_a);
		if (number.a)
			number.a = number.a->next;
		printf(" ");
		printitem(number.b, min_b, max_b);
		if (number.b)
			number.b = number.b->next;
		printf("\n");
	}
	usleep(50000);
}

void	prompt(t_number *number, t_display display)
{
	int		ret;
	char	*line;
	char	**operations;
	size_t	count;

	count = 0;
	if (!(operations = malloc(sizeof(char **) * 1000000)))
		return ;
	if (display.print)
		print(*number, operations, count);
	while (1)
	{
		ret = get_next_line(0, &line);
		operations[count++] = line;
		if (ret > 0)
			dispatch(number, line);
		if (ret > 0 && display.print)
			print(*number, operations, count);
		if (ret <= 0)
			break ;
	}
	while (count--)
		free(operations[count]);
	free(operations);
}
