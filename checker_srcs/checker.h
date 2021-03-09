/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:42:29 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/09 21:33:24 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "display.h"
# include "../utils/list.h"

t_item	*parse(char **args);
void	freeitem(t_item *item);
void	dispatch(t_number *number, char *operation);
void	prompt(t_number *number, t_display isplay);
bool	check(t_item *item);
#endif
