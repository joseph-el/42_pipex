/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 06:28:17 by yoel-idr          #+#    #+#             */
/*   Updated: 2023/01/06 12:28:29 by yoel-idr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

# define OUTPUT 2
# define INPUT 8
# define FORK 4
# define PROCESS 1

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	char			**args;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

typedef struct s_data
{
	int				fd1;
	int				fd2;
	int				fd[2];
	int				t_fd;
	int				pid1;
	char			*cmd;
	t_list			*lst;
}					t_pipe;

// pipex function && utils
int					herdoc(t_pipe **pip, int ac, char **av, char **env);
bool				get_path(char **env, char *cmd, char **p_cmd);
int					process(t_pipe **pip, char **p_cmd, char **env, int mode);
bool				dupfiles(t_pipe **pip, char **env, char **p_cmd, int mode);
int					ft_close(int fd1, int fd2);
int					ft_free(char *str1, char *str2);

// lib tools function

size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *str);
t_list				*ft_lstnew(char *cmd);
t_list				*ft_lstlast(t_list *lst);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_lstsize(t_list *lst);
int					ft_isdigit(int c);
char				*ft_strchr(const char *str, int c);
char				**ft_split(char const *s, char c, int start);
char				*reading_fd(int fd, char *stash);
char				*ft_ft(char *str);
char				*ft_strjoin(char *stash, char *buffer);
char				*ft_strjoin_s(char *stash, char *buffer);
char				*ft_subline(char *stash);
char				*cleaning_stash(char *stash);
char				*get_next_line(int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putstr(char *str);
void				clear_arr(char **arr);
void				ft_lstclear(t_list **lst);
void				ft_lstadd_back(t_list **lst, t_list *newC);
long long			ft_atoi(const char *str);

#endif
