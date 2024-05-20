/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhedjam <hhedjam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:46:23 by hhedjam           #+#    #+#             */
/*   Updated: 2024/02/03 15:49:29 by hhedjam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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

char	*get_next_line(int fd);
void	read_stock(int fd, t_list **stock);
void	add_stock(t_list **stock, char *buff, int charnbr);
void	extract_line(t_list *stock, char **line);
void	create_line(char **line, t_list *stock);
void	erased_stock(t_list **stock);
void	free_stock(t_list *stock);
int		strchr_list(t_list *stock);
t_list	*get_last(t_list *stock);
size_t	ft_strlen(const char *s);

#endif