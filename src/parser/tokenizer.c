/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:24:48 by davioliv          #+#    #+#             */
/*   Updated: 2024/08/18 22:24:50 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	tokenizer(t_mini *ms)
{
	int	i;

	i = 0;
	while (ms->input[i])
	{
		if (check_space(ms->input[i]))
			i++;
		else if (ms->input[i] == '|')
			i += put_token_lst(ms->input[i], PIPE, ms->token_lst);
		else if (ms->input[i] == '>' && ms->input[i + 1] != '>')
			i += put_token_lst(ms->input[i], REDIR_OUT, ms->token_lst);
		else if (ms->input[i] == '>' && ms->input[i + 1] == '>')
			i += put_token_lst(">>", APPEND, ms->token_lst);
		else if (ms->input[i] == '<' && ms->input[i + 1] != '<')
			i += put_token_lst(ms->input[i], REDIR_IN, ms->token_lst);
		else if (ms->input[i] == '<' && ms->input[i + 1] == '<')
			i += put_token_lst("<<", HEREDOC, ms->token_lst);
		else
			i += put_token_lst(set_input(ms->input), COM_ARG_EXP, ms->token_lst);
	}
}

int	put_token_lst(char *content, t_type type, t_token **token_lst)
{
	t_token	*token;
	t_token	*last;
	int		len;

	len = ft_strlen(content);
	token = new_token(content, type);
	last = *token_lst;
	while (last->next)
		last = last->next;
	token->prev = last;
	last->next = token;
	return (len);
}
