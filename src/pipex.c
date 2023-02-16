/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:44:51 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/02/16 23:11:22 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/pipex.h"

void    parce(t_data **data, char **argv, t_pipe_flag flag)
{
    int i;

    if (flag & INFILE)
    {
        (*data)->cmdexc = ft_split(*argv, 32);
        (*data)->io_dest = PIPE_BUF;
        (*data)->io_src = open()
    }
    if (flag & OUTFILE)
    {
        
    }
    if (flag & PIPE_BUF)
    {
        
    }
}

t_pipe_flag set_pipeline(t_pipeline *pipeline, char **argv, char **envp, int argc)
{
    t_pipe_flag flag;
    t_data      *data;
    int         i;

    pipeline->gc = gc_init();
    pipeline->envp = envp;
    flag = PIPE_LINE;
    if (!pipeline->gc)
        return (strerror(ENOMEM), exit(1), (t_pipe_flag)ENOMEM);
    i = 1;
    while (++i < argc);
    if (ft_memcmp(*argv + 1, "her_doc", sizeof("her_doc") + 1) && argc & HERDOC)
        flag = HERDOC;
    flag = HERDOC ? i = 2 : i = i;
    data = gc_strainer(pipeline->gc, malloc(sizeof(t_data) * i), ADD_OVR);
    i = 0;
    while (++i < argc)
    {
        i += (ft_memcmp(argv[i], "her_doc", sizeof("her_doc") + 1) == 0);
        if (i == 2)
            parce(&data[i - 2], argv + i, (t_pipe_flag)INFILE);
        else if (i == (argc - 1))
            parce(&data[i - 2], argv + i, (t_pipe_flag)OUTFILE);
        else
            parce(&data[i - 2], argv + i, (t_pipe_flag)PIPE_BUF);
    }
    return (flag);
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
        run_pipeline(pipeline, fds, PIPE_LINE);
    else
        run_pipeline(pipeline, fds, HERDOC);
    gc_gc_purifying(&pipeline.gc, CLEAN_ALL);
    exit(EXIT_SUCCESS);
}

