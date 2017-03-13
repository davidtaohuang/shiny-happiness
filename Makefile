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

ifdef ALLOCWRAP
	LDFLAGS += alloc_wrap.c -ldl
endif 

.PHONY: all clean fclean re testing

vpath %.h includes

CC = gcc

CFLAGS = -Wall -Werror -Wextra

CTFLAGS = -fsanitize=address

INCLUDES = -I includes/

SRCFILES = 	ft_printf.c \
			datasetup.c \
			parseswitch.c \
			formatnum.c \
			ft_dtoa.c \
			insertformat.c \
			padcs.c \
			padnum.c \
			padswitch.c \
			parsedbl.c \
			parsenum.c \
			parsestr.c \
			parseunum.c \
			parsezjt.c \
			formatdbl.c \
			padhex.c \
			padoct.c \

SRCDIR := srcs

SRC:= $(addprefix $(SRCDIR)/, SRCFILES))

#Printing things
LIBSRC :=	libft/ft_putchar.c \
			libft/ft_putstr.c \
			libft/ft_putnbr.c \
			libft/ft_putendl.c \
			libft/ft_putnbrnl.c \
			libft/ft_putchar_fd.c \
			libft/ft_putstr_fd.c \
			libft/ft_putnbr_fd.c \
			libft/ft_putendl_fd.c \

#ASCII things
LIBSRC += 	libft/ft_isalpha.c \
			libft/ft_isdigit.c \
			libft/ft_isalnum.c \
			libft/ft_isascii.c \
			libft/ft_isprint.c \
			libft/ft_islower.c \
			libft/ft_isupper.c \
			libft/ft_toupper.c \
			libft/ft_tolower.c \

#String things
LIBSRC += 	libft/ft_strequ.c \
			libft/ft_strnequ.c \
			libft/ft_strcmp.c \
			libft/ft_strncmp.c \
			libft/ft_strcpy.c \
			libft/ft_strncpy.c \
			libft/ft_strchr.c \
			libft/ft_strrchr.c \
			libft/ft_strcat.c \
			libft/ft_strncat.c \
			libft/ft_strlcat.c \
			libft/ft_strstr.c \
			libft/ft_strnstr.c \
			libft/ft_strlen.c \
			libft/ft_strrev.c \
			libft/ft_swap.c \
			libft/ft_wstrdup.c \
			libft/ft_wstrcpy.c \
			libft/ft_strjoinreplace.c \
			libft/ft_wctouni.c \

#Memory things and more complicated string things
LIBSRC += 	libft/ft_bzero.c \
			libft/ft_memset.c \
			libft/ft_strclr.c \
			libft/ft_memcpy.c \
			libft/ft_memccpy.c \
			libft/ft_memmove.c \
			libft/ft_memchr.c \
			libft/ft_memcmp.c \
			libft/ft_strdup.c \
			libft/ft_memalloc.c \
			libft/ft_memdel.c \
			libft/ft_strnew.c \
			libft/ft_strdel.c \
			libft/ft_strjoin.c \
			libft/ft_strsub.c \
			libft/ft_strtrim.c \
			libft/ft_strsplit.c \
			libft/ft_striter.c \
			libft/ft_striteri.c \
			libft/ft_strmap.c \
			libft/ft_strmapi.c \

#Math things
LIBSRC += 	libft/ft_atoi.c \
			libft/ft_atoibase.c \
			libft/ft_itoa.c \
			libft/ft_itoabase.c \
			libft/ft_max.c \
			libft/ft_min.c \
			libft/ft_maxmap.c \
			libft/ft_minmap.c \

OBJDIR := obj

LOBJS := $(addprefix $(OBJDIR)/, $(patsubst %.c,%.o,$(LIBSRC)))

LOBJDIR := obj/libft

OBJS := $(addprefix $(OBJDIR)/, $(patsubst %.c,%.o,$(SRCFILES)))

NAME = libftprintf.a

all: $(NAME)

$(LOBJS): $(LSRCS) | $(LOBJDIR)

$(OBJS): ft_printf.h $(SRCS) | $(OBJDIR)

$(LOBJDIR)/%.o : libft/%.c
		@$(CC) $(CFLAGS) -c $< -o $@
		@echo "Done creating $@..."

$(LOBJDIR): | $(OBJDIR)
		@echo "Creating subdirectory libft object files..."
		@mkdir $(LOBJDIR)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
		@$(CC) $(CFLAGS) -c $< -o $@
		@echo "Done creating $@..."

$(OBJDIR):
		@echo "Creating subdirectory for object files..."
		@mkdir $(OBJDIR)

$(NAME): ft_printf.h $(LOBJS) $(OBJS)
		@echo "Creating printf library..."
		@ar rc $(NAME) $(OBJS) $(LOBJS)
		@echo "Indexing printf library..."
		@ranlib $(NAME)
		@echo "All done!"

myasan: ft_printf.h $(OBJS) $(NAME) main.c
		@echo "Creating myasan..."
		@$(CC) $(LDFLAGS) $(CTFLAGS) $(GFLAGS) main.c -o $@ -L ./ -lftprintf
		@echo "All done!"

clean:
		@echo "Deleting printf object files and subdirectory..."
		@rm -f $(LOBJS)
		@rm -rf $(LOBJDIR)
		@rm -f $(OBJS)
		@rm -rf $(OBJDIR)

fclean: clean
		@echo "Deleting $(NAME)..."
		@rm -rf $(NAME)
		@rm -rf myasan

re: fclean all
