/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflores- <aflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:22:17 by aflores-          #+#    #+#             */
/*   Updated: 2025/03/26 11:35:38 by aflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_for_children(pid_t pid1, pid_t pid2)
{
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

void	create_pipe(t_pipe *pipe_struct)
{
	pipe_struct->infile = 0;
	pipe_struct->outfile = 1;
	if (pipe(pipe_struct->fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
}

void	close_pipe(t_pipe *pipe_struct)
{
	close(pipe_struct->fd[0]);
	close(pipe_struct->fd[1]);
}

pid_t	fork_process(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	return (pid);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
