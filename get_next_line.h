/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhedjam <hhedjam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:27:36 by hhedjam           #+#    #+#             */
/*   Updated: 2024/02/03 15:23:26 by hhedjam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}			t_list;

void	read_stock(int fd, t_list **stock);
void	add_stock(t_list **stock, char *buff, int charnbr);
void	extract_line(t_list *stock, char **line);
void	create_line(char **line, t_list *stock);
void	erased_stock(t_list **stock);
void	free_stock(t_list *stock);
int		strchr_list(t_list *stock);
t_list	*get_last(t_list *stock);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);

#endif