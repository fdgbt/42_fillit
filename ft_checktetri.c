/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checktetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 02:29:47 by fdagbert          #+#    #+#             */
/*   Updated: 2018/02/06 14:41:06 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_countsharp(char *tetri)
{
	int index;
	int nblock;

	index = 0;
	nblock = 0;
	while (index < D_BUFFSIZE && tetri[index] != 0)
	{
		if (tetri[index++] == '#')
			nblock++;
	}
	if (nblock != 4)
		return (1);
	else
		return (0);
}

static int		ft_checkformat(char *tetri)
{
	int index;
	int endline;
	int line;

	index = 0;
	line = 1;
	while (line <= 4)
	{
		endline = 0;
		while ((tetri[index] == '#' || tetri[index] == '.') && endline++ < 5)
			index++;
		if (endline != 4)
			return (1);
		if (tetri[index++] != '\n')
			return (1);
		line++;
	}
	if (tetri[index] != '\n')
	{
		if (tetri[index] != 0)
			return (1);
		else
			return (-1);
	}
	return (0);
}

static int		ft_checkconnect(char *line, int index)
{
	int connect;

	connect = 0;
	while (line[index] != '\n' && line[index] != '\0' && line[index] != '#')
		index++;
	while (line[index] == '#')
	{
		if ((index + 1 < D_BUFFSIZE) && (line[index + 1] == '#'))
			connect++;
		if ((index - 1 >= 0) && (line[index - 1] == '#'))
			connect++;
		if ((index + 5 < D_BUFFSIZE) && (line[index + 5] == '#'))
			connect++;
		if ((index - 5 >= 0) && (line[index - 5] == '#'))
			connect++;
		index++;
	}
	return (connect);
}

static int		ft_checkchain(char *tetri)
{
	int index;
	int connect;
	int nblock;
	int core;

	index = 0;
	nblock = 0;
	core = 0;
	while (index < 20)
	{
		if ((connect = ft_checkconnect(tetri, index)) > 1)
			core = 1;
		if (connect == 1 || connect == 2)
			nblock += 1;
		else if (connect == 3 || connect == 4)
			nblock += 2;
		else if (connect == 5)
			nblock += 3;
		else if (connect == 6)
			nblock += 4;
		index += 5;
	}
	if (nblock == 4 && core)
		return (0);
	return (1);
}

int				ft_checktetri(char *tetri)
{
	int end;

	if (ft_countsharp(tetri) || ft_checkchain(tetri))
		return (1);
	if (!(end = ft_checkformat(tetri)))
		return (0);
	else
		return (end);
}
