/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:01:54 by mohimi            #+#    #+#             */
/*   Updated: 2024/02/19 10:37:41 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	t_bpipex	*pipex;

	pipex = malloc(sizeof(t_bpipex));
	if (!pipex)
		ft_error_message("error from malloc!");
	if (ac < 5)
		ft_error_message("error from ac!");
	process_here_doc(ac, av, pipex);
	while (pipex->i < ac - 2)
	{
		dprintf(2, "%s\n", av[pipex->i]);
		first_middle_cmds(av[pipex->i++], envp, pipex);
	}
	last_cmd(ac, av, envp, pipex);
	close (pipex->fileout);
	close (0);
	free(pipex);
	while (wait(NULL) != -1)
		;
}
