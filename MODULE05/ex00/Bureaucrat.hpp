#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iomanip>
#include <iostream>
#include <string>
// COLORS
#define KRED "\033[0;31m"
#define KGRE "\033[0;32m"
#define KYEL "\033[0;33m"
#define LBLU "\033[0;34m"
#define KPUR "\033[0;35m"
#define KNOR "\033[0;37m"
#define KCYA "\033[0;36m"

#define KBLA "\033[0;30m"
#define KBLU "\x1B[34m"
#define SUBR "\033[0;31m\033[4m"
#define NEGR "\033[0;31m\033[1m"

class Bureaucrat
{

public:
  Bureaucrat(const std::string &name, int grade);
  Bureaucrat(Bureaucrat const &src);
  virtual ~Bureaucrat();
  Bureaucrat &operator=(Bureaucrat const &rhs);

public:
  int getGrade() const;
  std::string getName() const;
  void incrementGrade();
  void decrementGrade();

public:
  class GradeTooHighException : public std::exception
  {
    virtual const char *what() const throw();
  };
  class GradeTooLowException : public std::exception
  {
    virtual const char *what() const throw();
  };

private:
  const std::string _name;
  int _grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);

#endif