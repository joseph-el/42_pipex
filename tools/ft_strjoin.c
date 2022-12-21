/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 10:22:00 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/12/13 09:30:01 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*ft_strjoin(char *stash, char *buffer)
{
	char	*str;
	char	*ptr;
	int		len;

	if (!stash || !buffer)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buffer)) + 1);
	if (!str)
		return (NULL);
	ptr = str;
	len = 0;
	while (stash[len])
		*str++ = stash[len++];
	while (*buffer)
		*str++ = *buffer++;
	*str = 0;
	return (ptr);
}
