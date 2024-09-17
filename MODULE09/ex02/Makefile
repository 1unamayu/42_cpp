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

NAME =  PmergeMe
SRCS     := main.cpp PmergeMe.cpp
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

test:
	@echo "$(ORANGE)-----------------------  3000 Numbers -------------------------------------$(RESET)"
	@./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
	@echo "$(ORANGE)-----------------------  2000 Numbers -------------------------------------$(RESET)"
	@./PmergeMe `shuf -i 1-100000 -n 2000 | tr "\n" " "`
	@echo "$(ORANGE)-----------------------  1000 Numbers -------------------------------------$(RESET)"
	@./PmergeMe `shuf -i 1-100000 -n 1000 | tr "\n" " "`
	@echo "$(ORANGE)-----------------------  TEXT -------------------------------------$(RESET)"
	@./PmergeMe "2" "1" "55" "33"
	@echo "$(ORANGE)-----------------------  NEGATIVE NUMBERS -------------------------------------$(RESET)"
	@./PmergeMe "-2" "1" "55" "33" || true
	@echo "$(ORANGE)-----------------------  DUPLICATE NUMBERS -------------------------------------$(RESET)"	
	@./PmergeMe "2" "1" "55" "33" "55" "33" || true
	@echo "$(ORANGE)-----------------------  SINGLE NUMBER -------------------------------------$(RESET)"
	@./PmergeMe "2" || true
	@echo "$(ORANGE)-----------------------  EMPTY -------------------------------------$(RESET)"
	@./PmergeMe || true
	@echo "$(ORANGE)-----------------------  ZERO -------------------------------------$(RESET)"
	@./PmergeMe "0" "1" "55" "33" || true
	@echo "$(ORANGE)-----------------------  MAX INT -------------------------------------$(RESET)"
	@./PmergeMe "2147483647" "1" "55" "33" || true