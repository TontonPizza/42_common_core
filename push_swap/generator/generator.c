//#include <time.h>
//#include <unistd.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include <sys/types.h>
//
//
//int main(int argc, char **argv)
//{
//	int 	n;
//	int 	min;
//	int 	max;
//	int 	i;
//	int 	*values;
//	int 	count;
//
//	if (argc != 4)
//	{
//		printf("Erreur\n");
//		return (1);
//	}
//	n = atoi(argv[1]);
//	min = atoi(argv[2]);
//	max = atoi(argv[3]);
//	if (n > max - min || max < min || min < -10000)
//	{
//		printf("Erreur");
//		return (1);
//	}
//	i = 0;
//	values = malloc(sizeof(int) * (max - min) + 1);
//	while (i < max - min + 1)
//	{
//		values[i] = min + i;
//		i++;
//	}
//	srandom(((unsigned)time(NULL) * getpid()));
//	count = 0;
//	while (count < n)
//	{
//		i = random() % max - min;
//		if (values[i] == -50000)
//			continue;
//		printf("%d", values[i]);
//		count++;
//		values[i] = -50000;
//		if (count < n)
//			printf(" ");
//	}
//}
