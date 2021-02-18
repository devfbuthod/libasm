#include "../includes/main.h"

void strlen_test()
{
    printf("size : %zu", ft_strlen("plopiplop"));
}

void	strcmp_test(void)
{
	printf("\n\\***              strcmp               ***\\\n\n");
	
	if (strcmp("a", "z") != ft_strcmp("a", "z"))
		printf("[ko]wrong result of ft_strcmp(\"a\", \"z\")\n");
	else
		printf("[ok]\n");
	printf("strcmp res = %d & ft_strcmp res = %d\n", strcmp("a", "z"), ft_strcmp("a", "z"));
	if (strcmp("a", "") != ft_strcmp("a", ""))
		printf("[ko]wrong result of ft_strcmp(\"a\", \"\")\n");
	else
		printf("[ok]\n");
	printf("strcmp res = %d & ft_strcmp res = %d\n", strcmp("a", ""), ft_strcmp("a", ""));
	if (strcmp("Hello", "Hell") != ft_strcmp("Hello", "Hell"))
		printf("[ko]wrong result of ft_strcmp(\"Hello\", \"Hell\")\n");
	else
		printf("[ok]\n");
	printf("strcmp res = %d & ft_strcmp res = %d\n", strcmp("Hello", "Hell"), ft_strcmp("Hello", "Hell"));
	if (strcmp("", "a") != ft_strcmp("", "a"))
		printf("[ko]wrong result of ft_strcmp(\"\", \"a\")\n");
	else
		printf("[ok]\n");
	printf("strcmp res = %d & ft_strcmp res = %d\n", strcmp("", "a"), ft_strcmp("", "a"));
	if (strcmp("Hello world", "Hello word") != ft_strcmp("Hello world", "Hello word"))
		printf("[ko]wrong result of ft_strcmp(\"Hello world\", \"Hello word\")\n");
	else
		printf("[ok]\n");
	printf("strcmp res = %d & ft_strcmp res = %d\n", strcmp("Hello world", "Hello word"), ft_strcmp("Hello world", "Hello word"));
	if (strcmp("bla", "bla") != ft_strcmp("bla", "bla"))
		printf("[ko]wrong result of ft_strcmp(\"bla\", \"bla\")\n");
	else
		printf("[ok]\n");
	printf("strcmp res = %d & ft_strcmp res = %d\n", strcmp("bla", "bla"), ft_strcmp("bla", "bla"));
}

void    strcpy_test(void)
{
	char	*save;
	char    dst[13];
	char    str[] = "Hello world\n";
	char	*ret;

	save = &(dst[0]);
	printf("\n\\***              strcpy               ***\\\n\n");
	ret = ft_strcpy(dst, str);
	if ((char *)dst != str && ret == dst && save == ret && !strcmp(dst, str))
		printf("[ok]\n");
	else
		printf("[ko]wrong result with \"Hello world\\n\"\n");

	ret = ft_strcpy(dst, str + 11);
	if (dst == ret && save == ret && (char *)dst != (str + 11) && !strcmp(dst, (str + 11)))
		printf("[ok]\n");
	else
		printf("[ko]wrong result with \"\\n\"\n");
	ret = ft_strcpy(dst, str + 12);
	if (dst == ret && save == ret && (char *)dst != (str + 12) && !strcmp(dst, (str + 12)))
		printf("[ok]\n");
	else
		printf("[ko]wrong result with \"\"\n");
}

void	write_test(void)
{
	ssize_t	ret;
	int     fd = open("write_test.txt", O_CREAT | O_WRONLY | O_TRUNC, 0777);

	errno = 0;

	printf("\n\\***              write               ***\\\n\n");

	printf("test 1\n");
	dprintf(1, "Real write : |");
	ret = write(1, "", 0);
	printf("| ret : %zd errno : %d\n", ret, errno);
	dprintf(1, "Your write : |");
	ret = ft_write(1, "", 0);
	printf("| ret : %zd errno : %d", ret, errno);
	printf("\n\n");

	printf("test 2\n");
	dprintf(1, "Real write : |");
	ret = write(1, "test 2", 6);
	printf("| ret : %zd errno : %d\n", ret, errno);
	dprintf(1, "Your write : |");
	ret = ft_write(1, "test 2", 6);
	printf("| ret : %zd errno : %d", ret, errno);
	printf("\n\n");

	printf("test 3 (check \"write_test.txt\", there should only be \"Bonjour\\n\" twice)\n");
	dprintf(1, "Real write : |");
	ret = write(fd, "Bonjour\n", 8);
	printf("| ret : %zd errno : %d\n", ret, errno);
	dprintf(1, "Your write : |");
	ret = ft_write(fd, "Bonjour\n", 8);
	printf("| ret : %zd errno : %d", ret, errno);
	printf("\n\n");

	printf("test 4\n");
	dprintf(1, "Real write : |");
	ret = write(-1, "Bonjour\n", 8);
	printf("| ret : %zd errno : %d\n", ret, errno);
	dprintf(1, "Your write : |");
	ret = ft_write(-1, "Bonjour\n", 8);
	printf("| ret : %zd errno : %d", ret, errno);
	printf("\n\n");

	close(fd);
}

