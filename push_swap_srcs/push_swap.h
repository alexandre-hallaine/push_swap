/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 07:53:18 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/07 16:36:01 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "../list.h"

t_item	*parse(char **args);
void	dispatch(t_number *number, char *operation);
void	execute(t_number *number, char *operation);
size_t	getlen(t_item *item);
ssize_t	gettotal(t_item *item);
int		getmin(t_item *item);
int		getmax(t_item *item);
size_t	getindex(t_item *item, int nbr);
void	sort(t_number *number);
#endif
