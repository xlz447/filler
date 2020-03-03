/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xzhu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 21:13:04 by xzhu              #+#    #+#             */
/*   Updated: 2020/02/28 21:13:06 by xzhu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_filler(t_f *f)
{
	char	*line;
	char	**tmp;

	get_next_line(0, &line);
	tmp = ft_strsplit(line, ' ');
	f->player = tmp[2][1] - '0';
	f->symbol = f->player == 1 ? 'O' : 'X';
	free(line);
	ft_free_2d((void**)tmp);
}

void	read_piece(t_f *f, char *line)
{
	char			**tmp;
	unsigned int	i;

	tmp = ft_strsplit(line, ' ');
	f->piece_h = ft_atoi(tmp[1]);
	f->piece_w = ft_atoi(tmp[2]);
	free(line);
	ft_free_2d((void**)tmp);
	f->piece = ft_memalloc(sizeof(char*) * (f->piece_h + 1));
	f->piece[f->piece_h] = NULL;
	i = -1;
	while (++i < f->piece_h)
	{
		get_next_line(0, &line);
		f->piece[i] = ft_strdup(line);
		free(line);
	}
	ft_printf("%d %d\n\n", f->piece_h, f->piece_w);
}

void	read_map(t_f *f, char *line)
{
	char			**tmp;
	unsigned int	i;

	tmp = ft_strsplit(line, ' ');
	f->map_h = ft_atoi(tmp[1]);
	f->map_w = ft_atoi(tmp[2]);
	free(line);
	ft_free_2d((void**)tmp);
	get_next_line(0, &line);
	free(line);
	f->map = ft_memalloc(sizeof(char*) * (f->map_h + 1));
	f->map[f->map_h] = NULL;
	i = -1;
	while (++i < f->map_h)
	{
		get_next_line(0, &line);
		tmp = ft_strsplit(line, ' ');
		f->map[i] = ft_strdup(tmp[1]);
		free(line);
		ft_free_2d((void**)tmp);
	}
}

int		main(void)
{
	t_f		f;
	char	*line;

	init_filler(&f);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "Plateau"))
			read_map(&f, line);
		else if (ft_strstr(line, "Piece"))
			read_piece(&f, line);
		else
			continue ;
	}
	return (0);
}
