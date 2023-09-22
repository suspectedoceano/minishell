# NAME = libft
NAME = ylib

CFLAGS = -Wall -Wextra -Werror
CFLAGS_DEBUG = $(CFLAGS) -fsanitize=address -fsanitize=undefined
SRC_DIR = src
OBJ_DIR = obj
DBG_OBJ_DIR = dobj
SRC = $(wildcard $(addsuffix *.c,src/))
OBJ = $(patsubst src/%.c,obj/%.o,$(SRC))
DBG_OBJ = $(patsubst src/%.c,dobj/%.o,$(SRC))
DEFINES = -D GNL_BSIZE=24 LIST_C_STEP=20
INC_DIR = -I ./
CC = cc
AR = ar -rc

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(DBG_OBJ_DIR):
	@mkdir -p $(DBG_OBJ_DIR)

$(NAME): $(OBJ)
	@echo $(NAME): creating library $(NAME)
	@$(AR) $(NAME).a $(OBJ)

obj/%.o: src/%.c | $(OBJ_DIR)
	@echo $(NAME): building $@
	@$(CC) $(CFLAGS) $(INC_DIR) -O3 -c $< -o $@

debug: $(DBG_OBJ)
	@echo $(NAME): creating debuggable library $(NAME)
	@$(AR) $(NAME).a $(DBG_OBJ)

dobj/%.o: src/%.c | $(DBG_OBJ_DIR)
	@echo $(NAME): debug building $@
	@$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@ -g

clean:
	@echo $(NAME): cleaning objects
	@rm -f $(OBJ) $(DBG_OBJ)

fclean: clean
	@echo $(NAME): cleaning build artifacts
	@rm -f $(NAME).a

re: fclean all

redb: fclean debug

.PHONY: all clean fclean re debug redb $(NAME) $(OBJ_DIR) $(DBG_OBJ_DIR)
