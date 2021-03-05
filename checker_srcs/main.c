/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:01:23 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/06 00:20:19 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker.h"
#include "utils/lib.h"

void	freeitem(t_item *item)
{
	if (!item)
		return ;
	freeitem(item->next);
	free(item);
}

int		main(int argc, char **argv)
{
	t_number	number;
	int			ret;

	number = (t_number){0, 0};
	if (argc > 1)
		number.a = parse(argv + 1);
	if (number.a)
	{
		prompt(&number);
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
	freeitem(number.a);
	freeitem(number.b);
	return (ret);
}
