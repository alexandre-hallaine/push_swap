/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:04:10 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/05 16:18:12 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

#include <unistd.h>
#include <stdbool.h>

size_t	ft_strlen(char *str, char c);
ssize_t	ft_putchar_fd(char c, int fd);
ssize_t	ft_putstr_fd(char *str, int fd);
ssize_t	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);
int		get_next_line(int fd, char **line);
bool	ft_equals(char *str1, char *str2);
#endif