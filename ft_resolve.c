/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:52:57 by fdagbert          #+#    #+#             */
/*   Updated: 2018/01/26 00:58:58 by stin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**ft_newgrid(int size)
{
	char		**grid;
	int		i;

	if (!(grid = (char **)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	ft_bzero(grid, size + 1);
	i = 0;
	while (i < size)
	{
		if (!(grid[i] = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		ft_bzero(grid[i], size + 1);
		i++;
	}
	grid[i] = NULL;
	return (grid);
}

static void		ft_delgrid(char **grid)
{
	int 		i;

	i = 0;
	while (grid[i] != NULL)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	grid = NULL;
}

static void		ft_printgrid(char **grid, int size)
{
	int 		x;
	int 		y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (grid[x][y] >= 'A' && grid[x][y] <= 'Z')
				ft_putchar(grid[x][y]);
			else
				ft_putchar('.');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
	ft_delgrid(grid);
}

int				ft_resolve(t_tetri *first)
{
	int			size;
	int			nb;
	char			**grid;
	t_point 		initgrid;

	initgrid.x = 0;
	initgrid.y = 0;
	if (first == NULL)
		return (1);
	if ((nb = ft_reinitlist(first, 1)) > 26)
		return (1);
	size = 2;
	while (size * size < nb * 4)
		size++;
	if (!(grid = ft_newgrid(size)))
		return (-1);
	while ((ft_place(first, grid, size, initgrid)) != 0)
	{
		ft_delgrid(grid);
		ft_reinitlist(first, 1);
		grid = ft_newgrid(++size);
	}
	ft_printgrid(grid, size);
	return (0);
}
