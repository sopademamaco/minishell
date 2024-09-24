/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 23:28:20 by davioliv          #+#    #+#             */
/*   Updated: 2024/08/18 23:28:21 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*new_token(char *content, t_type type)
{
	t_token	*new_token;

	new_token = malloc(sizeof(t_token));
	if (!nem_token)
		return (NULL);
	new_token->content = content;
	new_token->type = type;
	new_token->next = NULL;
	new_token->prev = NULL;
	return (new_token);
}

char	*set_input(char *content)
{
	char	*input;
	int		i;
	int		csq; //check single quotes
	int		cdq; //check double quotes

	i = 0;
	csq = 0;
	cdq = 0;
	while (content[i])
	{
		if (content[i] == '\'' && !cdq)
			csq = !csq;
		else if (content[i] == '"' && !csq)
			cdq = !cdq;
		else if ((content[i] == '|' || content[i] == '<' || content[i] == '>' || content[i] == ' ') && csq == 0 && cdq == 0)
			break ;
		i++;
	}
	input = ft_substr(content, 0, i);
	return (input);
}
/*void	insert_token(t_token *token)
{
	t_token	*prev;

	token->prev = prev;*/
