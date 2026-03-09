/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingstephane <kingstephane@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:24:16 by kingstephan       #+#    #+#             */
/*   Updated: 2026/03/07 18:12:34 by kingstephan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm* Intern::createShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
};

AForm* Intern::createRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
};

AForm* Intern::createPresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
};

Intern::Intern()
{
	std::cout << "Intern Default constructor Called" << std::endl;
};

/*Intern::Intern(const Intern &other)
{
	std::cout << "Intern copy constructor Called" << std::endl;
};*/

Intern& Intern::operator=(const Intern &other)
{
	std::cout << "Intern copy assignment Called" << std::endl;
	if (this == &other)
		return (*this);
	return (*this);
};

Intern::~Intern()
{
	std::cout << "Intern Destructeur Called" << std::endl;
};

AForm* Intern::makeForm(const std::string name, const std::string target)
{
	std::string form_names[3] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
	};

	AForm* (Intern::*creators[3])(std::string) = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPresidential
    };

	for(int i = 0; i < 3; i++)
	{
		if (name == form_names[i])
		{
			std::cout << "Intern Creates " << name << std::endl;
			return (this->*creators[i])(target);
		}
	}
	std::cout << "Error The Form " << name << " does not exist!" << std::endl;
	return (NULL);
};