/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:00:03 by mohimi            #+#    #+#             */
/*   Updated: 2024/02/18 21:58:32 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execve(char *cmd, char **envp, t_pipex *xpipe)
{
	xpipe->split_cmd = ft_split(cmd, ' ');
	xpipe->chec = ft_get_path(envp);
	if (!xpipe->split_cmd[0] || !xpipe->chec)
		ft_error_message(GREEN "command not found!" RESET);
	xpipe->result = check_cmd(xpipe->chec, xpipe->split_cmd);
	if (xpipe->result)
	{
		if (execve(xpipe->result, xpipe->split_cmd, envp) == -1)
			ft_error_message(CYAN "error message from execve!" RESET);
	}
	else
		ft_error_message(YELLOW "error from access!" RESET);
}

void	child_process1(char **av, t_pipex *xpipe, char **envp)
{
	xpipe->filein = open(av[1], O_RDONLY, 0644);
	if (xpipe->filein == -1)
	{
		(close(xpipe->fd[0]), close(xpipe->fd[1]));
		ft_error_message(MAGENTA "error message from filein!" RESET);
	}
	close(xpipe->fd[0]);
	if (dup2(xpipe->filein, STDIN_FILENO) < 0)
		ft_error_message("error from dup2 in child2!");
	close(xpipe->filein);
	if (dup2(xpipe->fd[1], STDOUT_FILENO) < 0)
		ft_error_message("error from dup2 in child2!");
	close(xpipe->fd[1]);
	ft_execve(av[2], envp, xpipe);
}

void	child_process2(char **av, t_pipex *xpipe, char **envp)
{
	xpipe->fileout = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (xpipe->fileout == -1)
	{
		(close(xpipe->fd[0]), close(xpipe->fd[1]));
		ft_error_message(BLUE "error message from fileout!" RESET);
	}
	close(xpipe->fd[1]);
	if (dup2(xpipe->fd[0], STDIN_FILENO) < 0)
		ft_error_message("error from dup2 in child2!");
	close(xpipe->fd[0]);
	if (dup2(xpipe->fileout, STDOUT_FILENO) < 0)
		ft_error_message("error from dup2 in child2!");
	close(xpipe->fileout);
	ft_execve(av[3], envp, xpipe);
}

void	pipex(int ac, char **av, t_pipex *xpipe, char **envp)
{
	if (ac != 5)
		ft_error_message(RED "error message from ac!" RESET);
	if (!envp)
		ft_error_message(YELLOW "error message from envp!" RESET);
	if (pipe(xpipe->fd) < 0);
		ft_error_message(YELLOW "error message from pipe!" RESET);
	xpipe->pid1 = fork();
	if (xpipe->pid1 == -1)
		ft_error_message(BLUE "error message from pid1!" RESET);
	if (xpipe->pid1 == 0)
		child_process1(av, xpipe, envp);
	xpipe->pid2 = fork();
	if (xpipe->pid2 == -1)
		ft_error_message(RED "error message from pid2!" RESET);
	if (xpipe->pid2 == 0)
		child_process2(av, xpipe, envp);
}
