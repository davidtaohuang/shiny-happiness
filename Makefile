# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhuang <dhuang@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/05 21:53:35 by dhuang            #+#    #+#              #
#    Updated: 2017/01/11 16:20:02 by dhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re testing

vpath %.h includes

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I includes/

SRCFILES = ft_printf.c formatcheck.c freeft.c datasetup.c parseswitch.c \
			typeswitch.c formatnum.c ft_dtoa.c insertformat.c \
			padcs.c padnum.c padswitch.c parsedbl.c parsenum.c parsestr.c \
			parseunum.c parsezjt.c formatdbl.c \

SRCDIR := srcs

SRC:= $(addprefix $(SRCDIR)/, SRCFILES))

LIB = libft/libft.a

OBJDIR := obj

OBJS := $(addprefix $(OBJDIR)/, $(patsubst %.c,%.o,$(SRCFILES)))

NAME = myprintf

all: $(NAME)

$(LIB):
		make -C libft/

$(OBJS): ft_printf.h $(SRCS) | $(OBJDIR)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
		@$(CC) $(CFLAGS) -c $< -o $@
		@echo "Done creating $@..."

$(OBJDIR):
		@echo "Creating subdirectory for object files..."
		@mkdir $(OBJDIR)

$(NAME): ft_printf.h $(OBJS) $(LIB) main.c
		@echo "Creating $(NAME)..."
		@$(CC) $(CFLAGS) $(GFLAGS) $(OBJS) main.c -o $@ -L libft/ -lft
		@echo "All done!"

testing: ft_printf.h
		$(CC) $(CFLAGS) ft_printf.c formatcheck.c main.c

clean:
		@echo "Deleting printf object files and subdirectory..."
		@rm -f $(OBJS)
		@rm -rf $(OBJDIR)
		make clean -C libft/

fclean: clean
		@echo "Deleting $(NAME)..."
		@rm -f $(NAME)
		make fclean -C libft/

re: fclean all
