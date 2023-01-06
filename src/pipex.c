/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:52:00 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/01/06 12:28:03 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	pipex(t_pipe **pip, int ac, char **av, char **env)
{
	char	*p_cmd;

	p_cmd = NULL;
	(**pip).fd1 = open(av[1], O_RDWR);
	if ((**pip).fd1 == -1)
		return (perror("ERROR IN OPEN FILE"), exit(1), EXIT_FAILURE);
	(**pip).fd2 = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0666);
	if ((**pip).fd2 == -1)
		return (perror("ERROR IN OPEN FILE"), exit(1), EXIT_FAILURE);
	(**pip).cmd = ft_strjoin("/", (**pip).lst->args[0]);
	process(pip, &p_cmd, env, FORK | INPUT);
	ft_free((**pip).cmd, p_cmd);
	ft_close((**pip).fd[1], (**pip).fd[0]);
	(**pip).lst = (**pip).lst->next;
	(**pip).cmd = ft_strjoin("/", (*pip)->lst->args[0]);
	process(pip, &p_cmd, env, FORK | OUTPUT);
	ft_free((**pip).cmd, p_cmd);
	close((**pip).t_fd);
	ft_close((**pip).fd1, (**pip).fd2);
	while (wait(NULL) != -1)
		;
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av, char **env)
{
	t_pipe	*pip;
	t_list	*tmp;
	int		i;

	if (ac != 5)
		return (ft_putstr_fd("<INVALID args>", 2), EXIT_FAILURE);
	pip = malloc(sizeof(t_pipe));
	if (!pip)
		return (EXIT_FAILURE);
	pip->lst = NULL;
	i = 1;
	while (++i < 4)
		ft_lstadd_back(&pip->lst, ft_lstnew(av[i]));
	tmp = pip->lst;
	if (pipe(pip->fd) == -1)
		return (perror("ERROR IN PIPE"), EXIT_FAILURE);
	pipex(&pip, ac, av, env);
	ft_lstclear(&tmp);
	free(pip);
	return (EXIT_SUCCESS);
}
