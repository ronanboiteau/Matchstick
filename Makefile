NAME	 = matchstick

IDIR	 = include/

LIB	 = libmy.a
LNAME	 = my
LDIR	 = lib/my
IDIR_MY	 = lib/my/include/

CC	 = gcc
CFLAGS	+= -I $(IDIR) -I $(IDIR_MY)
CFLAGS	+= -Wall -Wextra
CFLAGS	+= -Wpedantic -Wno-long-long
CFLAGS	+= -Werror

AI_DIR		= ai/
AI_FILES	= computer.c		\
		  dumb.c		\
		  easy.c		\
		  hard1.c		\
		  hard2.c		\
		  marienbad1.c		\
		  marienbad2.c		\
		  medium1.c		\
		  medium2.c		\
		  random.c
AI		= $(addprefix $(AI_DIR), $(AI_FILES))

BOARD_DIR	= board/
BOARD_FILES	= change.c	\
		  free.c	\
		  print.c
BOARD		= $(addprefix $(BOARD_DIR), $(BOARD_FILES))

SRCS_DIR	= src/
SRCS_FILES	= chk.c			\
		  main.c		\
		  options.c		\
		  player.c		\
		  $(AI)			\
		  $(BOARD)
SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS	= $(SRCS:.c=.o)

RM	= rm -f


all: $(LIB) $(NAME)

$(LIB):
	make -C $(LDIR)

$(NAME): $(OBJS)
	$(CC) -L $(LDIR) -l $(LNAME) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	make -C $(LDIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LDIR) fclean

re: fclean all

.PHONY: all clean fclean re
