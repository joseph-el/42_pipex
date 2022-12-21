/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:27:03 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/12/18 10:37:05 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	clear_arr(char **arr)
{
	int	index;

	if (!arr)
		return ;
	index = 0;
	while (arr[index])
		free(arr[index++]);
	free(arr);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst);
		(*lst) = (*lst)->next;
		clear_arr(tmp->args);
		free(tmp);
	}
	free((*lst));
	lst = NULL;
}
