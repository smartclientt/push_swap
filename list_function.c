/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:55:59 by shbi              #+#    #+#             */
/*   Updated: 2022/07/18 14:45:09 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_free(t_list **lst)
{
	if (*lst)
	{
		free(*lst);
		*lst = NULL;
	}
	return (*lst);
}

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

void	ft_lstdelete_first(t_list **lst)
{
	t_list	*tmp;

	if (!*lst)
	{
		write (1, "wache \n", 7);
		exit(0);
	}
	else if ((*lst)->next == NULL)
	{
		free(*lst);
		*lst = NULL;
	}
	else
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
		tmp = NULL;
	}
}

void	ft_lstdelete_last(t_list **lst)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (!*lst)
		return ;
	else if ((*lst)->next == NULL)
	{
		free(*lst);
		*lst = NULL;
	}
	else
	{
		tmp1 = *lst;
		tmp2 = *lst;
		while (tmp1->next != NULL)
		{
			tmp1 = tmp1->next;
			if (tmp1->next != NULL)
				tmp2 = tmp2->next;
		}
		tmp2->next = NULL;
		ft_free(&tmp1);
	}
}

void	ft_lstdelete_pos(t_list **lst, int pos)
{
	t_list	*current;
	t_list	*previous;

	if (pos > ft_lstcount(*lst) || pos < 1 || *lst == NULL)
		return ;
	else if (pos == 1)
		ft_lstdelete_first(lst);
	else
	{
		current = *lst;
		previous = *lst;
		while (pos-- > 1)
		{
			current = current->next;
			if (pos > 1)
				previous = previous->next;
		}
		previous->next = current->next;
		free(current);
		current = NULL;
	}
}

void	ft_lstdelete_all(t_list **lst)
{
	t_list	*tmp;

	if (!*lst)
		return ;
	else
	{
		tmp = *lst;
		while (tmp)
		{
			tmp = tmp->next;
			free(*lst);
			*lst = NULL;
		}
		ft_free(&tmp);
	}
}
