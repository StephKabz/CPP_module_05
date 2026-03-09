/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingstephane <kingstephane@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:02:47 by kingstephan       #+#    #+#             */
/*   Updated: 2026/03/05 18:00:02 by kingstephan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <string>
#include <fstream>
#include <exception>

class Bureaucrat;

class AForm
{
	private :
		const std::string name;
		const int sign_grade;
		const int exec_grade;
		bool is_signed;
	public :
		AForm(const std::string name, const int sign_grade, const int exec_grade);
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);
		virtual ~AForm();
		void beSigned(const Bureaucrat &bureaucrate);
		std::string getName() const;
		int getSign_grade() const;
		int getExec_grade() const;
		bool isSigned() const;
		virtual void execute(Bureaucrat const &executor) const = 0;
	class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Grade too High";
			};
		};

	class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Grade too Low";
			};
		};
	class FormNotSigned : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Form is not Signed!";
			};
		};
};

std::ostream& operator<<(std::ostream& out, const AForm& Aform);

#endif