/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:01:23 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/06 21:11:28 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker.h"
#include "utils/lib.h"

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
	int			ret;
	bool		print;

	(void)argc;
	argv++;
	print = false;
	if (ft_equals(*argv, "-v"))
	{
		print = true;
		argv++;
	}
	number = (t_number){0, 0};
	if (*argv)
		number.a = parse(argv);
	if (number.a)
	{
		prompt(&number, print);
		if (check(number))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
		ret = 0;
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
		ret = 1;
	}
	freenumber(number);
	return (ret);
}
