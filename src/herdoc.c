/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:52:20 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/02/16 16:17:54 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/pipex.h"

int	herdoc(char *limiter, int *fds)
{
	char	*line;
	int		limiter_size;

	if (!limiter || pipe(fds) == -1)
		return (-1);
	limiter_size = ft_strlen(limiter);
	while (true)
	{
        ft_putstr("> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		gc_adding_adress(g_global.gc, line, ADD_TMP);
		if (!line || !ft_memcmp(limiter, line, limiter_size + 1))
			break ;
		write(fds[WIRITE_END], line, ft_strlen(line));
	}
	return (close(fds[WIRITE_END]), fds[READ_END]);
}