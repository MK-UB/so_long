#include "so_long.h"

void	ft_close(char **str)
{
	free(str);
	printf("map error");
	exit(1);
}


void    unisized_map(t_list *content)
{
	int j;
	
	while(content->map[j])
	{
		if (ft_strlen(content->map[j]) != ft_strlen(content->map[0]))
			ft_close(content->map);
		j++;
	}
}

void	rectangular_map(t_list *content)
{
	int l;
	int j;
	char *tab;
	int fd;

	fd = open(content->path, O_RDONLY);
	l = ft_strlen(content->path[0]) - 1;
	j = 1;
	tab = get_next_line(fd);
	while (tab)
		{
			free(tab);
			tab = get_next_line(fd);
			j++;
		}
	if (j == l)
		ft_close(content->path);
}