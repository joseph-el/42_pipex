/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:44:51 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/02/16 17:14:41 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/pipex.h"

void    parce(t_pipeline *pipeline,char **argv, t_pipe_flag flag)
{
    int index;

    index = 0;
    if (flag & INFILE)
    {
        pipeline
    }
}

t_pipe_flag    set_pipeline(t_pipeline *pipeline, char **envp, char **argv, int argc)
{
    t_data  *data;
    int     i;

    pipeline->gc = gc_init();
    if (!pipeline->gc)
        return (strerror(ENOMEM), exit(1), (t_pipe_flag)ENOMEM);
    if (ft_memcmp(*(argv + 1), "here_doc", sizeof("here_doc") + 1) && argc & HERDOC)
        return ((t_pipe_flag)HERDOC);
    i = 1;
    while (++i < (argc - 2));
    data = gc_strainer(pipeline->gc, malloc(sizeof(t_data) * i), ADD_OVR);
    pipeline->data = data;
    i = 0;
    while (++i < argc)
    {
        if (i == 2)
            parce(pipeline, argv, (t_pipe_flag)INFILE);
        else if (i == (argc - 1))
            parce (pipeline, argv, (t_pipe_flag)OUTFILE);
        else
            parce(pipeline, argv, (t_pipe_flag)PIPE_BUF);
    }
    return ((t_pipe_flag)PIPE_LINE);
}

int main(int argc, char **argv, char **envp)
{
    t_pipeline  pipeline = {.data = NULL, .envp = NULL, .gc = NULL};
    t_pipe_flag flag;
    int         fds[2];

    if (argc != 5 || argc < 5)
        return (ft_putstr_fd("BAD ARGS", 2), EXIT_FAILURE);
    flag = set_pipeline(&pipeline, envp, argv, argc);
    if (flag & ~HERDOC)
        pipeline(pipeline, fds);
    else
        heredoc(pipeline, fds);
    gc_gc_purifying(&pipeline.gc, CLEAN_ALL);
    exit(EXIT_SUCCESS);
}

