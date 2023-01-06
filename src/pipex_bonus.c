/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:45:53 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/01/06 12:25:34 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	pipex(t_pipe **pip, int ac, char **env)
{
	char	*p_cmd;
	int		index;

	index = 1;
	p_cmd = NULL;
	while (++index <= (ac - 2))
	{
		(**pip).cmd = ft_strjoin("/", (*pip)->lst->args[0]);
		pipe((**pip).fd);
		if (!(index ^ 2))
			process(pip, &p_cmd, env, FORK | INPUT);
		else if (index == (ac - 2))
			return (process(pip, &p_cmd, env, FORK | OUTPUT), EXIT_SUCCESS);
		else
			process(pip, &p_cmd, env, FORK | PROCESS);
		ft_close((**pip).fd[0], (*pip)->fd[1]);
		(**pip).lst = (**pip).lst->next;
		ft_free((**pip).cmd, p_cmd);
	}
	return (EXIT_SUCCESS);
}

static int	pipes(t_pipe **pip, int ac, char **av, char **env)
{
	t_list	*tmp;
	int		i;

	i = 1;
	(**pip).lst = NULL;
	while (++i <= (ac - 2))
		ft_lstadd_back(&(**pip).lst, ft_lstnew(av[i]));
	tmp = (**pip).lst;
	(**pip).fd1 = open(av[1], O_RDWR);
	if ((**pip).fd1 == -1)
		return (perror("ERROR IN OPEN FILE"), exit(1), EXIT_FAILURE);
	(**pip).fd2 = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if ((**pip).fd2 == -1)
		return (perror("ERROR IN OPEN FILE"), exit(1), EXIT_FAILURE);
	pipex(pip, ac, env);
	ft_close((**pip).fd1, (**pip).fd2);
	ft_lstclear(&tmp);
	while (wait(NULL) != -1)
		;
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av, char **env)
{
	t_pipe	*pip;

	if (ac < 5)
		return (ft_putstr_fd("<INVALID args>", 2), EXIT_FAILURE);
	pip = malloc(sizeof(t_pipe));
	if (!pip)
		return (EXIT_FAILURE);
	(*pip).lst = NULL;
	(*pip).cmd = NULL;
	if (!ft_strncmp("here_doc", av[1], 9) && !(ac ^ 6))
		return (herdoc(&pip, ac, av, env), free(pip), EXIT_SUCCESS);
	else
		return (pipes(&pip, ac, av, env), free(pip), EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
