.PHONY: all clean fclean re

# Name of file
NAME		=	test

# Directories name
PATH_INC	=	includes
PATH_SRC	=	srcs/
PATH_OBJ	=	objs/
PATH_CLASS	=	class
PATH_TEST	=	$(PATH_INC)/test

# List of sources
SRCS_FILES	= 	main.cpp 
SRCS_CLASS	= 	
INC_FILES	=	base.hpp vector_dclr.hpp vector.hpp reverse_iterator.hpp iterator_dclr.hpp
INC_TEST	=	test.hpp testAccess.hpp testResize.hpp testPrint.hpp testIterator.hpp testModifier.hpp


SRCS		=	$(addprefix $(), $(SRCS_FILES) $(addprefix $(PATH_CLASS)/, $(SRCS_CLASS)))
OBJS		=	$(addprefix $(PATH_OBJ), $(SRCS:%.cpp=%.o))
INCS		=	$(addprefix $(PATH_INC)/, $(INC_FILES)) $(addprefix $(PATH_TEST)/, $(INC_TEST))
DIRS_LIST	=	$(PATH_CLASS)

# Commands of compilation
COMP		=	clang++
# COMP_LIB	=	-lc++
COMP_DEB	=	-g3 -fsanitize=address
COMP_FLAG	=	-Wall -Werror -Wextra $(COMP_DEB) --std=c++98 -stdlib=libc++ -I$(PATH_INC) -I$(PATH_TEST) -I /usr/lib/c++/v1/  $(COMP_LIB)

# tester


# Others Command
RM			=	/bin/rm
MKDIR		=	/bin/mkdir
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
	@ $(MKDIR) -p $(addprefix $(PATH_OBJ)/, $(DIRS_LIST))

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
