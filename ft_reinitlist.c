/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reinitlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:52:57 by fdagbert          #+#    #+#             */
/*   Updated: 2018/01/26 00:30:04 by stin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_reinitpoint(t_tetri *current)
{
	int xdiff;
	int ydiff;
	int i;

	xdiff = current->p[0]->x;
	ydiff = current->p[0]->y;
	i = 1;
	while (i < 4)
	{
		if (current->p[i]->x < xdiff)
			xdiff = current->p[i]->x;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		current->p[i]->x -= xdiff;
		current->p[i]->y -= ydiff;
		i++;
	}
}

int				ft_reinitlist(t_tetri *first, char all)
{
	t_tetri		*current;
	int			nb;

	current = first;
	nb = 0;
	if (all == 1)
	{
		while (current)
		{
			ft_reinitpoint(current);
			nb = current->id;
			current = current->next;
		}
	}
	else
		ft_reinitpoint(current);
	return (nb);
}
