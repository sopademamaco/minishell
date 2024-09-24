/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:34:11 by davioliv          #+#    #+#             */
/*   Updated: 2024/07/25 15:34:13 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define NO	1
# define YES	0

# include "../libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef enum e_type
{
	PIPE,
	REDIR_OUT,
	APPEND,
	REDIR_IN,
	HEREDOC,
	COM_ARG_EXP
}		t_type;

typedef struct s_token
{
	char	*content;
	t_type	type;
	struct s_token	*next;
	struct s_token	*prev;
}		t_token;

typedef struct s_mini
{
	char	*input;
	t_token	*token_lst;
}		t_mini;

//	main

int	check_space_spam(char *input);
int	check_space(char input);

//	parser

void	tokenizer(t_mini *ms);
int		put_token_lst(char *content, t_type type, t_token **token_lst);
t_token	*new_token(char *content, t_type type);
char	*set_input(char *content);

#endif
