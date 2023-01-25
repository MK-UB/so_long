#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h> 
#include <unistd.h>

typedef struct	s_list
{
    void *mlx_ptr;
    void *win_ptr;
    void *wall;
	void *water;
    void *bobright;
    void *bobleft;
    void *jellyfish;
    void *home;
    void *safe;
    int column;
    int row;
    int c;
    int pos;
    char **map;
    char *path;
    
}				t_list;

void	ft_close(char **str);
void	unisized_map(t_list *content);
void	rectangular_map(t_list *content);
void	check_vertical(char **str);
void	check_horizental(char **str);
void	check_components(char**str);
void	remove_newline(t_list *content,char *av);
void	ft_parssing(t_list *content);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
char	*ft_strjoin(char *str1, char *str2);
int		found_newline(char *stash);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *src);
char	*get_linee(char *src);
char	*ft_substr(char *s, unsigned int start, size_t	len);
char	*update_it(char *s);
int	ft_run_and_alloc(char *str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

#endif