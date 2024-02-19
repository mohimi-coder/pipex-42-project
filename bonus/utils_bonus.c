/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohimi <mohimi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:02:28 by mohimi            #+#    #+#             */
/*   Updated: 2024/02/18 12:26:11 by mohimi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_searsh_for_slash(const char *s, int c)
{
	unsigned int	i;
	char			chr;

	i = 0;
	chr = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == chr)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

void	ft_error_message(char *mess)
{
	int	i;

	i = 0;
	while (mess[i])
	{
		write (2, &mess[i], 1);
		i++;
	}
	write (2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	ft_free_leak(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**ft_get_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			return (ft_split(env[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

char	*check_cmd(char **envp, char **cmd)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	if (ft_searsh_for_slash(cmd[0], '/') != 0)
		return (cmd[0]);
	else if (ft_searsh_for_slash(cmd[0], '.') != 0)
		return (cmd[0] + 2);
	while (envp[i])
	{
		tmp = ft_strjoin(envp[i], "/");
		tmp2 = ft_strjoin(tmp, cmd[0]);
		free(tmp);
		if (access(tmp2, F_OK) == 0)
		{
			ft_free_leak(envp);
			return (tmp2);
		}
		free(tmp2);
		i++;
	}
	ft_free_leak(envp);
	return (NULL);
}
