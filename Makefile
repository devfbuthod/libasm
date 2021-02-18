# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbuthod- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/11 11:23:46 by fbuthod-          #+#    #+#              #
#    Updated: 2021/02/11 11:23:53 by fbuthod-         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
HEADER = includes/libasm.h

CC = clang
CFLAGS = -Wall -Werror -Wextra
NASM = nasm
NASMFLAGS = -f macho64

FILES = ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s	\
		ft_read.s	\
		ft_strdup.s

OBJ = $(FILES:.s=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ)
			@echo "\nDo \"make test\" to start tests."

%.o:		%.s
			$(NASM) $(NASMFLAGS) $< -o $@

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME) a.out write_test.txt

re:			fclean all

test:		all
			$(CC) $(CFLAGS) -I/includes/main.h ./tester/*.c $(NAME)

.PHONY:		all clean fclean re bonus test bonus_test
