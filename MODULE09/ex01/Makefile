# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 15:42:33 by xamayuel          #+#    #+#              #
#    Updated: 2024/08/11 19:22:19 by xamayuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN
SRCS     := main.cpp RPN.cpp
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

HEADER_SCRIPT= ../../add_header.sh

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
	@clang-format -i -style="{BasedOnStyle: LLVM,IndentWidth: 2,ColumnLimit: 80,BreakBeforeBraces: Allman,AllowShortFunctionsOnASingleLine: false,IndentCaseLabels: false,KeepEmptyLinesAtTheStartOfBlocks: true,SpaceBeforeParens: false,SpaceInEmptyParentheses: false,SpacesInAngles: false,TabWidth: 2,UseTab: Never}" *.cpp *.hpp

test: all
	@echo "--------------------------------"
	@echo "https://paodayag.dev/reverse-polish-notation-js-parser/"
	@echo "--------------------------------"
	@./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	@echo "--------------------------------"
	@./$(NAME) "7 7 * 7 -"
	@echo "--------------------------------"
	@./$(NAME) "1 2 * 2 / 2 * 2 4 - +"
	@echo "--------------------------------"
	@./$(NAME) "(1 +1)"
	@echo "--------------------------------"
	@./$(NAME) "1 2 * 2 / 2 * 2 4 - 9 3 / + 9 - 1 3 * 3 +"
	@echo "--------------------------------"
	@./$(NAME) "3 4 + 5"
	@echo "--------------------------------"
	@./$(NAME) "4"
	@echo "--------------------------------"
	@./$(NAME) "1 2 3"
	@echo "--------------------------------"
	@./$(NAME) "1 2 3 +"
	@echo "--------------------------------"
	@./$(NAME) "1 2 3 + +"
	@echo "--------------------------------"
	@./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	@echo "--------------------------------"
	@./$(NAME) "9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -"
	@echo "--------------------------------"
	@./$(NAME) "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /"
	