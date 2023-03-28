#include <stdio.h>
#include "../libft/libft.h"

void get_num(char **argv)
{
	char **temp;
	char **idk;

	temp = argv;
	while (!argv)
	{
		idk = ft_split(temp[1], ' ');
		printf("%s\n", idk[1]);
	}
	
	//SPLIT && ATOI && ITOA
	//ATOI CHAR TO INT
}

int main(int argc, char **argv)
{
	if (argc != 2)
		printf("\n");
	else
		get_num(argv);
	//printf("%s", argv[1]);
	return 0;
}