#include "get_next_line.h"

int ft_find_nl(t_list *lst)
{
    int size;
    int i;

    size = 0;
    i = 0;
    while (lst)
    {
        while (lst->buff[i] && lst->buff[i++] != '\n')
            size++;
        lst = lst->next;
    }
    return (size);
}

char    *ft_add_res(char *res, )
{
    return (res);
}

char *get_next_line(int fd)
{
    static t_list *lst = NULL;
    int         read_bytes;
    char        *res;
    char        *buff;

    if (fd == -1 || BUFFER_SIZE <= 0)
        return (0);
    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buff)
        return (0);
    while (ft_find_nl(ft_lstlast(lst)) && read_bytes)
    {
        read_bytes = read(fd, buff, 100);
        if (read_bytes < 0 || (!lst && !read_bytes))
        {
            free(buff);
            return (0);
        }
        buff[read_bytes] = '\0';
        ft_lstadd_back(&lst, ft_lstnew(buff));
    }
    res = malloc(sizeof(char) * (ft_find_nl(lst) + 1));
    if (!res)
        return (0);
    ft_add_res(res);
    return (res);
}

int main()
{
    int fd;
    char *line;
    
    fd = open("C:/Users/Florian/Desktop/test.txt", O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        printf("line = %s", line);
    }
}