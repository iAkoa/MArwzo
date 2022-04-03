/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:10:09 by pat               #+#    #+#             */
/*   Updated: 2022/04/03 15:05:04 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/exec.h"


int main (int argc, char **argv, char **envp)
{
	int infile = open("infile", O_RDONLY);
	int outfile = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0660);
	t_data_p d;
	int i = 0;
	d.pipes_nb = 3;
	d.commands = calloc(sizeof(t_commands), 4);
	d.commands[0].infile = infile;
	d.commands[0].outfile = 0;
	d.commands[0].here_doc = "Bonjour je m'appelle steel\n\n";
	d.commands[0].infile_type = 2;
	d.commands[0].cmd_path = "/bin/cat";
	d.commands[0].args_vec = ft_split(argv[1], ' ');
	d.commands[0].envp = envp;

	d.commands[1].infile = 0;
	d.commands[1].outfile = 0;
	d.commands[1].here_doc = 0;
	d.commands[1].infile_type = 0;
	d.commands[1].cmd_path = "/bin/cat";
	d.commands[1].args_vec = ft_split(argv[2], ' ');
	d.commands[1].envp = envp;

	d.commands[2].infile = 0;
	d.commands[2].outfile = outfile;
	d.commands[2].here_doc = 0;
	d.commands[2].infile_type = 0;
	d.commands[2].cmd_path = "/bin/cat";
	d.commands[2].args_vec = ft_split(argv[3], ' ');
	d.commands[2].envp = envp;
	d.commands[3].stop = 1;
	e_exec(&d, d.commands);
	
	return (0);
}