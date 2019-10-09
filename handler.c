/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 20:53:14 by dgreat            #+#    #+#             */
/*   Updated: 2019/10/08 02:11:42 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

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

void		xyz_new(t_glist dot, char *str, t_glist **map, t_glist data)
{
	const int i = dot.y;
	const int j = dot.x;

	if (!((int)data.x % 2))
		map[i][j].x = (float)(j - data.x / 2);
	else
		map[i][j].x = (float)(j) - (float)(data.x / 2);
	if (!((int)data.y % 2))
		map[i][j].y = (float)(i - data.y / 2);
	else
		map[i][j].y = (float)(i) - (float)(data.y / 2);
	map[i][j].z = ft_atoi(str);
	//vardot("KARMA", map[i][j]);
}

t_glist		**allocator_new(t_glist data)// TODO: remove t_map arch
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



t_glist		**filler_new(t_glist data, t_glist **map, char **stock)//todo new arch
{
	int		i;
	int		j;
	char	**line;
	t_glist	dot;

	i = -1;
	while (++i < data.y)
	{
		if (data.x != ft_word_counter(stock[i], ' '))
//		{
//			free_map(lines);
//			free_str(line, cols);
//			free_str(stock, lines);
			error_notice("wrong coordinates number");
//		}
		j = -1;
		line = ft_strsplit(stock[i], ' ');
		while (++j < data.x)
			xyz_new(set_dot(j, i), line[j], map, data);
	}
	return (map);
}

t_glist		**checker_new(char *buf, t_mlx *win)
{
	char	**stock;
	t_glist	**map;
	t_glist	data;

	data.y = ft_word_counter(buf, '\n');
	stock = ft_strsplit(buf, '\n');
	data.x = ft_word_counter(stock[0], ' ');
	map = allocator_new(data);
	win->map = data;
	vardot("test", win->map);
	map = filler_new(data, map, stock);
	return (map);
}

void		reader(int fd)//todo  - получение win.map
{
	char		buf[BUFF_SIZE];
	char		**line;
	t_glist		**map;
	t_mlx		win;

	read(fd, buf, BUFF_SIZE);
	map = checker_new(buf, &win);
	win = window(WIDE, LENGTH);
	win.opt.dt_mode = 1;
	win.opt.axis = 0;
//	vardot("win.map", win.map);
	win.map = set_dot(19, 11);
	vardot("", map[0][0]);
	ft_foreach(win, map, vardot);

	error_notice("fuck debug");
	draw_map(win, map);
	mlx_loop(win.mp);
	//error_notice("debug");

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
