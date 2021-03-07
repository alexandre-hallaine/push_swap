/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 23:44:26 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/07 17:54:23 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lib.h"
#include "../list.h"

t_item	*item(int data)
{
	t_item	*ret;

	if (!(ret = malloc(sizeof(t_item))))
		return (NULL);
	ret->data = data;
	ret->next = 0;
	return (ret);
}

bool	contain(t_item *item, int nbr)
{
	while (item)
	{
		if (item->data == nbr)
			return (true);
		item = item->next;
	}
	return (false);
}

bool	isnbr(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str)
		return (false);
	return (true);
}

void	freeitem(t_item *item)
{
	if (!item)
		return ;
	freeitem(item->next);
	free(item);
}

t_item	*parse(char **args)
{
	size_t	index;
	t_item	*list;
	t_item	*last;
	int		data;

	index = 0;
	list = item(ft_atoi(args[index++]));
	last = list;
	while (args[index])
	{
		if (!isnbr(args[index])
			|| contain(list, (data = ft_atoi(args[index++]))))
		{
			freeitem(list);
			return (0);
		}
		last->next = item(data);
		last = last->next;
	}
	return (list);
}
