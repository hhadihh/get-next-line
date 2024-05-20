/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhedjam <hhedjam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:27:27 by hhedjam           #+#    #+#             */
/*   Updated: 2024/02/03 15:04:15 by hhedjam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	create_line(char **line, t_list *stock)
{
	int	i;
	int	len;

	len = 0;
	while (stock)
	{
		i = 0;
		while (stock -> content[i])
		{
			if (stock -> content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		stock = stock -> next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

void	erased_stock(t_list **stock)
{
	t_list	*last;
	t_list	*clean;
	int		i;
	int		j;

	clean = malloc(sizeof(t_list));
	if (stock == NULL || clean == NULL)
		return ;
	clean -> next = NULL;
	last = get_last(*stock);
	i = 0;
	while ((last -> content[i]) && (last -> content[i] != '\n'))
		i++;
	if (last ->content && last -> content[i] == '\n')
		i++;
	clean->content = malloc(sizeof(char) *((ft_strlen(last->content) - i) + 1));
	if (clean -> content == NULL)
		return ;
	j = 0;
	while (last -> content[i])
		clean -> content[j++] = last -> content[i++];
	clean -> content[j] = '\0';
	free_stock(*stock);
	*stock = clean;
}

int	strchr_list(t_list *stock)
{
	int		i;
	t_list	*current;

	i = 0;
	if (stock == NULL)
		return (0);
	current = get_last(stock);
	while (current -> content[i])
	{
		if (current -> content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*get_last(t_list *stock)
{
	t_list	*current;

	current = stock;
	while (current && current -> next)
		current = current -> next;
	return (current);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
