/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingstephane <kingstephane@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:32:56 by kingstephan       #+#    #+#             */
/*   Updated: 2026/03/03 18:11:02 by kingstephan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try{
		Bureaucrat steph("steph", 28);
		std::cout << steph << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat valid_one("valid_one", 1);
		valid_one.minusGrade();
		std::cout << valid_one << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat valid_two("valid_two", 150);
		valid_two.plusGrade();
		std::cout << valid_two << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	try{
		Bureaucrat Invalid("invalid", -12);
		std::cout << "ne sera pas atteint" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat invalid_two("invalid_two", 150);
		invalid_two.minusGrade();
		std::cout << invalid_two << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	return (0);
};

