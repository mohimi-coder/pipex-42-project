/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:43:45 by mohimi            #+#    #+#             */
/*   Updated: 2024/02/19 10:31:47 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_bpipex
{
	int		fd[2];
	pid_t	pid;
	int		filein;
	int		fileout;
	char	**split_cmd;
	char	**chec;
	char	*result;
	int		i;
	char	*limiter;
}		t_bpipex;

int		ft_open_files(char *av, int i);
void	ft_error_message(char *mess);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_get_path(char **env);
char	*check_cmd(char **envp, char **cmd);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
char	*ft_sersh_for_newline(const char *s, int c);
char	*get_next_line(int fd);
char	*ft_searsh_for_slash(const char *s, int c);
char	*ft_strdup(const char *src);
char	*ft_substr(const char *s, unsigned int start, size_t len);
void	process_here_doc(int ac, char **av, t_bpipex *pipex);
void	last_cmd(int ac, char **av, char **env, t_bpipex *pipex);
void	first_middle_cmds(char *command, char **envp, t_bpipex *bpipe);
void	ft_execve(char **cmd, char **envp, t_bpipex *bpipe);
#endif
