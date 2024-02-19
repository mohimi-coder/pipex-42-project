cc = cc

FLAGS = -Wall -Wextra -Werror

FILE = ./mandatory/ft_split.c \
		./mandatory/ft_strjoin.c \
		./mandatory/pipex.c \
		./mandatory/utils.c \
		./mandatory/main.c \
		./mandatory/ft_searsh_for_slash.c \

OBJECT_FILE = $(FILE:.c=.o)

BONUS = ./bonus/ft_execve_bonus.c \
		./bonus/ft_split_bonus.c \
		./bonus/ft_strjoin_bonus.c \
		./bonus/pipex_bonus.c \
		./bonus/utils_bonus.c \
		./bonus/main_bonus.c \
		./bonus/get_next_line_bonus.c \
		./bonus/get_next_line_utils_bonus.c \
		./bonus/ft_putstr_fd_bonus.c \
		./bonus/ft_strncmp_bonus.c \
		./bonus/ft_open_files_bonus.c \

OBJECT_FILE_BONUS = $(BONUS:.c=.o)

GREEN = \033[0;32m
RESET = \033[0m

NAME = pipex
NAME_BONUS = pipex_bonus

HEADER = pipex.h

HEADER_BONUS = pipex_bonus.h

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)
	@echo "$(GREEN)$(NAME) created$(RESET)"

$(NAME) : $(OBJECT_FILE)
	$(CC) $(FLAGS) $(OBJECT_FILE) -o $(NAME)

$(NAME_BONUS) : $(OBJECT_FILE_BONUS)
	$(CC) $(FLAGS) $(OBJECT_FILE_BONUS) -o $(NAME_BONUS)

bonus : $(NAME_BONUS)
	@echo "$(GREEN)$(NAME_BONUS) created$(RESET)"
-include $(HEADER) $(HEADER_BONUS)

tag:
	@echo "$(GREEN)"
	@echo "$(GREEN)██████╗ ██╗██████╗ ███████╗██╗  ██╗"
	@echo "$(GREEN)██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝"
	@echo "$(GREEN)██████╔╝██║██████╔╝█████╗   ╚███╔╝ "
	@echo "$(GREEN)██╔═══╝ ██║██╔═══╝ ██╔══╝   ██╔██╗ "
	@echo "$(GREEN)██║     ██║██║     ███████╗██╔╝ ██╗ BY MOHIMI"
	@echo "$(GREEN)╚═╝     ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝"

clean :
	rm -f $(OBJECT_FILE) $(OBJECT_FILE_BONUS)
	@echo "$(GREEN)$(NAME)$(NAME_BONUS) cleaned$(RESET)"

re : fclean all

fclean : clean
	rm -f $(NAME) $(NAME_BONUS)
	@echo "$(GREEN)$(NAME)$(NAME_BONUS) fcleaned$(RESET)"

.PHONY : all clean fclean re bonus