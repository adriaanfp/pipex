/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflores- <aflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:12:41 by aflores-          #+#    #+#             */
/*   Updated: 2025/03/26 11:38:49 by aflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(int argc, char *argv[], char *env[], t_pipe *pipe_struct)
{
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		exit_error(1);
	create_pipe(pipe_struct);
	pid1 = fork_process();
	if (pid1 == 0)
	{
		pipe_struct->infile = open_file(argv[1], 0);
		close(pipe_struct->fd[0]);
		run_child_process(argv[2], env, pipe_struct);
	}
	pipe_struct->outfile = open_file(argv[4], 1);
	pid2 = fork_process();
	if (pid2 == 0)
	{
		close(pipe_struct->fd[1]);
		run_child_process(argv[3], env, pipe_struct);
	}
	close_pipe(pipe_struct);
	wait_for_children(pid1, pid2);
	return (0);
}
