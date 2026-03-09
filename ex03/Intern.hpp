/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingstephane <kingstephane@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:23:44 by kingstephan       #+#    #+#             */
/*   Updated: 2026/03/07 18:12:20 by kingstephan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private :
		AForm* createShrubbery(std::string target);
		AForm* createRobotomy(std::string target);
		AForm* createPresidential(std::string target);
	public :
		Intern();
		//Intern(const Intern &other);
		Intern& operator=(const Intern &other);
		~Intern();
		AForm* makeForm(const std::string name, const std::string target);
};

#endif