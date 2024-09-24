/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:33:46 by davioliv          #+#    #+#             */
/*   Updated: 2024/07/25 15:33:47 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minishell.h"

char	*read_pwd(void);

int	main(int argc, char **argv)
{
	t_mini	ms;
	char	*prompt;

	prompt = read_pwd();
	if (argc != 1)
	{
		ft_printf("minishell: %s: no such file or directory\n", argv[1]);
		return (0);
	}
	while (2)
	{
		ms.input = readline(prompt);
		if (check_space_spam(ms.input) == NO)
			parser(&ms);
	}
}

char	*read_pwd(void)
{
	char	*buf;
	char	*prompt;

	buf = (char *)malloc(4096);
	if (!buf)
		return (0);
	prompt = getcwd(buf, 4096);
	prompt = ft_strjoin(prompt, "/ ");
	free(buf);
	return (prompt);
}
