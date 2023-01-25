/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:45:51 by melayoub          #+#    #+#             */
/*   Updated: 2023/01/11 16:10:02 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_word(char *str, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
		i++;
		if (str[i] != c && str[i])
		count += 1;
		while (str[i] != c && str[i])
		i++;
	}
	return (count);
}

static void	free_all(char **str)
{
	int	i;

	i = 0;
	if (!str[i])
	{
		while (str[i] != '\0')
		{
			free (str[i]);
			i++;
		}
		free (str);
	}
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	start;
	size_t	end;
	int		i;

	if (!s)
		return (0);
	str = (char **)malloc((count_word((char *)s, c) + 1) * sizeof(char *));
	if (!str)
		return (0);
	start = 0;
	i = 0;
	while (i < count_word((char *)s, c))
	{
		while (s[start] == c && s[start] != '\0')
			start++;
		end = start;
		while (s[end] != c && s[end] != '\0')
			end++;
		str[i++] = ft_substr((char *)s, start, end - start);
		free_all(str);
		start = end;
	}
	*(str + i) = NULL;
	return (str);
}