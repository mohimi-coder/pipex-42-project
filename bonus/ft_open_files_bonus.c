/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_files_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:03:11 by mohimi            #+#    #+#             */
/*   Updated: 2024/02/18 12:22:33 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_open_files(char *av, int i)
{
	int	fd;

	fd = -1;
	if (i == 0)
		fd = open(av, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (i == 1)
		fd = open(av, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (i == 2)
		fd = open(av, O_RDONLY, 0644);
	else if (i == -1)
		ft_error_message("Error from open!");
	return (fd);
}
