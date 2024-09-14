#include <iostream>
#include "Span.hpp"


void test_separator(const std::string &separator)
{
  std::cout << "\033[34m";
  std::string linea(120, '-');
  size_t inicio = (120 - separator.length()) / 2;
  linea.replace(inicio, separator.length(), separator);
  std::cout << linea << std::endl;
  std::cout << "\033[0m";
}
void test_basic_span() {
    try {
        Span sp(10000);
        std::cout << "\033[33m";
        std::cout << "Creando un Span de 10000 elementos (1,2,3....10000)." << std::endl;
        std::cout << "\033[0m";
        for (int i = 0; i < 10000; ++i) {
            sp.addNumber(i);
        }
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}


void test_random_numbers() {
    try {
        Span sp(5);
        std::srand(::time(0)); // Cambiado std::time a ::time
        std::cout << "\033[33m";
        std::cout << "Creando un Span de 5 elementos con numeros aleatorios entre 1 y 200. ( ";
        
        for (int i = 0; i < 5; ++i) {
            int random_number = std::rand() % 200 + 1;
            sp.addNumber(random_number);
            std::cout << random_number << " ";
        }
       std::cout << ")\033[0m";
        std::cout << std::endl;
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}
void test_subject_cases() {
    try {
        Span sp(5);
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "\033[33m";
        std::cout << "Creando un Span del subject. ( 5, 3, 17, 9, 11 )" << std::endl;
        std::cout << "\033[0m";
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}
void test_span_full_exception() {
    try {
        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        std::cout << "\033[33m";
        std::cout << "Añadiendo un cuarto número al Span de tamaño 3 para provocar una excepción." << std::endl;
        std::cout << "\033[0m";
        sp.addNumber(4); // Esto debería lanzar una excepción
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}   
int main() {
    test_separator("Test Basic Span");
    test_basic_span();

    test_separator("Test Random Numbers");
    test_random_numbers();

    test_separator("Test Subject Cases");
    test_subject_cases();
    test_separator("Test Span Full Exception");
    test_span_full_exception();
    return 0;
}
