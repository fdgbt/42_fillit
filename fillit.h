/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagbert <fdagbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:02:28 by fdagbert          #+#    #+#             */
/*   Updated: 2018/02/01 15:21:04 by fdagbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define D_BUFFSIZE 21
# define D_TETRIMAX 26

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef unsigned char	t_byte;

typedef struct		s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct		s_tetri
{
	int		id;
	t_point		*p[4];
	struct s_tetri	*next;
	struct s_tetri	*last;
}			t_tetri;

void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);

int			ft_checktetri(char *tetri);
t_tetri			*ft_newlist(char *file);
int			ft_place(t_tetri *current, char **grid,
					int size, t_point pos);
int			ft_reinitlist(t_tetri *first, char all);
int			ft_resolve(t_tetri *first);

#endif
