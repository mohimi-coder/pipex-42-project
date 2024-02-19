/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:48:37 by mohimi            #+#    #+#             */
/*   Updated: 2024/02/13 12:44:11 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_pipex
{
	char	*path;
	int		fd1;
	int		fd2;
	char	**av;
	char	**envp;
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		filein;
	int		fileout;
	char	**split_cmd;
	char	**chec;
	char	*result;
}			t_pipex;

char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	**ft_get_path(char **env);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*check_cmd(char **env, char **cmd);
void	ft_error_message(char *mess);
void	ft_free_leak(char **str);
void	pipex(int ac, char **av, t_pipex *xpipe, char **envp);
size_t	ft_strlen(const char *str);
char	*ft_searsh_for_slash(const char *s, int c);

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define RESET "\x1b[0m"

#endif