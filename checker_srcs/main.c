/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:01:23 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/07 19:29:44 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker.h"
#include "../utils/lib.h"

int		run(t_number *number, bool print)
{
	int	ret;

	if (number->a)
	{
		prompt(number, print);
		if (check(*number))
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
	return (ret);
}

int		main(int argc, char **argv)
{
	t_number	number;
	int			ret;
	bool		print;

	(void)argc;
	argv++;
	print = false;
	if (*argv && ft_equals(*argv, "-v"))
	{
		print = true;
		argv++;
	}
	if (!*argv)
		return (0);
	number = (t_number){parse(argv), 0};
	ret = run(&number, print);
	freeitem(number.a);
	freeitem(number.b);
	return (ret);
}
