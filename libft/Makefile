# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brichard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 12:04:00 by brichard          #+#    #+#              #
#    Updated: 2019/05/01 14:22:23 by brichard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                   VARIABLES                                  #
################################################################################

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INC = includes

SRCS_PATH = srcs
PRINTF_SRCS_PATH = srcs/ft_printf

OBJS_PATH = obj
PRINTF_OBJS_PATH = $(OBJS_PATH)

OBJS = $(SRCS:.c=.o)
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

D_OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS))
D_PRINTF_OBJS = $(addprefix $(PRINTF_OBJS_PATH)/, $(PRINTF_OBJS))

################################################################################
#                                    SOURCES                                   #
################################################################################

PRINTF_SRCS =

SRCS =			ft_strcmp.c \
				ft_putendl.c \

################################################################################
#                                  Headers                                     #
################################################################################

HEAD = libft.h

################################################################################
#                                    COlORS                                    #
################################################################################

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

define run_and_test
printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
	$(1) 2> $@.log; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
	elif [ -s $@.log ]; then \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
	else  \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
	fi; \
	cat $@.log; \
	rm -f $@.log; \
	exit $$RESULT
endef

OK_STRING    = "[OK]"
ERROR_STRING = "[ERROR]"
WARN_STRING  = "[WARNING]"
COM_STRING   = "Compiling"

################################################################################
#                                   COMMANDS                                   #
################################################################################

.PHONY: all clean fclean re

all: $(NAME)
	@echo > /dev/null

$(NAME): $(OBJS_PATH) $(INC) $(D_PRINTF_OBJS) $(D_OBJS)
	@$(call run_and_test, ar -rc $(NAME) $(D_OBJS) $(D_PRINTF_OBJS))
	@ranlib $(NAME)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c $(addprefix $(INC)/, $(HEAD))
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INC)

$(PRINTF_OBJS_PATH)/%.o: $(PRINTF_SRCS_PATH)/%.c
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INC)

$(OBJS_PATH):
	@mkdir -p $@

clean:
	@rm -f $(D_OBJS) && rm -rf $(OBJS_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all
