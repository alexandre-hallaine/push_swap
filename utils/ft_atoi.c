/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:33:47 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/05 22:25:29 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	ret;
	int	multiply;

	multiply = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			multiply = -1;
		str++;
	}
	ret = 0;
	while (*str >= '0' && *str <= '9')
	{
		ret *= 10;
		ret += *str - '0';
		str++;
	}
	return (multiply * ret);
}
