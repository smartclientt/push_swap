/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:55:59 by shbi              #+#    #+#             */
/*   Updated: 2022/07/16 06:10:21 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new->next = *lst;
		lst = &new;
	}
}

int	ft_lstcount(t_list *lst)
{
	int		count;
	t_list	*current;

	count = 0;
	current = lst;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

void	ft_lstadd_end(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (*lst && new)
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*lst = new;
}

void	ft_lstadd_to_pos(t_list **lst, t_list *new, int pos)
{
	t_list	*tmp;
	int		i;

	if (*lst && new)
	{
		tmp = *lst;
		if (pos == 1)
			ft_lstadd_front(&tmp, new);
		else
		{
			i = 1;
			while (i++ < pos)
				tmp = tmp->next;
			new->next = tmp->next;
			tmp->next = new;
		}
	}
	else
		*lst = new;
}
