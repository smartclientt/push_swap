/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:06:22 by shbi              #+#    #+#             */
/*   Updated: 2022/07/18 15:16:57 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstcount(t_list *lst);
void	ft_lstadd_end(t_list **lst, t_list *new);
void	ft_lstadd_to_pos(t_list **lst, t_list *new, int pos);
void	ft_lstdelete_first(t_list **lst);
void	ft_lstdelete_last(t_list **lst);
void	ft_lstdelete_pos(t_list **lst, int pos);
void	ft_lstdelete_all(t_list **lst);
t_list	*ft_free(t_list **lst);
void	sa_operation(t_list **lst);
void	ra_operation(t_list **lst);
void	rra_operation(t_list **lst);


#endif
