/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingstephane <kingstephane@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:46:31 by kingstephan       #+#    #+#             */
/*   Updated: 2026/03/05 17:57:17 by kingstephan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <string>
#include <fstream>
#include <exception>

class Form;

class Bureaucrat
{
	private :
		const std::string name;
		int grade;
	public :
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);
		std::string getName() const;
		int	getGrade() const;
		void plusGrade();
		void minusGrade();
		void signForm(Form& form);
		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Grade is too High(minimum 1)";
			};
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Grade is too low(Maximum 150)";
			};
		};
		~Bureaucrat();
};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);
	

#endif