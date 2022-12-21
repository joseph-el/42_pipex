/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:26:48 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/12/13 08:50:15 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_lstadd_back(t_list **lst, t_list *newC)
{
	t_list	*p;

	if (!(*lst))
		(*lst) = newC;
	else
	{
		p = (*lst);
		while (p->next)
			p = p->next;
		p->next = newC;
		newC->prev = p;
	}
}
