
// #include "so_long.h"

// //  static int ft_check_extension(char *path)
// // {
// //     int i;
// // 	char *str;

// // 	i = 0;
// // 	str = ft_substr(path, path[ft_strlen(path)-4], 4);
// // 	if (str == ".ber")
// // 		return (1);
// // 	return(0);
// // }


// // int	ft_run_and_alloc(char	**str)
// // {
// // 	int fd;
// // 	char *tab;
// // 	int i;

// //     i = 0;
// //     fd = open("map.ber", O_RDONLY);
// // 	tab = get_next_line(fd);
// //     while(tab)
// //     {
// //         free(tab);
// //         tab = get_next_line(fd);
// //         i++;
// //     }
// //     str = (char **)malloc (sizeof(char) * i + 1);
// //     close (fd);
// // return(i);
// // }

// void	remove_newline(t_list *content, char **av)
// {
//     char	*line;
//     char	*all_lines;
// 	int		fd;
//     fd = open(av[1], O_RDONLY);
// 	all_lines = get_next_line(fd);
//     while (1)
//     {
// 		line = get_next_line(fd);
// 		if(!line)
// 			break;
// 		all_lines = ft_strjoin(all_lines , line);
//     }
//     content->map = ft_split(all_lines, '\n');
//     str[j] = '\0';
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
//         s = get_next_line(fd);
//         i++;
//     }
//     //  printf("%s\n",tab);
//     close (fd);
//     return(i);
// }
// #include <mlx.h>

// int main(int ac, char **av)
// {
//     void *mlx_ptr;
//     void *win_ptr;
// 	void *image1;
// 	void *image0;
//     int j = 0;
//     int i = 0;
//     int y = 0;
//     int x = 0;
//     int width = ft_run_and_alloc(av[1]);
//     printf("%d", width);
//     exit(0);
//     mlx_ptr = mlx_init();
//     win_ptr = mlx_new_window(mlx_ptr, 1200, 1200, "GAME");
//     image1 = mlx_xpm_file_to_image(mlx_ptr, "./wall.xpm", &y, &y);
//     image0 = mlx_xpm_file_to_image(mlx_ptr, "./space.xpm", &y, &y);
//     while(av[j])
//     {
//         while(av[j][i])
//         {
// 			if(av[j][i] == 1)
//             {
//             	mlx_put_image_to_window(mlx_ptr, win_ptr, image1, y, y);
//             	y += 64;
//             }
// 			else
//             {
//             	mlx_put_image_to_window(mlx_ptr, win_ptr, image0, y, y);
//                 y += 64;
//             }
//         i++;
//         }
// 	j++;
//     } 
//     mlx_loop(mlx_ptr);
// }


    



