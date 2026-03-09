/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingstephane <kingstephane@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:41:02 by kingstephan       #+#    #+#             */
/*   Updated: 2026/03/07 15:30:18 by kingstephan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
AForm("ShrubberyCreationForm", 145, 137), target(target)
{};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : 
AForm(other) ,target(other.target) 
{};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	this->target = other.target;
	return (*this);
};

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->isSigned())
		throw AForm::FormNotSigned();
	if (executor.getGrade() > this->getExec_grade())
		throw AForm::GradeTooLowException();
	std::ofstream file(this->target + "_shrubbery");
	if (file.is_open())
	{
		file << "      _-_" << std::endl
    		<< "    *~~   ~~*" << std::endl
 			<< " *~~         ~~*" << std::endl
			<< "{               }" << std::endl
 			<< " *  _-     -_  *" << std::endl
   			<< "   ~  \\ //  ~" << std::endl
			<< "_- -   | | _- _" << std::endl
  			<< "  _ -  | |   -_" << std::endl
      		<< "      // \\" << std::endl;
		file.close();
	}
};

ShrubberyCreationForm::~ShrubberyCreationForm()
{};