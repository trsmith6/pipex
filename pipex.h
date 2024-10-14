/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trsmith <trsmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:24:33 by trsmith           #+#    #+#             */
/*   Updated: 2024/10/09 13:55:58 by trsmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

		//includes//
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "main-libs/libft/libft.h"
# include "main-libs/printf/ft_printf.h"
# include "main-libs/gnl/get_next_line.h"

		//pipex.c//
int		main(int argc, char *argv[], char **envp);
void	errmssg(int err);
void	error(void);
char	*pathfndr(char *cmd, char **envp);
void	execute(char *argv, char **envp);

		//family.c//
void	child_op(char **argv, char **envp, int *fd);
void	parent_op(char **argv, char **envp, int *fd);

#endif