#include "get_next_line.h"
#include <stdio.h>

int	main(void) {
	int	fd;
	char *line;
	int res;

	fd = open("text.txt", O_RDONLY);
	
	while ((res = get_next_line(fd, &line)))
	{
		printf("{%d} %s\n", res, line);
		free(line);
	}
	printf("{%d} %s\n", res, line);
	free(line);
	//sleep(1000);
	return 0;
}