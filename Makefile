# VARIABLES
NAME = pipex
BONUS_NAME = pipex_bonus
CC = gcc 
CFLAGS = -Wall -Wextra -Werror -I.
AR = ar rcs
RM = rm -f
LIBFT_PATH = ./livt
GREEN = `tput setaf 2`
RESET = `tput sgr0`
BLUE = `tput setaf 4`

# ARCHIVO
FILES = pipex.c\
		utils.c\

# CREA LOS ARCHIVOS OBJETO
OBJS = $(FILES:.c=.o)

# ARCHIVOS BONUS
FILES_BONUS = ./bonus/pipex_bonus.c\
			  ./bonus/archive_process_bonus.c\
			  ./bonus/archive_errors.c\
			  ./bonus/archive_heredoc.c\
			  ./bonus/archive_cmd_bonus.c\

# CREA LOS ARCHIVOS OBJETO
OBJS_BONUS = $(FILES_BONUS:.c=.o)

# COMPILA LOS ARCHIVOS
# SE ENCARGA DE QUE AGREGAR A LA LIBRERIA .A LOS OBJETOS
all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -L$(LIBFT_PATH) -lft -o $(NAME)
	@echo "${GREEN}------✅PIPEX COMPILED✅------${RESET}"

$(BONUS_NAME): $(OBJS_BONUS)
	@$(CC) $(OBJS_BONUS) -L$(LIBFT_PATH) -lft -o $(BONUS_NAME)
	@echo "${GREEN}------✅PIPEX BONUS COMPILED✅------${RESET}"

%.o: %.c
	@make -sC $(LIBFT_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "${GREEN}-----------✅PIPEX COMPILED✅------------${RESET}"

# ENCARGADO DE HACER LA PARTE DE LIMPIEZA TANTO EN ESTA CARPETA COMO EN LIBFT
clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@make -sC $(LIBFT_PATH) clean
	@echo "${BLUE}------✅ALL CLEAN✅-------${RESET}"

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@make -sC $(LIBFT_PATH) fclean

re: fclean all

bonus: $(BONUS_NAME)

.PHONY: all clean fclean re bonus