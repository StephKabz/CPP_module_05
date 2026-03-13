/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkabang <stkabang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 15:05:25 by kingstephan       #+#    #+#             */
/*   Updated: 2026/03/13 14:08:22 by stkabang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("unamed"), grade(30)
{
	std::cout << "Bureaucrat Default Constructor called" << std::endl;
};

Bureaucrat::Bureaucrat(const std::string name, int grade):
name(name), grade(grade) 
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
};

Bureaucrat::Bureaucrat(const Bureaucrat &other) :
name(other.name), grade(other.grade)
{
	std::cout << "Bureaucrat copy constructeur called" << std::endl;
};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "copy assignment called" << std::endl;
	if (this == &other)
		return (*this);
	this->grade = other.grade;
	return (*this);
};

std::string Bureaucrat::getName() const
{
	return (this->name);
};

int Bureaucrat::getGrade() const
{
	return (this->grade);
};

void Bureaucrat::plusGrade()
{
	if (grade <= 1)
		throw GradeTooHighException();
	this->grade--;
};

void Bureaucrat::minusGrade()
{
	if (grade >= 150)
		throw GradeTooLowException();
	this->grade++;
};

void Bureaucrat::signForm(AForm& Aform)
{
	try
	{
		Aform.beSigned(*this);
		std::cout << this->getName() << " Signed " 
		<< Aform.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->name << " couldn't sign " 
		<< Aform.getName() << " because " << e.what() << std::endl;
	}
};

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed "
		<< form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->name << " couldn't execute " 
		<< form.getName() << " because " << e.what() << std::endl;
	}
	
};

Bureaucrat::~Bureaucrat()
{
	std::cout << this->getName() << " Bureaucrat destructor called" << std::endl;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " 
	<< bureaucrat.getGrade();
	return (out);
};
