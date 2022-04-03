/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:24:25 by tdeville          #+#    #+#             */
/*   Updated: 2022/03/29 16:45:00 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft2/include/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_commands t_commands;
typedef struct s_data_p t_data_p;
typedef struct s_hd_data t_hd_data;

struct s_commands
{
	char	**args_vec;
	char	*cmd_path;
	char	*here_doc;
	int		infile;
	int		outfile;
	int		infile_type;
};

struct s_hd_data
{
	int		expend_var;
	int		check;
	char	*tmp;
	char	*tmp1;
	char	*new_buffer;
	char	*here_doc_del;
};

struct s_data_p
{
	char		*stdin_arg;
	char    	*path;
	char    	**env_path;
	char		**args;
	char		**env_vars;
	int			pipes_nb;
	int			args_create;
	t_commands	*commands;
	t_hd_data	hd_data;
	t_track		*track;
};

/* ------------------- PARSING ------------------- */
	// Bin Path
int		find_env_path(char **envp, t_data_p *data);
int		ft_access(char *arg);
char	*expend_env_var(t_data_p *data, char **envp, char *var);

	// Lexer
int		lexer(char *arg, t_data_p *data);
int		pipe_check(char *arg, int i);
int		synthax_checker(char *arg);
int		split_args(char *arg, t_data_p *data);
int		create_arg(char *str, int i, t_data_p *data, int bad_pipe);
int		count_pipes(char *str);
int		pipe_synthax(char *str, t_data_p data);

	// Here_doc
int		check_heredoc(char *arg, t_data_p *data, int idx);
int		get_heredoc_del(char *arg, int i, t_data_p *data);
int		ft_here_doc(t_data_p *data, int idx);
int		here_doc_write(t_data_p *data, char *buffer, int idx);
char	*expend_var_in_buffer(char *buffer, char **expended_vars, t_data_p *data);
int		format_del(char *del, t_data_p *data);
void	fill_vars_tab(t_data_p *data, char **var, char *buffer, int *idx, int *k);
char	*get_expend_var(t_data_p *data, char *buffer);
	// Here_doc utils
int		nb_of_env_vars(char *buffer);
char	*check_bsn_buffer(t_data_p *data, char *new_buffer);
int		check_var(char *var);
char	*trim_last_bsn(t_data_p *data, char *here_doc_content);
int		check_del(char *del);
	// Clear here_doc
char	*clear_here_doc(t_data_p *data, char *arg);


	// Utils
int 	state_checker(char *str, int start, int len);

	// Expend variables
int		check_arg_vars(char *arg, t_data_p *data);
char	**get_exp_vars_arg(char *arg, t_data_p *data);

#endif
