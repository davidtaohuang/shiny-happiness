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

#Printing things
LIBSRCS := ft_putchar.c ft_putstr.c ft_putnbr.c ft_putendl.c ft_putnbrnl.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c \

#ASCII things
LIBSRCS += ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_islower.c ft_isupper.c ft_toupper.c ft_tolower.c \

#String things
LIBSRCS += ft_strequ.c ft_strnequ.c \
	ft_strcmp.c ft_strncmp.c \
	ft_strcpy.c ft_strncpy.c \
	ft_strchr.c ft_strrchr.c \
	ft_strcat.c ft_strncat.c ft_strlcat.c \
	ft_strstr.c ft_strnstr.c \
	ft_strlen.c ft_strrev.c  ft_swap.c \
	ft_wstrdup.c ft_wstrcpy.c ft_putwstr.c \
	ft_strjoinreplace.c \

#Memory things and more complicated string things
LIBSRCS += ft_bzero.c ft_memset.c ft_strclr.c \
	ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	ft_strdup.c ft_memalloc.c ft_memdel.c \
	ft_strnew.c ft_strdel.c ft_strjoin.c \
	ft_strsub.c ft_strtrim.c ft_strsplit.c ft_striter.c ft_striteri.c \
	ft_strmap.c ft_strmapi.c \

#List things
LIBSRCS += ft_lstnew.c ft_lstadd.c ft_lstiter.c \
	ft_lstdelone.c ft_lstdel.c ft_lstmap.c \
	ft_mrlc.c ft_srlc.c ft_strnew2.c \
	get_next_line.c \
	ft_lstaddend.c ft_lstmemdel.c

#Math things
LIBSRCS += ft_atoi.c ft_atoibase.c \
	ft_itoa.c ft_itoabase.c \
	ft_max.c ft_min.c ft_maxmap.c ft_minmap.c \

LOBJS := $(addprefix libft/obj/, $(patsubst %.c,%.o,$(LIBSRCS)))

LIB = libft/libft.a

OBJDIR := obj

OBJS := $(addprefix $(OBJDIR)/, $(patsubst %.c,%.o,$(SRCFILES)))

LPF = libftprintf.a

all: $(LPF)

$(LIB):
		make -C libft/

$(OBJS): ft_printf.h $(SRCS) | $(OBJDIR)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
		@$(CC) $(CFLAGS) -c $< -o $@
		@echo "Done creating $@..."

$(OBJDIR):
		@echo "Creating subdirectory for object files..."
		@mkdir $(OBJDIR)

$(LPF): ft_printf.h $(OBJS) $(LIB)
		@echo "Creating printf library..."
		@ar rc $(LPF) $(OBJS) $(LOBJS)
		@echo "Indexing printf library..."
		@ranlib $(LPF)
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
		@rm -rf $(LPF)
		make fclean -C libft/

re: fclean all
