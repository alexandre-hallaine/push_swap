/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:04:10 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/09 21:36:46 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <unistd.h>
# include <stdbool.h>
# include "../utils/list.h"

size_t	ft_strlen(char *str, char c);
ssize_t	ft_putchar_fd(char c, int fd);
ssize_t	ft_putstr_fd(char *str, int fd);
ssize_t	ft_putnbr_fd(int n, int fd);
int		get_next_line(int fd, char **line);
bool	ft_equals(char *str1, char *str2);
size_t	getlen(t_item *item);
int		getmin(t_item *item);
int		getmax(t_item *item);
size_t	getindex(t_item *item, int nbr);
ssize_t	getpivot(t_number number, size_t index, size_t division);
#endif
