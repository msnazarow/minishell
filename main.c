/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelisabe <nelisabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 23:40:05 by sgertrud          #+#    #+#             */
/*   Updated: 2020/11/18 15:50:40 by nelisabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <termios.h>
#include "parse.h"
#include "main.h"

int	main(int argc, char **argv, char **envp)
{
	argc = argc;
	argv = argv;
	struct termios term;
	char *str;
	char **command;
	char *temp;
	t_envp *_envp;

	_envp = envp_create_list(envp);
	set_terminal_mode(term);
	while (1)
	{
		write(1, GREEN, 5);
		write(1,"minishell: ", 12);
		write(1, RESET, 5);
		str = read_line(term);
		temp = str;
		//printf("Your commands are:\n");
		while (*str && *str != '\n')
		{
			command = parse_command(&str, _envp);
			do_command(command, &_envp, term);
			str++;
			/*printf("Your arguments are: {");
			while (*command)
				printf("[%s] ",*command++);
			str++;
			printf("}\n");*/
		}
		free(temp);
	}

	return (0);
}