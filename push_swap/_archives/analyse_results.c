//#include "../headers/push_swap.h"
//
//#define LIMIT_SCORE	850
//#define FILE_NAME	"best_score.txt"
//
//int main(int argc, char **argv)
//{
//	if (argc < 1)
//		return 0;
//
//	char	*line;
//	char 	*line_2;
//	char 	**split;
//	int 	i;
//	int 	fd = open(argv[1], O_RDONLY);
//	int 	fd_2 = open(FILE_NAME, O_WRONLY | O_APPEND | O_CREAT);
//
//	printf("fd = %d  ; fd2 = %d\n", fd, fd_2);
//
//	while(get_next_line(fd, &line))
//	{
//		if (i % 1000 == 0)
//			ft_putendl_fd(line, 1);
//		i = 0;
//		line_2 = ft_strdup(line);
//		while (line_2[i])
//		{
//			if (line_2[i] == ';')
//				line_2[i] = ' ';
//			i++;
//		}
//		split = ft_split(line_2, ' ');
//		if (ft_atoi(split[split_size(split) - 1]) < 850)
//			ft_putendl_fd(line, fd_2);
//		free_split(split);
//		free(line_2);
//		free(line);
//	}
//}
