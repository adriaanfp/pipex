/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflores- <aflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:43:01 by aflores-          #+#    #+#             */
/*   Updated: 2025/01/29 18:48:58 by aflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_error(int n_exit)
{
	if (n_exit == 1)
		ft_putstr_fd("./pipex infile cmd cmd outfile\n", 2);
		exit(1);
}

int	open_file(char *file, int in_out)
{
	int  storage;

	if (in_out == 0)
		storage = open(file, O_RDONLY, 0777);
	if (in_out == 1)
		storage = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (storage == -1)
	{	
		perror("Error abriedo el archivo");
		exit(1);
	}
	return (storage);
}

void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*my_getenv(char *name, char **env)
{
	int	i;
	int	j;
	char *sub_char;

	i = 0;
	while (env[i])
	{
		while (env[i][j] && env[i][j] != '=')
		j++;
		sub_char = ft_substr(env[i], 0, j);
		if (ft_strcmp(sub_char, name) == 0)
		{
			free(sub_char);
			return (env[i] + j + 1);
		}
		free(sub_char);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	*exec;
	char	**allpath;
	char	*path_part;
	char	**s_cmd;

	i = -1;
	allpath = ft_split(my_getenv("PATH", env), ':');
	s_cmd = ft_split(cmd, ' ');
	while (allpath[++i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_ft_strjoin(path_part, s_cmd[0]);
		free(path_part);
		if (access(exec, F_OK | X_OK == 0))
		{
			free_tab(s_cmd);
			return (exec);
		}
		free(exec);
	}
	free_tab(allpath);
	free_tab(s_cmd);
	return (cmd);
}

