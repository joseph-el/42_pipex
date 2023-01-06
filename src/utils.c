/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:16:38 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/01/01 22:34:12 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

bool	get_path(char **env, char *cmd, char **p_cmd)
{
	char	**path;
	char	*tmp;
	int		i;

	i = 0;
	while (env[++i] && ft_strncmp(env[i], "PATH=", 5))
		;
	path = ft_split(env[i], ':', 5);
	i = 0;
	while (path && path[i])
	{
		tmp = ft_strjoin(path[i], cmd);
		if (!access(tmp, X_OK))
			return (clear_arr(path), (*p_cmd) = tmp, true);
		i++;
	}
	return (ft_putstr_fd("path not found\n", 2), false);
}

bool	dupfiles(t_pipe **pip, char **env, char **p_cmd, int mode)
{
	if (! get_path(env, (**pip).cmd, p_cmd))
		return (exit(1), false);
	if (mode & INPUT)
	{
		close((*pip)->fd[0]);
		dup2((*pip)->fd[1], STDOUT_FILENO);
		dup2((*pip)->fd1, STDIN_FILENO);
	}
	else if (mode & PROCESS)
	{
		close((*pip)->fd[0]);
		dup2((*pip)->fd[1], STDOUT_FILENO);
		dup2((*pip)->t_fd, STDIN_FILENO);
	}
	else if (mode & OUTPUT)
	{
		dup2((*pip)->t_fd, STDIN_FILENO);
		dup2((*pip)->fd2, STDOUT_FILENO);
	}
	return (true);
}

int	process(t_pipe **pip, char **p_cmd, char **env, int mode)
{
	(**pip).pid1 = fork();
	if ((**pip).pid1 < 0)
		return (EXIT_FAILURE);
	if (mode & INPUT && !(**pip).pid1)
	{
		dupfiles(pip, env, p_cmd, FORK | INPUT);
		if (execve(*p_cmd, (**pip).lst->args, NULL) == -1)
			return (perror("command not found"), exit(127), EXIT_FAILURE);
	}
	else if ((mode & PROCESS) && !(**pip).pid1)
	{
		dupfiles(pip, env, p_cmd, FORK | PROCESS);
		if (execve(*p_cmd, (**pip).lst->args, NULL) == -1)
			return (perror("command not found"), exit(127), EXIT_FAILURE);
	}
	else if ((mode & OUTPUT) && !(**pip).pid1)
	{
		dupfiles(pip, env, p_cmd, FORK | OUTPUT);
		if (execve(*p_cmd, (**pip).lst->args, NULL) == -1)
			return (perror("command not found"), exit(127), EXIT_FAILURE);
	}
	close((**pip).t_fd);
	(**pip).t_fd = dup((**pip).fd[0]);
	return (EXIT_SUCCESS);
}

int	ft_close(int fd1, int fd2)
{
	if (fd1 > 2)
		close(fd1);
	if (fd2 > 2)
		close(fd2);
	return (EXIT_SUCCESS);
}

int	ft_free(char *str1, char *str2)
{
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	return (EXIT_SUCCESS);
}
