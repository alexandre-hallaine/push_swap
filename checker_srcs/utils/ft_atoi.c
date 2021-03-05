/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:33:47 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/05 19:50:05 by ahallain         ###   ########.fr       */
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
	while (*str)
		if (*str >= '0' && *str <= '9')
		{
			ret *= 10;
			ret += *str - '0';
			str++;
		}
		else
			return (-1);
	return (multiply * ret);
}
