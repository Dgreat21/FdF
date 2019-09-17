/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgreat <dgreat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 20:53:14 by dgreat            #+#    #+#             */
/*   Updated: 2019/09/18 00:09:07 by dgreat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void	free_map(int lines)
{
	int i;

	i = 0;
	while (i < lines)
	{
		free(g_map[i]);
		i++;
	}
	free(g_map);
}

void	mapper(int lines, int cols)
{
	g_data.i = lines;
	g_data.j = cols;
	g_data.x = 0;
	g_data.y = 0;
	(g_data.i % 2) ? g_data.y++ : (0);
	(g_data.j % 2) ? g_data.x++ : (0);
}

void	xyz(int i, int j, char *str)
{
	if (!g_data.x)
		g_map[i][j].x = (float)(j - g_data.j / 2);
	else
		g_map[i][j].x = float(j) - float(g_data.j / 2);
	if (!g_data.y)
		g_map[i][j].y = (float)(i - g_data.i / 2);
	else
		g_map[i][j].y = float(i) - float(g_data.i / 2);
	g_map[i][j].z = ft_atoi(str);
}

void	allocator(int lines, int cols)
{
	int	i;
	int	cl;

	i = 0;
	cl = 0;
	mapper(lines, cols);
	if ((g_map = (t_glist **)malloc((lines) * sizeof(t_glist *))) == NULL)
		error_notice("Malloc error");
	while (i < lines)
	{
		if ((g_map[i] = (t_glist *)malloc((cols) * sizeof(t_glist))) == NULL)
		{
			while (cl < i)
			{
				free(g_map[cl]);
				cl++;
			}
			free(g_map);
			error_notice("Lines malloc error");
		}
		i++;
	}
}

void	checker(char *buf)
{
	int		i;
	int		j;
	char	**stock;
	char	**line;

	i = 0;
	g_lines = ft_word_counter(buf, '\n');
	stock = ft_strsplit(buf, '\n');
	g_cols = ft_word_counter(stock[0], ' ');
	allocator(g_lines, g_cols);
	while (i < g_lines)
	{
		j = 0;
		if (cols != ft_word_counter(stock[i], ' '))
		{
			free_map(g_lines);
			free_str(line, g_cols);
			free_str(stock, g_lines);
			error_notice("wrong coordinates number");
		}
		line = ft_strsplit(stock[i], ' ');
		while (j < g_cols)
			xyz(i, j, line[j++]);
		i++;
	}
}

void	reader(int fd)
{
	int			i;
	int			j;
	char		buf[BUFF_SIZE];

	i = 0;
	j = 0;
	read(fd, buf, BUFF_SIZE);
	checker(buf);
	error_notice("debug");
}

int		main(int argc, char **argv)
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
	reader(fd);
	if (argc == 2)
		close(fd);
	return (0);
}
