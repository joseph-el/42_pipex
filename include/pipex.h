/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:40:38 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/02/16 22:48:40 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <paths.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>
# include "gc_memory.h"

# define MIDDLE     1 << 1
# define FIRST      1 << 3
# define LAST       1 << 2
# define INFILE     1 << 5
# define OUTFILE    1 << 4
# define FILE_PERM  0664
# define HERDOC     0x6
# define PIPE_LINE  0x4
# define WIRITE_END 1
# define READ_END   0


typedef unsigned short t_pipe_flag;

typedef struct s_data
{
    int     io_dest;
    int     io_src;
    char    **cmdexc;
}               t_data;

typedef struct s_pipeline
{
    t_gc    *gc;
    t_data  *data;
    char    **envp;
}               t_pipeline;



# endif