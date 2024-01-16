
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"


char *gnl(int fd)
{
    char *buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
    int i = read(fd, buff, BUFFER_SIZE);
    printf("%i\n", i);
    return(buff);
}

#include <fcntl.h>
 int	main(void)
 {
 	int		fd;
    fd = open("mytext.txt", O_RDONLY);
 	printf("%s", gnl(fd));
 	// printf("%s", gnl(fd));
 	// printf("%s", get_next_line(fd));
 	// printf("%s", get_next_line(fd));
 	// printf("%s", get_next_line(fd));
 	// printf("%s", get_next_line(fd));
 }