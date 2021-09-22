.PHONY: all clean fclean re

# Name of file
NAME		=	test

# Directories name
PATH_INC	=	includes
PATH_SRC	=	srcs/
PATH_OBJ	=	objs/
PATH_CLASS	=	class

# List of sources
SRCS_FILES	= 	main.cpp
SRCS_CLASS	= 	
INC_FILES	=	vector_dclr.hpp vector.hpp

SRCS		=	$(addprefix $(), $(SRCS_FILES) $(addprefix $(PATH_CLASS)/, $(SRCS_CLASS)))
OBJS		=	$(addprefix $(PATH_OBJ), $(SRCS:%.cpp=%.o))
INCS		=	$(addprefix $(PATH_INC)/, $(INC_FILES))
DIRS_LIST	=	$(PATH_CLASS)

# Commands of compilation
COMP		=	clang++
# COMP_LIB	=	-lc++
COMP_FLAG	=	-Wall -Werror -Wextra --std=c++98 -stdlib=libc++ -I$(PATH_INC)  -I /usr/lib/c++/v1/  $(COMP_LIB)
COMP_DEB	=	-g3 -fsanitize=address

# Others Command
RM			=	/bin/rm
# SETLIST		=	set -x;

# Color Code and template code
_YELLOW		=	\033[38;5;184m
_GREEN		=	\033[38;5;46m
_RESET		=	\033[0m
_INFO		=	[$(_YELLOW)INFO$(_RESET)]
_SUCCESS	=	[$(_GREEN)SUCCESS$(_RESET)]

# Functions
all:	init $(NAME)
	@ echo "$(_SUCCESS) Compilation done"

init:
	@ mkdir -p $(addprefix $(PATH_OBJ)/, $(DIRS_LIST))

$(NAME): $(OBJS) $(INCS)
	@ $(SETLIST) $(COMP) $(COMP_FLAG) -o $(NAME) $(OBJS)
	@ echo "$(_INFO) linking of $(NAME)"

$(PATH_OBJ)%.o : $(PATH_SRC)%.cpp  $(INCS)
	@ ( $(SETLIST) $(COMP) $(COMP_FLAG) -c $< -o $@ )
	@ echo "$(_INFO) Compilation of $*"

clean:
	@ $(RM) -rf $(PATH_OBJ)
	@ echo "$(_INFO) Deleted files and directory"

fclean: clean
	@ $(RM) -rf $(NAME)

re: fclean all
