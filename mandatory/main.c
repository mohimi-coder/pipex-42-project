/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:38:41 by mohimi            #+#    #+#             */
/*   Updated: 2024/02/18 11:57:34 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	*xpipe;

	xpipe = malloc(sizeof(t_pipex));
	if (!xpipe)
		ft_error_message(RED "error message from malloc!" RESET);
	pipex(ac, av, xpipe, envp);
	close(xpipe->fd[0]);
	close(xpipe->fd[1]);
	wait(NULL);
	wait(NULL);
	free (xpipe);
}
