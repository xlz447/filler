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

static void average_piece_size(t_f *f)
{
	t_p		cur;
	t_p		min;
	t_p		max;

	min.x = 2147483647;
	min.y = 2147483647;
	max.x = -2147483648;
	max.y = -2147483648;
	cur.y = -1;
	while (++cur.y < f->piece_h)
	{
		cur.x = -1;
		while (++cur.x < f->piece_w)
		{
			if (f->piece[cur.y][cur.x] == '*')
			{
				set_min_max(&cur, &min, &max);
			}
		}
	}
	f->aps_sum.x += (max.x - min.x + 1);
	f->aps_sum.y += (max.y - min.y + 1);
	f->piece_count++;
}

static void	read_piece(t_f *f, char *line)
{
	char	**tmp;
	int		i;

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
	average_piece_size(f);
}

static void	read_map(t_f *f, char *line)
{
	char	**tmp;
	int		i;

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

static void	init_filler(t_f *f)
{
	char	*line;
	char	**tmp;

	get_next_line(0, &line);
	tmp = ft_strsplit(line, ' ');
	f->player = tmp[2][1] - '0';
	f->symbol = f->player == 1 ? 'O' : 'X';
	free(line);
	ft_free_2d((void**)tmp);
	f->fit_count = 0;
	f->piece_count = 0;
	f->aps_sum.x = 0;
	f->aps_sum.y = 0;
}

int			main(void)
{
	t_f		f;
	char	*line;

	init_filler(&f);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "Plateau"))
			read_map(&f, line);
		else if (ft_strstr(line, "Piece"))
		{
			read_piece(&f, line);
			solve(&f);
		}
		else
			continue ;
	}
	return (0);
}
