/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalorsan <aalorsan@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 10:40:34 by aalorsan          #+#    #+#             */
/*   Updated: 2026/03/05 10:40:37 by aalorsan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	count_string(char const *str, char c)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] != '\0')
			counter++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (counter);
}

static void	free_all(char **strings, int i)
{
	while (i > 0)
		free(strings[--i]);
	free(strings);
}

static char	*fill_word(char const **s, char c)
{
	char	*word;
	size_t	len;
	size_t	k;

	len = 0;
	while ((*s)[len] && (*s)[len] != c)
		len++;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	k = 0;
	while (**s && **s != c)
		word[k++] = *(*s)++;
	word[k] = '\0';
	return (word);
}

static int	fill_all(char **string, char const **s, char c)
{
	size_t	i;

	i = 0;
	while (**s)
	{
		while (**s && **s == c)
			(*s)++;
		if (**s)
		{
			string[i] = fill_word(s, c);
			if (!string[i])
				return (free_all(string, i), 0);
			i++;
		}
	}
	string[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**string;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_string(s, c);
	string = malloc(sizeof(char *) * (words + 1));
	if (!string)
		return (NULL);
	if (!fill_all(string, &s, c))
		return (NULL);
	return (string);
}
