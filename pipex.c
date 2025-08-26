/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflores- <aflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:55:30 by aflores-          #+#    #+#             */
/*   Updated: 2025/03/26 11:34:52 by aflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_command(char *cmd, char **env)
{
	char	**arguments;
	char	*path;

	arguments = ft_split(cmd, ' ');
	if (!arguments)
		exit_error(1);
	path = get_path(arguments[0], env);
	if (!path)
	{
		free_tab(arguments);
		exit_error(1);
	}
	if (execve(path, arguments, env) == -1)
	{
		perror("execve");
		free_tab(arguments);
		free(path);
		exit(EXIT_FAILURE);
	}
}

void	run_child_process(char *command, char *env[], t_pipe *pipe_struct)
{
	if (pipe_struct->infile != STDIN_FILENO)
	{
		dup2(pipe_struct->infile, STDIN_FILENO);
		close(pipe_struct->infile);
	}
	else
	{
		dup2(pipe_struct->fd[0], STDIN_FILENO);
		close(pipe_struct->fd[0]);
	}
	if (pipe_struct->outfile != STDOUT_FILENO)
	{
		dup2(pipe_struct->outfile, STDOUT_FILENO);
		close(pipe_struct->outfile);
	}
	else
	{
		dup2(pipe_struct->fd[1], STDOUT_FILENO);
		close(pipe_struct->fd[1]);
	}
	close_pipe(pipe_struct);
	execute_command(command, env);
	perror("execve");
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[], char *env[])
{
	t_pipe	*pipe_main;

	pipe_main = malloc(sizeof(t_pipe));
	pipex(argc, argv, env, pipe_main);
	free(pipe_main);
	return (0);
}
