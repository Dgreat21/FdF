/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 20:53:14 by dgreat            #+#    #+#             */
/*   Updated: 2019/10/22 22:15:16 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#define SCALE 3

void		free_map(int lines, t_glist **map)
{
	int i;

	i = 0;
	while (i < lines)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void		xyz_new(t_glist  dot, char *str, t_glist **map, t_mlx win)
{
		const int i = dot.y;
		const int j = dot.x;
		char **cache;
		if (!((int) win.map.x % 2))
			map[i][j].x = ((float) (j - win.map.x / 2)) * SCALE;
		else
			map[i][j].x = ((float) (j) - (float) (win.map.x / 2)) * SCALE;
		if (!((int) win.map.y % 2))
			map[i][j].y = ((float) (i - win.map.y / 2)) * SCALE;
		else
			map[i][j].y = ((float) (i) - (float) (win.map.y / 2)) * SCALE;
		cache = ft_strsplit(str, ',');
	map[i][j].z = ft_atoi(cache[0]) * (SCALE);
	if (cache[1])
		map[i][j].hue.mlx = ft_atoi_base(cache[1] + 2, 16);
	else
		map[i][j].hue.mlx = WHITE;
}

t_glist		**allocator_new(t_glist data)
{
	int		i;
	int		cl;
	t_glist	**map;

	i = 0;
	cl = 0;
	if ((map = (t_glist **)malloc((data.y) * sizeof(t_glist *))) == NULL)
		error_notice("Malloc error");
	while (i < data.y)
	{
		if ((map[i] = (t_glist *)malloc((data.x) * sizeof(t_glist))) == NULL)
		{
			while (cl < i)
			{
				free(map[cl]);
				cl++;
			}
			free(map);
			error_notice("Lines malloc error");
		}
		i++;
	}
	return (map);
}

t_glist		**filler_new(t_mlx win, t_glist **map, char **stock)
	{
		int		i;
		int		j;
		char	**line;
		t_glist	dot;
		int		now;
		char	data[10];

		i = -1;
		while (++i < win.map.y)
		{
			if (win.map.x != ft_word_counter(stock[i], ' '))
				error_notice("wrong coordinate number");
			j = -1;
			line = ft_strsplit(stock[i], ' ');
			while (++j < win.map.x)
//				xyz_new(set_dot(j, i), line[j], map, win);
				map[i][j] = set_xyz(j, i, line[j], win.opt.hue.mlx);
		}
		return (map);
	}

t_glist		**checker_new(char *buf, t_mlx *win)
{
	char	**stock;
	t_glist	**map;
	t_glist	data;

	win->map.y = ft_word_counter(buf, '\n');
	stock = ft_strsplit(buf, '\n');
	win->map.x = ft_word_counter(stock[0], ' ');
	map = allocator_new(win->map);
	map = filler_new(*win, map, stock);
	return (map);
}

//void		reader(int fd)
//{
//	char		buf[BUFF_SIZE];
//	char		**line;
//	t_glist		**map;
//	t_mlx		win;
//
//	read(fd, buf, BUFF_SIZE);
//	win = window(WIDE, LENGTH);
//	map = checker_new(buf, &win);
//	win.opt.dt_mode = 1;
//	win.opt.axis = 0;
//	draw_map(win, map);
//	mlx_loop(win.mp);
//}

void  reader(int fd)
{
	char  buf[BUFF_SIZE];

	t_glist  **map;
	t_mlx  win;

	read(fd, buf, BUFF_SIZE);
	win = window(WIDE, LENGTH);
	map = checker_new(buf, &win);

	draw_map(&win, map);
	mlx_put_image_to_window(win.mp, win.wp, win.img, 0, 0);
	mlx_loop(win.mp);
}

int			main(int argc, char **argv)
{
	int			fd;

	fd = 0;
	if (argc == 1)
		error_notice("no file");
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		error_notice("Too much arguments");
//	close(fd);
//	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_notice("File opening error");
	reader(fd);
//	if (argc == 2)
//		close(fd);
	return (0);
}
