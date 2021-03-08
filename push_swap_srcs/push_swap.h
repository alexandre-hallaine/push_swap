/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 07:53:18 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/08 14:57:07 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include "../list.h"

t_item	*parse(char **args);
void	freeitem(t_item *item);
void	dispatch(t_number *number, char *operation);
void	execute(t_number *number, char *operation);
void	sort(t_number *number);
bool	check(t_number number);
#endif
