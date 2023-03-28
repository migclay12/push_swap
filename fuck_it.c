#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*recive;
	int		size;

	i = 0;
	size = ft_strlen(s1);
	recive = malloc(sizeof(char) * (size + 1));
	if (!recive)
		return (NULL);
	while (s1[i] != '\0')
	{
		recive[i] = s1[i];
		i++;
	}
	recive[i] = '\0';
	return (recive);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*recive;
	size_t	i;
	size_t	length;
	size_t	j;

	if (!s)
		return (0);
	length = ft_strlen(s);
	if (length < start || *s == '\0')
		return (ft_strdup(""));
	if (len > length)
		recive = malloc(sizeof(char) * (length + 1));
	else
		recive = malloc(sizeof(char) * (len + 1));
	if (!recive)
		return (0);
	i = start;
	j = 0;
	while (i < length && j < len)
	{
		recive[j++] = s[i++];
	}
	recive[j] = '\0';
	return (recive);
}

static int	count_string(const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static int	count_word(const char *s, char c, int i)
{
	int	cont;

	cont = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		cont++;
	}
	return (cont);
}

static char	**freemem(char **exit, int i)
{
	while (i >= 0)
	{
		free(exit[i]);
		i--;
	}
	free(exit);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		countstr;
	int		countwrd;
	char	**idk;
	size_t	count;

	if (!s)
		return (NULL);
	countstr = count_string(s, c);
	idk = malloc(sizeof(char *) * (countstr + 1));
	if (!idk)
		return (NULL);
	idk[countstr] = NULL;
	countwrd = 0;
	count = 0;
	while (countwrd < countstr)
	{
		while (s[count] == c)
			count++;
		idk[countwrd] = ft_substr(s, count, count_word(s, c, count));
		if (!idk[countwrd])
			freemem(idk, countwrd);
		count += count_word(s, c, count);
		countwrd++;
	}
	return (idk);
}

void get_num(char **argv)
{
	char **temp;
	char **idk;
    int i;

    i = 0;
	temp = argv;
	while (argv[i])
	{
		idk = ft_split(temp[i], ' ');
		//printf("%s\n", idk[i]);
        printf("%d", i);
        i++;
	}
	free(idk);
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