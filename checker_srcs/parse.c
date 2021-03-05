/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 23:44:26 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/05 23:54:34 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"
#include "utils/lib.h"

t_item	*item(int data)
{
	t_item	*ret;

	if (!(ret = malloc(sizeof(t_item))))
		return (NULL);
	ret->data = data;
	return (ret);
}

t_item	*parse(char **args)
{
	size_t	index;
	size_t	index1;
	t_item	*list;
	t_item	*last;

	index = 0;
	list = item(ft_atoi(args[index++]));
	last = list;
	while (args[index])
	{
		index1 = 0;
		while (args[index][index1] >= '0' && args[index][index1] <= '9')
			index1++;
		if (args[index][index1])
			return (0);
		last->next = item(ft_atoi(args[index++]));
		last = last->next;
	}
	return (list);
}
