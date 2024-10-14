/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   family.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsmith <trsmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:48:33 by trsmith           #+#    #+#             */
/*   Updated: 2024/10/09 13:54:25 by trsmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_op(char **argv, int *fd, char **envp)
{
	int	file_input;

	file_input = open(argv[1], O_RDONLY, 0777);
	if (file_input == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(file_input, STDIN_FILENO);
	close(fd[0]);
	execute(argv[2], envp);
}

void	parent_op(char **argv, char **envp, int *fd)
{
	int	file_output;

	file_output = open(argv[4], O_WRONLY, O_CREAT, O_TRUNC);
	if (file_output == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(file_output, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}
