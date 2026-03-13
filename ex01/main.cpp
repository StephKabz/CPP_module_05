/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkabang <stkabang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:32:56 by kingstephan       #+#    #+#             */
/*   Updated: 2026/03/13 13:16:43 by stkabang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		Bureaucrat bob("Bob", 30);
		Form form1("Tax Form", 50, 25);
		
		std::cout << bob << std::endl;
		std::cout << form1 << std::endl;
		
		bob.signForm(form1);  // Doit réussir (30 < 50)
		
		std::cout << form1 << std::endl;  // Vérifier qu'il est signé
	}
	catch (std::exception& e) {
    	std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "  ====================  " << std::endl << std::endl;

	try {
		Bureaucrat steph("Steph", 70);
		Form form1("Tax Form", 50, 25);
		
		std::cout << steph << std::endl;
		std::cout << form1 << std::endl;
		
		steph.signForm(form1);  // Doit rater (70 > 50)
		
		std::cout << form1 << std::endl;  // Vérifier qu'il est signé
	}
	catch (std::exception& e) {
    	std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "  ====================  " << std::endl << std::endl;

	try {
		Bureaucrat marc("Marc", 50);
		Form form1("Tax Form", 50, 25);

		marc.minusGrade();
		
		std::cout << marc << std::endl;
		std::cout << form1 << std::endl;
		
		marc.signForm(form1);  // Doit rater (51 > 50)
		
		std::cout << form1 << std::endl;  // Vérifier qu'il est signé
	}
	catch (std::exception& e) {
    	std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "  ====================  " << std::endl << std::endl;

	try {
		Bureaucrat alice("Alice", 10);
		Form contract("Contract", 50, 25);
		
		alice.signForm(contract);  // 1ère signature
		alice.signForm(contract);  // 2ème signature
	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	return (0);
};

