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
	@echo "$(ORANGE)-----------------------  5000 Numbers -------------------------------------$(RESET)"
	@./PmergeMe `shuf -i 1-100000 -n 5000 | tr "\n" " "`
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

help:
	@echo "Paso a paso con un ejemplo	"
	@echo "Imaginemos que tenemos estos números: [5, 2, 9, 1, 7, 3]"
	@echo "Paso 1: Verificar si hay un número solitario"
	@echo "Si tenemos una cantidad impar de números, guardamos el último para después."
	@echo "Tenemos 6 números, que es par, así que no hay número solitario."
	@echo "Paso 2: Formar parejas"
	@echo "Agrupamos los números de dos en dos:"	
	@echo "[5, 2] → Primera pareja"
	@echo "[9, 1] → Segunda pareja"
	@echo "[7, 3] → Tercera pareja"
	@echo "Paso 3: Ordenar cada pareja (el mayor primero)"
	@echo "[5, 2] → [5, 2] (ya está ordenado con el mayor primero)"
	@echo "[9, 1] → [9, 1] (ya está ordenado con el mayor primero)"	
	@echo "[7, 3] → [7, 3] (ya está ordenado con el mayor primero)"
	@echo "Paso 4: Separar en dos grupos"
	@echo "Grupo de mayores (left): [5, 9, 7]"
	@echo "Grupo de menores (right): [2, 1, 3]"
	@echo "Paso 5: Ordenar el grupo de mayores"
	@echo "Usamos un método simple llamado 'insertion sort':"
	@echo "Empezamos con [5]"
	@echo "Añadimos 9: [5, 9]"
	@echo "Añadimos 7: [5, 7, 9]"
	@echo "Ahora tenemos el grupo de mayores ordenado: [5, 7, 9]"
	@echo "Paso 6: Crear una secuencia especial para insertar"
	@echo "Aquí usamos los 'números de Jacobsthal' para decidir en qué orden insertar los números menores."
	@echo "Para nuestro ejemplo con 3 números en el grupo de menores, la secuencia sería aproximadamente [0, 2, 1]."
	@echo "Paso 7: Insertar los números menores en el orden de la secuencia"
	@echo "Insertamos right[0] = 2 en [5, 7, 9] → [2, 5, 7, 9]"
	@echo "Insertamos right[2] = 3 en [2, 5, 7, 9] → [2, 3, 5, 7, 9]"
	@echo "Insertamos right[1] = 1 en [2, 3, 5, 7, 9] → [1, 2, 3, 5, 7, 9]"
	@echo "Resultado final"
	@echo "¡Ahora tenemos todos los números ordenados! [1, 2, 3, 5, 7, 9]"	
	@echo "---------------------------------------------------------------------"
	@echo "Los números de Jacobsthal forman una secuencia de números enteros que tienen aplicaciones en diversas áreas de las matemáticas y la informática, incluyendo el algoritmo de ordenación Ford-Johnson. Aquí te explico los aspectos clave de estos números:"
	@echo "Definición y Propiedades:"
	@echo "Relación de recurrencia:"
	@echo "La secuencia de Jacobsthal se define mediante la siguiente relación de recurrencia:"
	@echo "J(0) = 0"
	@echo "J(1) = 1"
	@echo "J(n) = J(n-1) + 2 * J(n-2) para n ≥ 2"
	@echo "Primeros términos:"
	@echo "Los primeros números de Jacobsthal son: 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341"