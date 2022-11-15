/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 01:34:47 by fdagbert          #+#    #+#             */
/*   Updated: 2018/01/30 16:12:02 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			ft_newpoint(char *tetri, t_tetri *new)
{
	t_point			*newpt;
	int			n;
	int			i;
	int			j;

	n = 0;
	i = 0;
	j = 0;
	while (tetri[i] != '\0' && n < 4)
	{
		while (tetri[i] != '#')
		{
			i++;
			if ((i % 5) == 0)
				j++;
		}
		if (!(newpt = (t_point *)malloc(sizeof(t_point))))
			return (1);
		newpt->x = i % 5;
		newpt->y = j;
		new->p[n] = newpt;
		n++;
		i++;
	}
	return (0);
}

static t_tetri			*ft_chaintetri(t_tetri *first, t_tetri *new)
{
	t_tetri			*current;
	int			id;

	id = 1;
	if (first == NULL)
	{
		first = new;
		current = NULL;
	}
	else
	{
		id++;
		current = first;
		while (current->next != NULL)
		{
			current = current->next;
			id++;
		}
		current->next = new;
	}
	new->id = id;
	new->next = NULL;
	new->last = current;
	return (first);
}

static t_tetri			*ft_newtetri(char *tetri, t_tetri *first)
{
	t_tetri			*new;

	if (!(new = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	if ((ft_newpoint(tetri, new)))
		return (NULL);
	return (ft_chaintetri(first, new));
}

t_tetri				*ft_newlist(char *file)
{
	int			fd;
	int			ret;
	char			buff[D_BUFFSIZE];
	t_tetri			*first;

	first = NULL;
	ft_bzero(buff, D_BUFFSIZE);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	else
	{
		while ((ret = read(fd, buff, D_BUFFSIZE)))
		{
			if (ret < 0)
				return (NULL);
			buff[D_BUFFSIZE - 1] = '\0';
			first = ft_newtetri(buff, first);
			ft_bzero(buff, D_BUFFSIZE);
		}
		if (close(fd) < 0)
			return (NULL);
	}
	return (first);
}
