/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:30:09 by fdagbert          #+#    #+#             */
/*   Updated: 2018/01/25 23:46:50 by stin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_error(int code)
{
	if (code == 0)
		ft_putstr("usage: ./fillit [source_file]\n");
	else if (code == 1)
		ft_putstr("error\n");
	return (1);
}

static void		ft_cleanlist(t_tetri *first)
{
	t_tetri		*current;

	current = first;
	while (current != NULL)
	{	
		free(current->p[0]);
		free(current->p[1]);
		free(current->p[2]);
		free(current->p[3]);
		first = current->next;
		free(current);
		current = first;
	}
}

static int		ft_readfile(char *file)
{
	int			fd;
	int			ret;
	int			end;
	char		buff[D_BUFFSIZE];

	fd = 0;
	ret = 0;
	end = 0;
	ft_bzero(buff, D_BUFFSIZE);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (1);
	else
	{
		while ((ret = read(fd, buff, D_BUFFSIZE)))
		{
			if (ret < 0)
				return (1);
			else if ((end = ft_checktetri(buff)) > 0)
				return (1);
			ft_bzero(buff, D_BUFFSIZE);
		}
		if (!end || (close(fd) < 0))
			return (1);
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_tetri		*tetrilist;

	if (argc == 2)
	{
		if (ft_readfile(argv[1]))
			return (ft_error(1));
		if (!(tetrilist = ft_newlist(argv[1])))
			return (ft_error(1));
		if (ft_resolve(tetrilist) != 0)
			return (ft_error(1));
		ft_cleanlist(tetrilist);
	}
	else
		return (ft_error(0));
	return (0);
}
