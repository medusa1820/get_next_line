#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*result;

	fd = open("text0.txt", O_RDONLY);
	result = get_next_line(fd);
	while (result)
	{
		printf("%s", result);
		free(result);
		result = get_next_line(fd);
	}
	close(fd);
	system("leaks a.out");
	return (0);
}
