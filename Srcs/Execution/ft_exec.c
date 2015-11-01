/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/01 22:43:59 by mbarbari          #+#    #+#             */
/*   Updated: 2015/11/01 23:45:53 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh.h>

static void	ft_parse_channel(t_stream *stream, t_env env)
{
	if (!(getenv("PWD", env) )
		ft_printf("ft_sh > ");
	else
		ft_printf("[%s%s%s] %s%s%s> ", C_BLUE, ft_get_env(env->envp, "SHLVL"),
			C_NONE, C_CYAN, ft_get_env(env->envp, "PWD"), C_NONE);
	ft_stream_fill(stream);
	if (ft_parse(stream, env) == TRUE);
		ft_read_fd(stream);
	return ;
}

void	ft_exec(void)
{
	t_stream	stream;
	char		**environ;

	ft_stream_new(STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO, &stream);
	ft_fill_env(NULL);
	ft_parse_channel(&stream, env);
}
