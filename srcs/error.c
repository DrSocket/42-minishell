/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:40:53 by jfeuilla          #+#    #+#             */
/*   Updated: 2021/03/16 18:40:53 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int			is_quote_dir_pair(char *s, int i, char quote, char dir)
{
	int		j;
	int		count;
	int		signe;

	j = i;
	count = 0;
	if (dir == '<')
		signe = -1;
	else
		signe = 1;
	while (j >= 0 && s[j])
	{
		if (s[j] == quote)
			count++;
		j = j + signe * 1;
	}
	return (count % 2);
}

int			n_inside_q(char *s, int i)
{
	if (i == ft_strlen(s) - 1)
		return (0);
	if (is_quote_dir_pair(s, i, '"', '<') == 1 && ft_strchr(s + i, '"') != NULL)
		return (1);
	if (is_quote_dir_pair(s, i, 39, '>') == 1 && ft_strchr(s + i, 39) != NULL)
		return (1);
	return (0);
}

int			check_error_unexpected2(char *s, int *j)
{
	int	i;

	i = *j;
	*j = i;
	if (s[i] && (s[i] == '|' || s[i] == ';') && n_inside_q(s, i) == 0)
		return (print_error_unexpected(s[i]));
	if (s[i] && (s[i] == '<' || s[i] == '>') && n_inside_q(s, i) == 0)
		return (print_error_nl_expected());
	while (s[i] && s[i] == ' ')
		i++;
	if (s[i] && (s[i] == '|' || s[i] == ';') && n_inside_q(s, i) == 0)
		return (print_error_unexpected(s[i]));
	if (s[i] && (s[i] == '<' || s[i] == '>') && n_inside_q(s, i) == 0)
		return (print_error_nl_expected());
	return (0);
}

int			check_error_unexpected(char *s)
{
	int		i;

	i = -1;
	if (s[0] && (s[0] == '|' || s[0] == ';'))
		return (print_error_unexpected(s[0]));
	if (s[0] && s[0] == '<')
		return (print_error_unexpected(s[0]));
	while (s[++i])
	{
		if ((s[i] == '|' || s[i] == ';') && s[i + 1])
		{
			i++;
			if (check_error_unexpected2(s, &i) != 0)
				return (1);
		}
		if ((s[i] == '<' || s[i] == '>') && s[i + 1])
		{
			i++;
			if (s[i] && (s[i] == '|' || s[i] == ';')
			&& n_inside_q(s, i) == 0)
				return (print_error_unexpected(s[i]));
		}
	}
	return (0);
}

int			check_red(char *line)
{
	int		i;

	i = ft_strlen(line);
	if (check_err(line) == 1)
		return (print_error_unexpected('>'));
	if (check_err_bis(line) == 1)
		return (print_error_unexpected('<'));
	if (i > 0)
	{
		if (line[i - 1] == '<' || line[i - 1] == '>')
			return (print_error_nl_expected());
	}
	return (0);
}
