/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 20:53:14 by dgreat            #+#    #+#             */
/*   Updated: 2019/09/25 09:33:39 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void		free_map(int lines, t_glist map)
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
	return (data);
}

void		xyz(int *coords, char *str, t_glist **map, t_map data)
{
	const int i = coords[0];
	const int j = coords[1];

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
void		filler(t_map data, t_glist **map, char **stock)
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
		while (++j < data.j)
		{
			coords[0] = i;
			coords[1] = j;
			xyz(coords, line[j], *map, data);
		}
	}
}
void		checker(char *buf, int lines, int cols)
{
	char	**stock;
	t_glist	map;
	t_map	data;
//	int		i;
//	int		j;
	//char	**line;

//	i = -1;
	lines = ft_word_counter(buf, '\n');
	stock = ft_strsplit(buf, '\n');
	cols = ft_word_counter(stock[0], ' ');
	data = mapper(lines, cols);
	map = allocator(data);
//	while (++i < lines)
//	{
//		if (cols != ft_word_counter(stock[i], ' '))
////		{
////			free_map(lines);
////			free_str(line, cols);
////			free_str(stock, lines);
//			error_notice("wrong coordinates number");
////		}
//		j = -1;
//		line = ft_strsplit(stock[i], ' ');
//		while (++j < cols)
//			xyz(i, j, line[j], map, data);
//	}
	filler(data, map, stock);
}

void		reader(int fd)
{
	int			i;
	int			j;
	int			lines;
	int			cols;
	char		buf[BUFF_SIZE];

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
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_notice("File opening error");
	if (argc == 2)
		close(fd);
	reader(fd);
	return (0);
}
