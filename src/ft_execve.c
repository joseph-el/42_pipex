/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:56:20 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/02/16 16:05:54 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/pipex.h"

static void	destroyer(char **arr)
{
	int	index;

	if (!arr)
		return ;
	index = 0;
	while (arr[index])
		free(arr[index++]);
	free(arr);
}

static char	*get_path(char *cmdline, char **envp)
{
	char	**path;
	char	*p_cmd;
	int		i;

	if (ft_strchr(cmdline, '/'))
		return (cmdline);
	while (envp && ft_strcmp(*envp, "PATH", sizeof("PATH") + 1))
        *envp ++;
	if (!*envp)
		return (NULL);
	cmdline = gc(g_global.gc, ft_strjoin("/", cmdline), ADD_TMP);
	path = ft_split(p_cmd, ':');
	i = 0;
	while (path && path[i])
	{
		p_cmd = gc(g_global.gc, ft_strjoin(path[i], cmdline), ADD_TMP);
		if (!access(p_cmd, X_OK))
			return (destroyer(path), p_cmd);
		i++;
	}
	return (NULL);
}

int	ft_execve(char *cmd, char **cmd_argument, char **envp)
{
	char		*p_cmd;
	char		**env;
	struct stat	s_stat;

	p_cmd = get_path(cmd);
	if (!p_cmd)
		return (ft_putstr_fd("command not found", 2), exit(127), -1);
	stat(p_cmd, &s_stat);
	if (S_ISDIR(s_stat.st_mode))
		return (strerror(EISDIR), exit(126), -1);
	execve(p_cmd, cmd_argument, envp);
	return (-1);
}
