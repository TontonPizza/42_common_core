#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>



char	*ft_strdup(char *s);
int		ft_strlen(char *s);
char	*ft_strcpy(char *dest, char *src);
int 	ft_write(int i, char *b, int nb);
int		ft_strcmp(char *a, char *b);
int		ft_read(int fd, char *buffer, int size);

extern int *___error(int res)
{
	errno = res;
	return 0;
}

void flush_buffer(char *b, int n)
{
	int i = 0;

	while(i < n)
		b[i++]=0;
}

void	test_strlen(char *s)
{
	printf("\n\n########## TEST STRLEN ##########\n");
	printf("\n%s : %d", s, ft_strlen(s));
}

void	test_strcpy(char *src)
{
	printf("\n\n########## TEST STRCPY ##########\n");

	int i = ft_strlen(src);
	char *d = malloc(sizeof(char) * i);
	d = ft_strcpy(d, src);
	write(1, d, i);
	free(d);
}

void	test_strdup()
{
	printf("\n\n########## TEST STRDUP ##########\n");

	char *s;
	s = ft_strdup("salut les copains");
	printf("%s\n", s);
	free(s);
}

void	test_write()
{
	printf("\n\n########## TEST WRITE ##########\n");
	errno = 0;
	int r = ft_write(1, "salut\n", 6);
	printf("\n%s : errno = %d\n", strerror(errno), errno);
	printf("return value : %d\n", r);
	r =ft_write(-1, "toto", 4);
	printf("\n%s : errno = %d\n", strerror(errno), errno);
	printf("return value : %d\n", r);
	r = ft_write(1, 0, 1);
	printf("\n%s : errno = %d\n", strerror(errno), errno);
	printf("return value : %d\n", r);

}

void	test_read()
{
	printf("\n\n########## TEST READ ##########\n");
	errno = 0;
	char b[32];
	int fd = open("doc/notes.txt", O_RDONLY);
	ft_read(fd, b, 10);
	ft_write(1, b, 10);
	printf("\n%s : errno = %d\n", strerror(errno), errno);
	flush_buffer(b, 32);

	fd = open("fdp", O_RDONLY);
	ft_read(fd, b, 10);
	ft_write(1, b, 10);
	printf("\n%s : errno = %d\n", strerror(errno), errno);
	flush_buffer(b, 32);

	fd = open("doc/notes.txt", O_WRONLY);
	ft_read(fd, b, 10);
	ft_write(1, b, 10);
	printf("\n%s : errno = %d\n", strerror(errno), errno);
	flush_buffer(b, 32);
}

int main (int argc, char **argv)
{
	test_strlen("salut les copains\0");
	test_strcpy("coucou\0");
	test_strdup();
	test_read();
	test_write();
	return (0);
}

