/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 13:53:14 by ahallain          #+#    #+#             */
/*   Updated: 2021/03/05 23:05:36 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef	struct s_item	t_item;
struct					s_item
{
	int		data;
	t_item	*next;
};

typedef struct			s_number
{
	t_item	*a;
	t_item	*b;
}						t_number;
#endif
