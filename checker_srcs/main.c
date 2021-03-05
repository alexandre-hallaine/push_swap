/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:01:23 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/05 16:40:44 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "checker.h"
#include "utils/lib.h"

int		*parse(char **args)
{
	size_t	index;
	int		*ret;

	index = 0;
	while (args[index])
		if (ft_atoi(args[index++]) == -1)
			return (NULL);
	if (!(ret = malloc(sizeof(int *) * (index + 1))))
		return (NULL);
	ret[index] = 0;
	while (index--)
		ret[index] = ft_atoi(args[index]);
	return (ret);
}

bool	check(t_number number)
{
	size_t	index;

	if (number.b[0])
		return (false);
	index = 0;
	while (number.a[index + 1])
	{
		if (number.a[index] > number.a[index + 1])
			return (false);
		index++;
	}
	return (true);
}

int		main(int argc, char **argv)
{
	t_number	number;

	number = (t_number){NULL, NULL};
	if (argc > 1)
		number.a = parse(argv + 1);
	if (number.a == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	number.b = parse(argv + argc);
	prompt(&number);
	if (check(number))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (0);
}
