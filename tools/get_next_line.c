/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:51:21 by yoel-idr          #+#    #+#             */
/*   Updated: 2022/12/16 21:24:25 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*reading_fd(int fd, char *stash)
{
	char	*buffer;
	int		readed;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	readed = 1;
	while (!ft_ft(stash) && readed != 0)
	{
		readed = (int)read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[readed] = 0;
		stash = ft_strjoin_s(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = reading_fd(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_subline(stash);
	stash = cleaning_stash(stash);
	return (line);
}
