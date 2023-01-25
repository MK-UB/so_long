/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:45:35 by melayoub          #+#    #+#             */
/*   Updated: 2023/01/25 01:20:28 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "so_long.h"

// static int ft_check_extension(char *path)
// {
// 	int i;
    
//     i = 0;
//     while (path[i])
//     {
//         if (path[i] == '.' && path[i + 1] == 'b' && path[i + 2] == 'e' && path[i + 3] == 'r' && path[i + 4] == '\0')
//             return (1);
//         i++;
//     }
//     return(0);
// }

// void	remove_newline(t_list *content, char *av)
// {
//     char	*line;
//     char	*all_lines;
// 	int		fd;
//     int i ;
//     int j = 0;

//     i = ft_run_and_alloc(av);
//     printf("%d", i);
//     content->map = (char **)malloc(sizeof(char *) * i + 1);
//     fd = open(av, O_RDONLY);
//     while (i > j)
//     {
// 		content->map[j] = get_next_line(fd);
// 		j++;
//     }
//     content->map[j] = 0;
//     // str[j] = '\0';
// }

// int	ft_run_and_alloc(char *str)
// {
// 	int fd;
//     char *s;
// 	int i;
//     i = 0;
//     fd = open(str, O_RDONLY);
//     s = get_next_line(fd);
//     while(s)
//     {
//         free(s);
//         s = get_next_line(fd);
//         i++;
//     }
//     printf("here\n");
//     printf("%s\n",s);
//     close (fd);
//     return(i);
// }
// void	ft_parssing(t_list *content)
// {
// 	unisized_map(content);
// 	rectangular_map(content);
// 	check_horizental(content->map);
// 	check_vertical(content->map);
// 	check_components(content->map);
// }

//
// void    struct_init(t_list *content)
// {
//     content->pos = 1;

// }

void	remove_newline(t_list *content, char *av)
{
    char	*line;
    char	*all_lines;
	int		fd;
    fd = open(av, O_RDONLY);
	all_lines = get_next_line(fd);
    while(1)
    {
		line = get_next_line(fd);
		if(!line)
			break;
		all_lines = ft_strjoin(all_lines , line);
    }
    content->map = ft_split(all_lines, '\n');
    // str[j] = '\0';
}

int	map_size(char **str)
{
	int i;
    i = 0;
    while(str[i])
    {
        i++;
    }
    return(i);
}

void setup_imgs(t_list *content)
{
    int y;
    int width = ft_strlen(content->map[0]) * 64;
    int height = map_size(content->map) * 64;
    content->mlx_ptr = mlx_init();
    content->win_ptr = mlx_new_window(content->mlx_ptr, width, height, "GAME");
    content->wall = mlx_xpm_file_to_image(content->mlx_ptr, "./wall.xpm", &y, &y);
    content->water = mlx_xpm_file_to_image(content->mlx_ptr, "./water.xpm", &y, &y);
    content->bobright = mlx_xpm_file_to_image(content->mlx_ptr, "./bobright.xpm", &y, &y);
    content->bobleft = mlx_xpm_file_to_image(content->mlx_ptr, "./bobleft.xpm", &y, &y);
    content->jellyfish = mlx_xpm_file_to_image(content->mlx_ptr, "./jellyfish.xpm", &y, &y);
    content->home = mlx_xpm_file_to_image(content->mlx_ptr, "./home.xpm", &y, &y);
	content->safe = mlx_xpm_file_to_image(content->mlx_ptr, "./safe.xpm", &y, &y);
}

int	ft_still(char x, t_list *content)
{
	int i;
	int r;
    int c;
    c = 0;
    r = 0;
	i = 0;
    while(content->map[r])
    {
        while(content->map[r][c])
        {
            if(content->map[r][c] == x)
            {
				i++;
            }
            c++;
        }
        c=0;
        r++;
	}
	return(i);
}
void    make_map(t_list *content)
{
    int k = 0;
    int m = 0;

 while(content->map[k])
     {
        printf("%s\n", content->map[k]);
        m = 0;
         while (content->map[k][m])
        {
           // printf("m : %d k : %d\n", m, k);
            
			mlx_put_image_to_window(content->mlx_ptr, content->win_ptr, content->water, m * 64, k * 64);
            if(content->map[k][m] == '1')
                mlx_put_image_to_window(content->mlx_ptr, content->win_ptr, content->wall, m * 64, k * 64);
            if(content->map[k][m] == 'P')
            {
             if (content->pos == -1)
                    mlx_put_image_to_window(content->mlx_ptr, content->win_ptr, content->bobright, m * 64, k * 64);
             if (content->pos == 1)
                    mlx_put_image_to_window(content->mlx_ptr, content->win_ptr, content->bobleft, m * 64, k * 64);

            }
            if(content->map[k][m] == 'C')
                mlx_put_image_to_window(content->mlx_ptr, content->win_ptr, content->jellyfish, m * 64, k * 64);
            else if(content->map[k][m] == 'E')
                {
					mlx_put_image_to_window(content->mlx_ptr, content->win_ptr, content->home, m * 64, k * 64);
					if(ft_still('C', content) == 0)
					{
						mlx_put_image_to_window(content->mlx_ptr, content->win_ptr, content->water, m * 64, k * 64);
						mlx_put_image_to_window(content->mlx_ptr, content->win_ptr, content->safe, m * 64, k * 64);
					}				
				}
			m++;
        }
        k++;
     }
}
void player_pos(t_list *content)
{
    int r;
    int c;
    c = 0;
    r = 0;
    while(content->map[r])
    {
        while(content->map[r][c])
        {
            if(content->map[r][c] == 'P')
            {
                content->row = r;
                content->column = c;
                return ;
            }
            c++;
        }
        c=0;
        r++;
    }
}



// void	safe_home(char x, t_list *content)
// {
// 	if (ft_still('C', content) == 0)
		
// }

void    swap(char *a, char *b, t_list  *content)
{
	char c;
	
	if (*b == 'C')
		*b = '0';
	if (*b == 'E' && ft_still('C', content) == 0)
		{
			*a = '0';
			exit(0);
		}
	else if (*b == 'E' && ft_still('C', content) > 0)
	{
		return ;
	}
	c = *a;
	*a = *b;
	*b = c;                    
}

int key_move(int key, t_list *content)
{
    int m = 1;
    int k = 1;

    player_pos(content);

    if(key == 0 && content->map[content->row][content->column - 1] != '1')
        //move left
        {
            content->pos = 1;
            swap(&content->map[content->row][content->column],
            &content->map[content->row][content->column - 1], content);
            mlx_put_image_to_window(content->mlx_ptr, content->win_ptr, content->bobleft, m * 64, k * 64);
        }
    if(key == 1 && content->map[content->row + 1][content->column] != '1')
        //move down
        swap(&content->map[content->row][content->column],
         &content->map[content->row + 1][content->column], content);
    if(key == 2 && content->map[content->row][content->column + 1] != '1')
        //move right
        {
            content->pos = -1;
            swap(&content->map[content->row][content->column],
            &content->map[content->row][content->column +1], content);
            mlx_put_image_to_window(content->mlx_ptr, content->win_ptr, content->bobright, m * 64, k * 64);
        }
    if(key == 13 && content->map[content->row - 1][content->column] != '1')
        //move up
    {
        swap(&content->map[content->row][content->column], 
        &content->map[content->row - 1][content->column], content);
    }
    make_map(content);
    // printf("%d\n",key);
return(0);
}

int main(int ac, char **av)
{
    t_list content;

        // struct_init(&content);
        content.pos = 1;
        remove_newline(&content, av[1]);
        setup_imgs(&content);
        make_map(&content);
        mlx_key_hook(content.win_ptr, key_move, &content);
 
     mlx_loop(content.mlx_ptr);

}