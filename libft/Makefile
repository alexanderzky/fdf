# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/27 13:49:49 by ozalisky          #+#    #+#              #
#    Updated: 2018/05/31 12:30:58 by ozalisky         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memdel.c \
		ft_memmove.c ft_memset.c ft_putchar.c \
		ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
		ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
		ft_putstr_fd.c ft_strcat.c \
		ft_strchr.c ft_strclr.c ft_strcmp.c \
		ft_strcpy.c ft_strdel.c ft_strdup.c \
		ft_strequ.c ft_striter.c ft_striteri.c \
		ft_strjoin.c ft_strlcat.c ft_strlen.c \
		ft_strmap.c ft_strmapi.c ft_strncat.c \
		ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
		ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c \
		ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_memcpy_bkw.c ft_iscntrlspace.c \
		ft_islower.c ft_issign.c ft_isupper.c ft_iscntrlch.c ft_isspace.c ft_nbr_lngth.c ft_lstnew.c \
		ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_arrdel.c ft_has_ch.c ft_words.c \
		ft_printf.c ft_itoa_base.c ft_uformat.c ft_xformat.c ft_diformat.c ft_influences.c \
		ft_checkers.c ft_adders.c ft_lists.c ft_pformat.c ft_cformat.c ft_sformat.c ft_oformat.c ft_buffer_add_wrong.c ft_o_additional.c ft_influence_chars.c \
		ft_wcformat.c ft_u_additional.c ft_p_additional.c ft_additional.c ft_di_minus.c ft_di_additional.c ft_swformat.c ft_ws_minus.c ft_ws_plus.c ft_s_plus.c \
		ft_length_funcs.c ft_x_additional.c ft_x_minus.c ft_itoa_base_dec.c get_next_line.c\

OBJ = ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o \
		ft_itoa.o ft_memalloc.o ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o \
		ft_memdel.o ft_memmove.o ft_memset.o ft_putchar.o ft_putchar_fd.o ft_putendl.o \
		ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o \
		ft_strcat.o ft_strchr.o ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o ft_strdup.o \
		ft_strequ.o ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlen.o ft_strmap.o ft_strmapi.o \
		ft_strncat.o ft_strncmp.o ft_strncpy.o ft_strnequ.o ft_strnew.o \
		ft_strnstr.o ft_strrchr.o ft_strsplit.o ft_strstr.o ft_strsub.o \
		ft_strtrim.o ft_tolower.o ft_toupper.o ft_memcpy_bkw.o ft_iscntrlspace.o ft_islower.o ft_issign.o ft_isupper.o \
		ft_iscntrlch.o ft_isspace.o ft_nbr_lngth.o ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstmap.o \
		ft_arrdel.o ft_has_ch.o ft_words.o \
		ft_printf.o ft_itoa_base.o ft_uformat.o ft_xformat.o ft_diformat.o ft_influences.o \
		ft_checkers.o ft_adders.o ft_lists.o ft_pformat.o ft_cformat.o ft_sformat.o ft_oformat.o ft_buffer_add_wrong.o ft_o_additional.o ft_influence_chars.o \
		ft_wcformat.o ft_u_additional.o ft_p_additional.o ft_additional.o ft_di_minus.o ft_di_additional.o ft_swformat.o ft_ws_minus.o ft_ws_plus.o ft_s_plus.o \
		ft_length_funcs.o ft_x_additional.o ft_x_minus.o ft_itoa_base_dec.o get_next_line.o\

CC = gcc

FLAGS = -Wall -Wextra -Werror -c

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(SRC)
	ar rc $(NAME) $(OBJ)

.PHONY: clean
clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re:	fclean all
