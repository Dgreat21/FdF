/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 20:53:14 by dgreat            #+#    #+#             */
/*   Updated: 2019/10/07 02:54:21 by dgreat           ###   ########.fr       */
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

t_map		mapper(int lines, int cols)
{
	t_map	data;

	data.i = lines;
	data.j = cols;
	data.x = 0;
	data.y = 0;
	(data.i % 2) ? data.y++ : (0);
	(data.j % 2) ? data.x++ : (0);
	vardump("lin", lines);
	vardump("col", cols);
	return (data);
}

void		xyz(int *coords, char *str, t_glist **map, t_map data)
{
	const int i = coords[X];
	const int j = coords[Y];

	if (!data.x)
		map[i][j].x = (float)(j - data.j / 2);
	else
		map[i][j].x = (float)(j) - (float)(data.j / 2);
	if (!data.y)
		map[i][j].y = (float)(i - data.i / 2);
	else
		map[i][j].y = (float)(i) - (float)(data.i / 2);
	map[i][j].z = ft_atoi(str);
}

//t_map		mapper_new(int lines, int cols)//TODO :
//{
//	t_glist	data;
//
//	data.i = lines;
//	data.j = cols;
//	data.x = 0;
//	data.y = 0;
//	(data.i % 2) ? data.y++ : (0);
//	(data.j % 2) ? data.x++ : (0);
//	return (data);
//}

//void		xyz_new(int *coords, char *str, t_glist **map, t_map data)
//{
//	const int i = coords[Y];
//	const int j = coords[X];
//
//	if (!data.x)
//		map[i][j].x = (float)(j - data.j / 2);
//	else
//		map[i][j].x = (float)(j) - (float)(data.j / 2);
//	if (!data.y)
//		map[i][j].y = (float)(i - data.i / 2);
//	else
//		map[i][j].y = (float)(i) - (float)(data.i / 2);
//	map[i][j].z = ft_atoi(str);
//}

t_glist		**allocator(t_map data)
{
	int		i;
	int		cl;
	t_glist	**map;

	i = 0;
	cl = 0;
	if ((map = (t_glist **)malloc((data.i) * sizeof(t_glist *))) == NULL)
		error_notice("Malloc error");
	while (i < data.i)
	{
		if ((map[i] = (t_glist *)malloc((data.j) * sizeof(t_glist))) == NULL)
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

//t_glist		**allocator(t_glist data)// TODO: remove t_map arch
//{
//	int		i;
//	int		cl;
//	t_glist	**map;
//
//	i = 0;
//	cl = 0;
//	if ((map = (t_glist **)malloc((data.mid[Y]) * sizeof(t_glist *))) == NULL)
//		error_notice("Malloc error");
//	while (i < data.mid[Y])
//	{
//		if ((map[i] = (t_glist *)malloc((data.mid[X]) * sizeof(t_glist))) == NULL)
//		{
//			while (cl < i)
//			{
//				free(map[cl]);
//				cl++;
//			}
//			free(map);
//			error_notice("Lines malloc error");
//		}
//		i++;
//	}
//	return (map);
//}

void		filler(t_map data, t_glist **map, char **stock)//todo new arch
{
	int		i;
	int		j;
	int		coords[2];
	char	**line;

	i = -1;
	while (++i < data.i)
	{
		if (data.j != ft_word_counter(stock[i], ' '))
//		{
//			free_map(lines);
//			free_str(line, cols);
//			free_str(stock, lines);
			error_notice("wrong coordinates number");
//		}
		j = -1;
		line = ft_strsplit(stock[i], ' ');
		vardump("data.j", data.j);//todo seg
		while (++j < data.j)
		{
			vardump("j", j);
			coords[0] = i;
			coords[1] = j;
			xyz(coords, line[j], map, data);
		}
		vardump("i", i);
	}
}

//void		filler_new(t_map data, t_glist **map, char **stock)//todo new arch
//{
//	int		i;
//	int		j;
//	char	**line;
//	t_glist	dot;
//
//	i = -1;
//	while (++i < data.i)
//	{
//		if (data.j != ft_word_counter(stock[i], ' '))
////		{
////			free_map(lines);
////			free_str(line, cols);
////			free_str(stock, lines);
//			error_notice("wrong coordinates number");
////		}
//		j = -1;
//		line = ft_strsplit(stock[i], ' ');
//		while (++j < data.j)
//		{
//			coords[0] = i;
//			coords[1] = j;
//			xyz(coords, line[j], *map, data);
//		}
//	}
//}

void		checker(char *buf)
{
	char	**stock;
	t_glist	**map;
	t_map	data;
	int		lines;
	int		cols;


	lines = ft_word_counter(buf, '\n');
	stock = ft_strsplit(buf, '\n');
	cols = ft_word_counter(stock[0], ' ');
	data = mapper(lines, cols);
	map = allocator(data);
	filler(data, map, stock);
}

//void		checker_new(char *buf, int lines, int cols)
//{
//	char	**stock;
//	t_glist	**map;
//	t_glist	data;
//
//	lines = ft_word_counter(buf, '\n');
//	stock = ft_strsplit(buf, '\n');
//	cols = ft_word_counter(stock[0], ' ');
//	data = mapper(lines, cols);
//	map = allocator(data);
//	filler(data, map, stock);
//}

void		reader(int fd)
{
	int			i;
	int			j;
	int			lines;
	int			cols;
	char		buf[BUFF_SIZE];
	char		**line;

	i = 0;
	j = 0;
	read(fd, buf, BUFF_SIZE);
	checker(buf);
	error_notice("debug");
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
