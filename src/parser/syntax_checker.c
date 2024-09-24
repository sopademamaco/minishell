/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 23:58:57 by davioliv          #+#    #+#             */
/*   Updated: 2024/08/28 23:58:58 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	syntax_check(t_mini *ms)
{
	t_token	*token_lst;

	ms->token_lst = token_lst;
	while (token_lst->next)
	{
		
