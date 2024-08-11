#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
class ShrubberyCreationForm : public AForm
{
  private:
    const std::string _target;
    ShrubberyCreationForm(void);

  public:
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm(void);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

    std::string const &getTarget(void) const;

    void execute(Bureaucrat const &executor) const;
};

#endif