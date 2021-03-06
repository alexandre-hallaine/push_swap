/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:42:29 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/06 18:22:48 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdbool.h>
# include "list.h"

t_item	*parse(char **args);
void	prompt(t_number *number);
bool	check(t_number number);
#endif
