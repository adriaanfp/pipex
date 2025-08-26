/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aflores- <aflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:55:49 by aflores-          #+#    #+#             */
/*   Updated: 2025/03/19 16:31:25 by aflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "LIBFT/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipe
{
	int	infile;
	int	outfile;
	int	fd[2];
}		t_pipe;

void	exit_error(int n_exit);
char	*get_path(char *cmd, char **env);
void	free_tab(char **tab);
int		open_file(char *file, int in_out);
void	wait_for_children(pid_t pid1, pid_t pid2);
void	create_pipe(t_pipe *pipe_struct);
pid_t	fork_process(void);
int		ft_strcmp(const char *s1, const char *s2);
void	close_pipe(t_pipe *pipe_struct);
void	run_child_process(char *command, char *env[], t_pipe *pipe_struct);
int		pipex(int argc, char *argv[], char *env[], t_pipe *pipe_struct);

#endif
