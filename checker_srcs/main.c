/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:01:23 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/09 21:10:00 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker.h"
#include "../utils/lib.h"

int			run(t_number *number, t_display display)
{
	int	ret;

	if (number->a)
	{
		prompt(number, display);
		if (!number->b && check(number->a))
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

t_display	flag(char ***args)
{
	bool	color;
	bool	print;

	color = false;
	print = false;
	while (***args == '-')
	{
		if ((**args)[1] == 'c')
			color = true;
		else if ((**args)[1] == 'v')
			print = true;
		(*args)++;
	}
	return ((t_display){color, print});
}

int			main(int argc, char **argv)
{
	t_number	number;
	t_display	display;
	int			ret;

	(void)argc;
	argv++;
	display = flag(&argv);
	if (!*argv)
		return (0);
	number = (t_number){parse(argv), 0};
	ret = run(&number, display);
	freeitem(number.a);
	freeitem(number.b);
	return (ret);
}
