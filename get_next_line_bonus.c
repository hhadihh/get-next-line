/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhedjam <hhedjam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:10:06 by hhedjam           #+#    #+#             */
/*   Updated: 2024/02/03 15:49:05 by hhedjam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_list	*stock;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || (read(fd, &line, 0) < 0))
		return (NULL);
	line = NULL;
	read_stock(fd, &stock);
	if (stock == NULL)
		return (NULL);
	extract_line(stock, &line);
	erased_stock(&stock);
	if (line[0] == '\0')
	{
		free_stock(stock);
		stock = NULL;
		free (line);
		return (NULL);
	}
	return (line);
}

void	free_stock(t_list *stock)
{
	t_list	*current;
	t_list	*next;

	current = stock;
	while (current)
	{
		free(current ->content);
		next = current -> next;
		free (current);
		current = next;
	}
}

void	read_stock(int fd, t_list **stock)
{
	char	*buff;
	int		charnbr;

	charnbr = 1;
	while (!(strchr_list(*stock)) && charnbr != 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return ;
		charnbr = (int)read(fd, buff, BUFFER_SIZE);
		buff[charnbr] = '\0';
		if ((*stock == NULL && charnbr == 0) || charnbr < 0)
			return (free(buff));
		buff[charnbr] = '\0';
		add_stock(stock, buff, charnbr);
		free(buff);
	}
}

void	add_stock(t_list **stock, char *buff, int charnbr)
{
	int		i;
	t_list	*last;
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return ;
	node -> next = NULL;
	node -> content = malloc(sizeof(char) * (charnbr + 1));
	if (node -> content == NULL)
		return ;
	i = 0;
	while (buff[i] && i < charnbr)
	{
		node -> content[i] = buff[i];
		i++;
	}
	node -> content[i] = '\0';
	if (*stock == NULL)
	{
		*stock = node;
		return ;
	}
	last = get_last(*stock);
	last -> next = node;
}

void	extract_line(t_list *stock, char **line)
{
	int	i;
	int	j;

	if (stock == NULL)
		return ;
	create_line(line, stock);
	if (*line == NULL)
		return ;
	j = 0;
	while (stock)
	{
		i = 0;
		while (stock -> content[i])
		{
			if (stock -> content[i] == '\n')
			{
				(*line)[j++] = stock-> content[i];
				break ;
			}
			(*line)[j++] = stock -> content[i++];
		}
		stock = stock -> next;
	}
	(*line)[j] = '\0';
}
