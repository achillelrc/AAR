##
## Makefile for inv in /home/binary/All/Rush1/form/CPE_2016_b2rush1/
##
## Made by Laroche Achille
## Login   <binary>
##
## Started on  Sun Mar  5 22:58:05 2017 Laroche Achille
## Last update Sun Jul 30 20:26:49 2017 Laroche Achille
##

RM	=	rm -f

CFLAGS	=	-Iinclude

SRCS1	=	archive/srcs/archiver.c \
		archive/srcs/handler.c \
		archive/srcs/base1.c \
		archive/srcs/base2.c

OBJS1	=	$(SRCS1:.c=.o)

SRCS2	=	unarchive/srcs/unarchiver.c \
		unarchive/srcs/lilfunc.c \
		unarchive/srcs/base1.c \
		unarchive/srcs/base2.c

OBJS2	=	$(SRCS2:.c=.o)

all:		arch unarch		

arch:		$(OBJS1)
		$(CC) -o fuck $(OBJS1)

unarch:		$(OBJS2)
		$(CC) -o unfuck $(OBJS2)

clean:
		$(RM) $(OBJS1) $(OBJS2) $**~

fclean:		clean
		$(RM) fuck unfuck

re:		clean fclean all

.PHONY:		all clean fclean re
