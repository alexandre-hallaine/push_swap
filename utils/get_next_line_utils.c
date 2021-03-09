/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 21:50:11 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/09 21:36:14 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

size_t	ft_strlen(char *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

void	ft_addstr(char *from, char **to)
{
	char	*new;
	size_t	index;
	size_t	index1;

	index = ft_strlen(*to, 0) + ft_strlen(from, 0);
	if (!(new = malloc(sizeof(char *) * (index + 1))))
		return ;
	new[index] = 0;
	index = 0;
	while ((*to)[index])
	{
		new[index] = (*to)[index];
		index++;
	}
	index1 = 0;
	while (from[index1])
	{
		new[index + index1] = from[index1];
		index1++;
	}
	free(*to);
	*to = new;
}

bool	ft_contain(char *str, char c)
{
	while (*str && *str != c)
		str++;
	return (*str == c);
}

char	*ft_getstr(char *from, char c)
{
	size_t	len;
	size_t	index;
	char	*new;

	len = ft_strlen(from, c);
	if (!(new = malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	new[len] = 0;
	index = 0;
	while (index < len)
	{
		new[index] = from[index];
		index++;
	}
	return (new);
}

void	ft_rmfirst(char **str, size_t len)
{
	size_t	total_len;
	size_t	index;
	char	*new;

	total_len = ft_strlen(*str, 0) - len;
	if (!(new = malloc(sizeof(char **) * (total_len + 1))))
		return ;
	new[total_len] = 0;
	index = 0;
	while (index < total_len)
	{
		new[index] = (*str)[index + len];
		index++;
	}
	free(*str);
	*str = new;
}
