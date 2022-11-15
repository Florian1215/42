
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 20
#endif

char *get_next_line(int fd);

typedef struct s_list
{
	char			*buff;
	struct s_list	*next;
}				t_list;

#endif