# VARIABLES
NAME = pipex
CC = gcc 
CFLAGS = -Wall -Wextra -Werror -I.
AR = ar rcs
RM = rm -f
LIBFT_PATH = ./libft
GREEN = `tput setaf 2`
RESET = `tput sgr0`
BLUE = `tput setaf 4`

# ARCHIVO
FILES = pipex.c\
		utils.c\

# CREA LOS ARCHIVOS OBJETO
OBJS = $(FILES:.c=.o)

# COMPILA LOS ARCHIVOS
# SE ENCARGA DE QUE AGREGAR A LA LIBRERIA .A LOS OBJETOS
all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -L$(LIBFT_PATH) -lft -o $(NAME)
	@echo "${GREEN}------✅PIPEX COMPILED✅------${RESET}"

%.o: %.c
	@make -sC $(LIBFT_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "${GREEN}-----------✅PIPEX COMPILED✅------------${RESET}"

# ENCARGADO DE HACER LA PARTE DE LIMPIEZA TANTO EN ESTA CARPETA COMO EN LIBFT
clean:
	@$(RM) $(OBJS)
	@make -sC $(LIBFT_PATH) clean
	@echo "${BLUE}------✅ALL CLEAN✅-------${RESET}"

fclean: clean
	@$(RM) $(NAME)
	@make -sC $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean