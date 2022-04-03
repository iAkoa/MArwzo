/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_pipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 19:08:44 by rmattheo          #+#    #+#             */
/*   Updated: 2022/04/03 04:05:08 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/exec.h"

void	e_heredoc_pipe(t_data_p *data, t_commands *c, int i)
{
	int	pfd_heredoc[2];
	c[i].pipe_heredoc0 = pfd_heredoc[0];
	c[i].pipe_heredoc1 = pfd_heredoc[1];
	dprintf(2, "c.pipe heredoc 1 == %i\n", c->pipe_heredoc1);
	dprintf(2, "c.pipe heredoc 0 == %i\n", c->pipe_heredoc0);
}

void	open_all_pipe(t_data_p *data, t_commands *c)
{
	int	i;
	
	i = -1;
	int	pfd[2];
	while (++i <= data->pipes_nb)
	{
		pipe(pfd);
		c[i].next_pfd1 = pfd[1];
		c[i].next_pfd0 = pfd[0];
		if (i >= 1)
		{
			c[i].last_pfd1 = c[i - 1].next_pfd1;
			c[i].last_pfd0 = c[i - 1].next_pfd0;
		}
	}
	
}

void	close_all_pipe(t_commands *c)
{
	int	i;

	i = -1;
	while(!c[++i].stop)
	{
		if (c[i].next_pfd0)
			if(close (c[i].next_pfd0))
				exit(1);
		if (c[i].next_pfd1)
			if(close (c[i].next_pfd1))
				exit(1);
		if (c[i].last_pfd0)
			if(close (c[i].next_pfd0))
				exit(1);
		if (c[i].last_pfd1)
			if(close (c[i].next_pfd1))
				exit(1);
				if (c[i].last_pfd0)
			if(close (c[i].next_pfd0))
				exit(1);
		if (c[i].pipe_heredoc0)
			if(close (c[i].pipe_heredoc0))
				exit(1);
		if (c[i].pipe_heredoc1)
			if(close (c[i].pipe_heredoc1))
				exit(1);
	}
}