#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	long size;
	char *buf;
	char *ptr;

	size = pathconf(".", _PC_PATH_MAX);


	if ((buf = (char *)malloc((size_t)size)) != NULL)
		ptr = getcwd(buf, (size_t)size);
	printf("pathname: %s\n", ptr);
	return (0);
}
