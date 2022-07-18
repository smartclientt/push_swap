/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shbi <shbi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:06:15 by shbi              #+#    #+#             */
/*   Updated: 2022/07/18 15:17:03 by shbi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_list *n1, *n2, *n3, *n4, *current;

	n1 = ft_lstnew("saad");
	n2 = ft_lstnew("hbi");
	n3 = ft_lstnew("smart");
	n4 = ft_lstnew("rochdi");
	// ft_lstadd_front(&n1, n2);
	ft_lstadd_end(&n1, n2);
	ft_lstadd_end(&n1, n3);
	ft_lstadd_to_pos(&n1, n4, 1);
	current = n4;
	while (current)
	{
		printf("%s\n", current->content);
		current = current->next;
	}
	printf("---------\n");
	current = n4;
	rra_operation(&current);
	while (current)
	{
		printf("%s\n", current->content);
		current = current->next;
	}
	return (0);
}
