/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:30:13 by mohimi            #+#    #+#             */
/*   Updated: 2024/02/19 11:01:26 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	first_middle_cmds(char *command, char **envp, t_bpipex *bpipe)
{
	if (pipe(bpipe->fd) == -1)
		ft_error_message("Error from pipe");
	bpipe->pid = fork();
	if (bpipe->pid == -1)
		ft_error_message("Error from fork");
	if (bpipe->pid == 0)
	{
		close(bpipe->fd[0]);
		if (dup2(bpipe->fd[1], STDOUT_FILENO) < 0)
			ft_error_message("error from dup2 in fist_mid_cmd!");
		close(bpipe->fd[1]);
		ft_execve(&command, envp, bpipe);
	}
	else
	{
		close(bpipe->fd[1]);
		if (dup2(bpipe->fd[0], STDIN_FILENO) < 0)
			ft_error_message("error from dup2 in f_m parnt!");
		close(bpipe->fd[0]);
	}
}

void	last_cmd(int ac, char **av, char **env, t_bpipex *pipex)
{
	pipex->pid = fork();
	if (pipex->pid == -1)
		ft_error_message("Error from fork!");
	if (pipex->pid == 0)
	{
		close(pipex->fd[0]);
		dup2(pipex->fd[1], STDOUT_FILENO);
		close (pipex->fd[1]);
		dup2(pipex->fileout, STDOUT_FILENO);
		ft_execve(&av[ac - 2], env, pipex);
	}
	else
	{
		close(pipex->fd[1]);
		dup2(pipex->fd[0], STDIN_FILENO);
		close(pipex->fd[0]);
	}
}

void	ft_is_there_herdoc(char **av, int fd[2])
{
	char	*ret_line;

	close(fd[0]);
	while (1)
	{
		ret_line = get_next_line(0);
		if (ft_strncmp(ret_line, av[2], ft_strlen(av[2])) == 0)
		{
			free(ret_line);
			exit(0);
		}
		ft_putstr_fd(ret_line, fd[1]);
		free(ret_line);
	}
}

void	ft_here_doc(char **av)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
		ft_is_there_herdoc(av, fd);
	else
	{
		close (fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			ft_error_message("error message from dup2 in here_doc!");
		close (fd[0]);
	}
}

void	process_here_doc(int ac, char **av, t_bpipex *pipex)
{
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		pipex->i = 3;
		pipex->fileout = ft_open_files(av[ac - 1], 1);
		if (ac < 6)
			ft_error_message("Error from ac in here_doc!");
		ft_here_doc(av);
	}
	else
	{
		pipex->i = 2;
		pipex->fileout = ft_open_files(av[ac - 1], 0);
		pipex->filein = ft_open_files(av[1], 2);
		if (dup2(pipex->filein, STDIN_FILENO) < 0)
			ft_error_message("error from dup2 in process_heredoc!");
		close (pipex->filein);
	}
}
