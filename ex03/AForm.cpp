/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingstephane <kingstephane@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:15:58 by kingstephan       #+#    #+#             */
/*   Updated: 2026/03/05 17:59:48 by kingstephan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm(const std::string name, const int sign_grade, const int exec_grade) : 
name(name), sign_grade(sign_grade), exec_grade(exec_grade), is_signed(false)
{
	if (sign_grade < 1)
		throw AForm::GradeTooHighException();
	if (sign_grade > 150)
		throw AForm::GradeTooLowException();
	if (exec_grade < 1)
		throw AForm::GradeTooHighException();
	if (exec_grade > 150)
		throw AForm::GradeTooLowException();
};

AForm::AForm(const AForm &other) :
name(other.name), sign_grade(other.sign_grade), exec_grade(other.exec_grade), is_signed(other.is_signed)
{};

AForm& AForm::operator=(const AForm &other)
{
	if (this == &other)
		return (*this);
	this->is_signed = other.is_signed;
	return (*this);
};

AForm::~AForm(){};

void AForm::beSigned(const Bureaucrat &bureaucrate)
{
	if (bureaucrate.getGrade() > this->sign_grade)
		throw AForm::GradeTooLowException();
	this->is_signed = true;
};

std::string AForm::getName() const
{
	return (this->name);
};
int AForm::getSign_grade() const
{
	return (this->sign_grade);
};

int AForm::getExec_grade() const
{
	return (this->exec_grade);
};

bool AForm::isSigned() const
{
	return (this->is_signed);
};

std::ostream& operator<<(std::ostream& out, const AForm& Aform)
{
	out << Aform.getName() << " :" << std::endl
	<< "Sign_grade is : " << Aform.getSign_grade() << "!" << std::endl 
	<< "Exec_grade is : " << Aform.getExec_grade() << "!" << std::endl
	<< "Is AForm signed : " << (Aform.isSigned() ? "Yes!" : "No!");
	return (out);
};
