/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:37:41 by shbi              #+#    #+#             */
/*   Updated: 2022/07/18 15:20:21 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_operation(t_list **lst)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (!*lst)
		return ;
	else
	{
		tmp1 = (*lst);
		tmp2 = (*lst)->next;
		*lst = tmp2;
		tmp1->next = tmp2->next;
		tmp2->next = tmp1;
	}
}

void	ra_operation(t_list **lst)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (!*lst)
		return ;
	else
	{
		tmp1 = *lst;
		tmp2 = (*lst)->next;
		*lst = tmp2;
		tmp1->next = NULL;
		while (tmp2->next != NULL)
			tmp2 = tmp2->next;
		tmp2->next = tmp1;
	}
}

void	rra_operation(t_list **lst)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	if (!*lst)
		return ;
	else
	{
		tmp1 = *lst;
		tmp2 = *lst;
		while (tmp2->next != NULL)
		{
			tmp3 = tmp2;
			tmp2 = tmp2->next;
			if (tmp2->next == NULL)
				*lst = tmp2;
		}
		tmp3->next = NULL;
		tmp2->next = tmp1;
	}
}
