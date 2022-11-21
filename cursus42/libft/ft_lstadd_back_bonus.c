/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 08:06:54 by afavre            #+#    #+#             */
/*   Updated: 2022/10/28 08:16:32 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*oldlast;

	oldlast = ft_lstlast(*lst);
	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
			oldlast->next = new;
	}
}
