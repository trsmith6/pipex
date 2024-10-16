/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsmith <trsmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:27:37 by trsmith           #+#    #+#             */
/*   Updated: 2024/10/09 13:52:47 by trsmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	int	fd[2];
	pid_t	pid1;

	if (argc == 5)
		{
			if (pipe(fd) == -1)
				error();
			pid1 = fork();
			if (pid1 == -1)
				error();
			if (pid1 == 0)
				child_op(argv, envp, fd);
			waitpid(pid1, NULL, 0);
			parent_op(argv, envp, fd);
		}
}

void	errmssg(int err)
{
	if (err == 1)
		ft_putstr_fd("./pipex file1 cmd1 cmd2 file2\n", 2);
	exit (0);
}
void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

char	*pathfndr(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[1], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free (path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	int		i;
	char	*path;

	i = -1;
	cmd = ft_split(argv, ' ');
	path = pathfndr(cmd[0], envp);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		error();
	}
	if (execve(path, cmd, envp) == -1)
		error();
}
