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

int main()
{
    strlen_test();

    strcpy_test();

	strcmp_test();

    return (0);
}