void	read_test(void)
{
	int	fd;
	int	ret;
	int	error;
	int	ret2;
	char	buff1[1000];
	char	buff2[1000];

	printf("\n\\***              read               ***\\\n\n");
	fd = open("Makefile", O_RDONLY);
	ret = read(fd, buff1, 999);
	ret >= 0 ? buff1[ret] = 0 : 0;
	error = errno;
	close(fd);
	fd = open("Makefile", O_RDONLY);
	ret2 = ft_read(fd, buff2, 999);
	ret2 >= 0 ? buff2[ret2] = 0 : 0;
	close(fd);
	if (ret != ret2)
		printf("Reading Makefile with a len of 999\n[ko]wrong ret value\n");
	else if (error != errno)
		printf("Reading Makefile with a len of 999\n[ko]wrong value in errno\n");
	else if (strcmp(buff1, buff2))
		printf("Reading Makefile with a len of 999\n[ko]reading wrong\n");
	else
		printf("[ok]\n");

	fd = open("empty.txt", O_RDONLY);
	ret = read(fd, buff1, 100);
	ret >= 0 ? buff1[ret] = 0 : 0;
	error = errno;
	close(fd);
	fd = open("empty.txt", O_RDONLY);
	ret2 = ft_read(fd, buff2, 100);
	ret2 >= 0 ? buff2[ret2] = 0 : 0;
	close(fd);
	if (ret != ret2)
		printf("Reading Makefile with a len of 999\n[ko]wrong ret value\nexpected : %d, yours : %d\n", ret, ret2);
	else if (error != errno)
		printf("Reading Makefile with a len of 999\n[ko]wrong value in errno\n");
	else if (strcmp(buff1, buff2))
		printf("Reading Makefile with a len of 999\n[ko]reading wrong\n");
	else
		printf("[ok]\n");

	fd = -1;
	ret = read(fd, buff1, 100);
	ret >= 0 ? buff1[ret] = 0 : 0;
	error = errno;
	fd = -1;
	ret2 = ft_read(fd, buff2, 100);
	ret2 >= 0 ? buff2[ret2] = 0 : 0;
	if (ret != ret2)
		printf("Reading Makefile with a len of 999\n[ko]wrong ret value\n");
	else if (error != errno)
		printf("Reading Makefile with a len of 999\n[ko]wrong value in errno\n");
	else if (ret >= 0 && strcmp(buff1, buff2))
		printf("Reading Makefile with a len of 999\n[ko]reading wrong\n");
	else
		printf("[ok]\n");
}

void	strdup_test(void)
{
	char	*dup;
	char	str[] = "Hello world\n";

	printf("\n\\***              strdup               ***\\\n\n");
	dup = ft_strdup(str);
	if (dup != str && !strcmp(dup, str))
		printf("[ok]\n");
	else
		printf("[ko]wrong result with \"Hello world\\n\"\n");
	free(dup);
	dup = ft_strdup(str + 11);
	if (dup != (str + 11) && !strcmp(dup, (str + 11)))
		printf("[ok]\n");
	else
		printf("[ko]wrong result with \"\\n\"\n");
	free(dup);
	dup = ft_strdup(str + 12);
	if (dup != (str + 12) && !strcmp(dup, (str + 12)))
		printf("[ok]\n");
	else
		printf("[ko]wrong result with \"\"\n");
	free(dup);
}

int main()
{
    strlen_test();

    strcpy_test();

	strcmp_test();

	write_test();

	read_test();

	strdup_test();

    return (0);
}