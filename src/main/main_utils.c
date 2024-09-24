/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davioliv <davioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:41:53 by davioliv          #+#    #+#             */
/*   Updated: 2024/08/18 22:41:54 by davioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_space_spam(char *input)
{
	int	i;
	int	is_space;

	i = 0;
	is_space = YES;
	while (input[i])
	{
		if (input[i] != ' ' || input[i] != '\t' || input[i] != '\n' || input[i] != '\v' || input[i] != '\f')
			is_space = NO;
		else
			is_space = YES;
		i++;
	}
	return (is_space);
}

int	check_space(char input)
{
	if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n' || input[i] == '\v' || input[i] == '\f')
		return (YES);
	else
		return (NO);
}		
