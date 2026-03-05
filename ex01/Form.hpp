/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingstephane <kingstephane@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:02:47 by kingstephan       #+#    #+#             */
/*   Updated: 2026/03/05 18:00:02 by kingstephan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <string>
#include <fstream>
#include <exception>

class Bureaucrat;

class Form
{
	private :
		const std::string name;
		const int sign_grade;
		const int exec_grade;
		bool is_signed;
	public :
		Form(const std::string name, const int sign_grade, const int exec_grade);
		Form(const Form &other);
		Form& operator=(const Form &other);
		~Form();
		void beSigned(const Bureaucrat &bureaucrate);
		std::string getName() const;
		int getSign_grade() const;
		int getExec_grade() const;
		bool isSigned() const;
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
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif