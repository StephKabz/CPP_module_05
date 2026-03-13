/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkabang <stkabang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:15:58 by kingstephan       #+#    #+#             */
/*   Updated: 2026/03/13 13:55:49 by stkabang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(const std::string name, const int sign_grade, const int exec_grade) : 
name(name), sign_grade(sign_grade), exec_grade(exec_grade), is_signed(false)
{
	if (sign_grade < 1)
		throw Form::GradeTooHighException();
	if (sign_grade > 150)
		throw Form::GradeTooLowException();
	if (exec_grade < 1)
		throw Form::GradeTooHighException();
	if (exec_grade > 150)
		throw Form::GradeTooLowException();
};

Form::Form(const Form &other) :
name(other.name), sign_grade(other.sign_grade), exec_grade(other.exec_grade), is_signed(other.is_signed)
{};

Form& Form::operator=(const Form &other)
{
	if (this == &other)
		return (*this);
	this->is_signed = other.is_signed;
	return (*this);
};

Form::~Form(){};

void Form::beSigned(const Bureaucrat &bureaucrate)
{
	if (this->is_signed)
	{
		std::cout << "Form already signed!" << std::endl;
		return;
	}
	if (bureaucrate.getGrade() > this->sign_grade)
		throw Form::GradeTooLowException();
	this->is_signed = true;
};

std::string Form::getName() const
{
	return (this->name);
};

int Form::getSign_grade() const
{
	return (this->sign_grade);
};

int Form::getExec_grade() const
{
	return (this->exec_grade);
};

bool Form::isSigned() const
{
	return (this->is_signed);
};

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	out << form.getName() << " :" << std::endl
	<< "Sign_grade is : " << form.getSign_grade() << "!" << std::endl 
	<< "Exec_grade is : " << form.getExec_grade() << "!" << std::endl
	<< "Is Form signed : " << (form.isSigned() ? "Yes!" : "No!");
	return (out);
};
