# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 15:42:33 by xamayuel          #+#    #+#              #
#    Updated: 2024/05/02 17:45:01 by xamayuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex01
SRCS     := main.cpp Bureaucrat.cpp Form.cpp
OBJS_DIR := .obj/
OBJS     := $(SRCS:.cpp=.o)
OBJS_PREF:= $(addprefix $(OBJS_DIR),$(OBJS))
CXX      := c++
CXXFLAGS := -Wall -Werror -Wextra -pedantic -std=c++98
RESET			= 	\033[0m
GREEN 			= 	\033[38;5;46m
WHITE 			= 	\033[38;5;15m
GREY 			= 	\033[38;5;8m
ORANGE 			= 	\033[38;5;202m
RED 			= 	\033[38;5;160m

$(OBJS_DIR)%.o: %.cpp
	@mkdir -p $(OBJS_DIR)
	@echo "$(GREY)Compiling.............................$(GREEN)$<"
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(GREEN)DONE!$(RESET)"
	@sleep .4
	@clear
	
all: $(NAME)

$(NAME): $(OBJS_PREF)
	@$(CXX) $(OBJS_PREF) -o $@

clean:
	@clear
	@rm -f $(OBJS_PREF)
	@rm -rf $(OBJS_DIR)
	@echo "$(RED)[INFO]$(GREY) Objects and .obj folder removed! $(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)[INFO]$(GREY) $(NAME) removed!"

re:     fclean all

.PHONY: all clean fclean re

author:
	@echo "Author: $(GREEN)xamayuel$(RESET)"

format:
	@clang-format -i -style="{BasedOnStyle: LLVM,IndentWidth: 4,ColumnLimit: 80,BreakBeforeBraces: Allman,AllowShortFunctionsOnASingleLine: false,IndentCaseLabels: false,KeepEmptyLinesAtTheStartOfBlocks: true,SpaceBeforeParens: false,SpaceInEmptyParentheses: false,SpacesInAngles: false,TabWidth: 4,UseTab: Never}" *.cpp *.hpp
