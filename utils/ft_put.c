/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:07:21 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/08 14:57:31 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../utils/lib.h"

ssize_t	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

ssize_t	ft_putstr_fd(char *str, int fd)
{
	return (write(fd, str, ft_strlen(str, 0)));
}

ssize_t	ft_putnbr_fd(int n, int fd)
{
	ssize_t	ret;

	ret = 0;
	if (n < 0)
	{
		ret += ft_putchar_fd('-', fd);
		if (n == -2147483648)
		{
			ret += ft_putchar_fd('2', fd);
			n = -147483648;
		}
		n *= -1;
	}
	if (n > 9)
		ret += ft_putnbr_fd(n / 10, fd);
	return (ret + ft_putchar_fd(n % 10 + '0', fd));
}
