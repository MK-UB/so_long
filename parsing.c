
#include "so_long.h"

static int map_size(char **map)
{
	int j = 0;
	while(map[j])
		j++;
	return (j);
}

void    check_horizental(char **str)
{
    int j;
    int i;

	j = map_size(str) - 1;
    i = 0;
    while (str[i])
    {
        if (str[0][i] != '1' || str[j][i] != '1')
			ft_close(str);
        i++;
    }
}

void    check_vertical(char **str)
{
    int j;
    int i; 
	
    j = 0;
    i = ft_strlen(str[j]);
    while (str[j])
    {
        if(str[j][0] != '1' || str[j][i - 1] != '1')
			ft_close(str);
         j++;
    }
}

static int there_is(char **str, char x)
{
	int y = 0;
	int i = 0;
	int j = 0;
	while(str[j])
	{
		while(str[j][i])
		{
			if (str[j][i] == x)
				y++;
			i++;
		}
		i = 0;
		j++;
	}
	return (y);
}

void	check_components(char **str)
{


	if(there_is(str, 'P') != 1 
		|| there_is(str, 'C') < 1 
			|| there_is(str, 'E') != 1)
				ft_close(str);
}
