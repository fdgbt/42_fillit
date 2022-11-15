/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:52:57 by fdagbert          #+#    #+#             */
/*   Updated: 2018/01/31 22:48:31 by stin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_check(t_tetri *current, char **grid, int size, t_point pos)
{
	int 		i;

	i = 0;
	if (pos.x == -1)
		return (1);
	while (i < 4)
	{
		if (current->p[i]->x + pos.x >= size)
			return (1);
		else if (current->p[i]->y + pos.y >= size)
			return (2);
		else if (grid[current->p[i]->x + pos.x][current->p[i]->y + pos.y] != 0)
			return (3);
		else
			i++;
	}
	return (0);
}

static void		ft_put(t_tetri *current, char **grid, t_point pos)
{
	int 		i;

	i = 0;
	while (i < 4)
	{
		current->p[i]->x += pos.x;
		current->p[i]->y += pos.y;
		grid[current->p[i]->x][current->p[i]->y] = current->id + 64;
		i++;
	}
}

static t_point		ft_nextcase(int size, t_point pos, int check)
{
	if (pos.x == -1 || check == 2)
	{
		pos.x = -1;
		return (pos);
	}
	if ((pos.x + 1 < size) && check != 1)
		pos.x++;
	else if (pos.y + 1 < size)
	{
		pos.x = 0;
		pos.y++;
	}
	else
		pos.x = -1;
	return (pos);
}

static t_point		ft_nextpos(t_tetri *last, char **grid, int size, t_point pos)
{
	int 		i;
	int 		offset;

	i = 0;
	offset = 0;
	while (i < 4)
	{
		grid[last->p[i]->x][last->p[i]->y] = 0;
		if (last->p[i]->x < last->p[0]->x)
		{
			if ((last->p[0]->x - last->p[i]->x) > offset)
				offset = last->p[0]->x - last->p[i]->x;
		}
		i++;
	}
	pos.x = last->p[0]->x - offset;
	pos.y = last->p[0]->y;
	pos = ft_nextcase(size, pos, 3);
	ft_reinitlist(last, 0);
	return (pos);
}

int			ft_place(t_tetri *current, char **grid, int size, t_point pos)
{
	int 		check;

	while (current != NULL)
	{
		while (pos.x != -1)
		{
			if (!(check = ft_check(current, grid, size, pos)))
			{
				ft_put(current, grid, pos);
				current = current->next;
				pos.x = 0;
				pos.y = 0;
				if (current == NULL)
					return (0);
			}
			else
				pos = ft_nextcase(size, pos, check);
		}
		if (current->last != NULL)
			pos = ft_nextpos(current->last, grid, size, pos);
		current = current->last;
	}
	return (1);
}
