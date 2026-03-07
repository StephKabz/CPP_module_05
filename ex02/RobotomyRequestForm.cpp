/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingstephane <kingstephane@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:31:30 by kingstephan       #+#    #+#             */
/*   Updated: 2026/03/07 15:32:13 by kingstephan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
AForm("RobotomyRequestForm", 72, 45), target(target)
{};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : 
AForm(other) ,target(other.target) 
{};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	this->target = other.target;
	return (*this);
};

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->isSigned())
		throw AForm::FormNotSigned();
	if (executor.getGrade() > this->getExec_grade())
		throw AForm::GradeTooLowException();
	std::cout << "DDrrrr" << "zwiiizwii" << "grrr" << std::endl;
	if (rand() % 2 == 0)
		std::cout << this->target << " has been robotomized successfully " << std::endl;
	else
		std::cout << "Failed to robotomized " << this->target << std::endl;
};

RobotomyRequestForm::~RobotomyRequestForm()
{};