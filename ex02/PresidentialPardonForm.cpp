/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingstephane <kingstephane@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:26:56 by kingstephan       #+#    #+#             */
/*   Updated: 2026/03/07 15:28:13 by kingstephan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
AForm("PresidentialPardonForm", 25, 5), target(target)
{};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : 
AForm(other) ,target(other.target) 
{};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	this->target = other.target;
	return (*this);
};

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->isSigned())
		throw AForm::FormNotSigned();
	if (executor.getGrade() > this->getExec_grade())
		throw AForm::GradeTooLowException();
	std::cout << this->target << " Has Been Pardonned by Zaphod Beeblebrox." << std::endl;
};

PresidentialPardonForm::~PresidentialPardonForm()
{};