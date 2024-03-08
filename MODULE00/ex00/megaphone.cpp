/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:06:31 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/22 18:07:21 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

int main(int argc, char *argv[]) {
    int i(1);
    int j;

    if (argc > 1) {
        while (argv[i]) {
            j = 0;
            while (argv[i][j]) std::cout << (char)toupper(argv[i][j++]);
            std::cout << " ";
            i++;
        }
    } else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
    return (0);
}
