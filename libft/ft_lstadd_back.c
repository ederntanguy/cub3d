/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etanguy <etanguy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:48:28 by etanguy           #+#    #+#             */
/*   Updated: 2022/11/13 14:03:22 by etanguy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	tmp = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
/*
#include <stdio.h>
int main(void)
{
	t_list *elem1;
	t_list *elem2;
	t_list *elem3;
	t_list *elem4;

	elem1 = NULL;
	elem2 = ft_lstnew("layaa");
	elem3 = ft_lstnew("layaaa");
	elem4 = ft_lstnew("layaaaa");
	ft_lstadd_back(&elem1, elem4);
	while (elem1)
	{
		printf("%s\n", (char *)elem1->content);
		elem1 = elem1->next;
	}
	return 0;
}
*/
