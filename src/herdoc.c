/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:12:15 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/01/06 12:28:58 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	read_herdoc(t_pipe **pip, char *av)
{
	char	*line;
	size_t	len;

	pipe((**pip).fd);
	len = ft_strlen(av);
	while (1)
	{
		write(1, "pipe ", 6);
		write(1, "heredoc> ", 10);
		line = get_next_line(STDIN_FILENO);
		if ((!ft_strncmp(line, av, ft_strlen(av))
				&& ft_strlen(line) == len + 1) || !line)
			break ;
		ft_putstr_fd(line, (**pip).fd[1]);
		free(line);
	}
	free(line);
	(**pip).t_fd = dup((**pip).fd[0]);
	ft_close((**pip).fd[0], (**pip).fd[1]);
	pipe((**pip).fd);
	return (EXIT_SUCCESS);
}

static int	process_(t_pipe **pip, char **p_cmd, char **env, int mode)
{
	(**pip).pid1 = fork();
	if ((**pip).pid1 == -1)
		return (exit(1), EXIT_FAILURE);
	if ((mode & INPUT) && !(**pip).pid1)
	{
		if (!get_path(env, (**pip).cmd, p_cmd))
			return (exit(1), EXIT_FAILURE);
		dup2((**pip).t_fd, STDIN_FILENO);
		dup2((**pip).fd[1], STDOUT_FILENO);
		if (execve(*p_cmd, (**pip).lst->args, NULL) == -1)
			return (perror("command1 not found"), exit(127), EXIT_FAILURE);
	}
	else if ((mode & OUTPUT) && !(**pip).pid1)
	{
		if (!get_path(env, (**pip).cmd, p_cmd))
			return (exit(1), EXIT_FAILURE);
		dup2((**pip).fd[0], STDIN_FILENO);
		dup2((**pip).fd2, STDOUT_FILENO);
		if (execve(*p_cmd, (**pip).lst->next->args, NULL) == -1)
			return (perror("command2 not found"), exit(127), EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	herdoc(t_pipe **pip, int ac, char **av, char **env)
{
	char	*p_cmd;
	int		i;

	i = 2;
	p_cmd = NULL;
	while (++i <= (ac - 2))
		ft_lstadd_back(&(**pip).lst, ft_lstnew(av[i]));
	(**pip).fd2 = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0666);
	if ((**pip).fd2 == -1)
		return (perror("ERROR IN OPEN FILE"), exit(1), EXIT_FAILURE);
	read_herdoc(pip, av[2]);
	(**pip).cmd = ft_strjoin("/", (**pip).lst->args[0]);
	process_(pip, &p_cmd, env, FORK | INPUT);
	ft_free((**pip).cmd, p_cmd);
	ft_close((**pip).fd[1], (**pip).t_fd);
	(**pip).cmd = ft_strjoin("/", (**pip).lst->next->args[0]);
	process_(pip, &p_cmd, env, FORK | OUTPUT);
	ft_free((**pip).cmd, p_cmd);
	ft_close((**pip).t_fd, (**pip).fd2);
	ft_close((**pip).fd[1], (**pip).fd[0]);
	while (wait(NULL) != -1)
		;
	return (EXIT_SUCCESS);
}
