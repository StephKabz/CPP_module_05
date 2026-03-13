/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stkabang <stkabang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:32:56 by kingstephan       #+#    #+#             */
/*   Updated: 2026/03/13 14:06:55 by stkabang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>

void printSeparator(std::string title) {
    std::cout << "\n========================================" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "========================================\n" << std::endl;
}

int main() {
    srand(time(NULL));
    
    printSeparator("TEST 1: ShrubberyCreationForm - SUCCESS");
    try {
        Bureaucrat bob("Bob", 137);
        ShrubberyCreationForm shrub("home");
        
        std::cout << bob << std::endl;
        std::cout << shrub << std::endl << std::endl;
        
        bob.signForm(shrub);
        bob.executeForm(shrub);
        
        std::cout << "\n✓ Check if file 'home_shrubbery' was created!" << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    printSeparator("TEST 2: ShrubberyCreationForm - NOT SIGNED");

    try {
        Bureaucrat charlie("Charlie", 100);
        ShrubberyCreationForm shrub2("garden");
        
        std::cout << charlie << std::endl;
        std::cout << shrub2 << std::endl << std::endl;
        
        // Ne signe PAS le formulaire
        charlie.executeForm(shrub2);  // Devrait échouer
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // TEST 3: ShrubberyCreationForm - Grade Too Low to Execute

    printSeparator("TEST 3: ShrubberyCreationForm - GRADE TOO LOW");
    try {
        Bureaucrat low("LowGrade", 145);      // Peut signer (145)
        Bureaucrat veryLow("VeryLow", 150);   // Ne peut PAS exécuter (137)
        ShrubberyCreationForm shrub3("office");
        
        low.signForm(shrub3);           // OK
        veryLow.executeForm(shrub3);    // Devrait échouer
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // TEST 4: RobotomyRequestForm - Success (50/50)

    printSeparator("TEST 4: RobotomyRequestForm - RANDOM 50/50");
    try {
        Bureaucrat alice("Alice", 45);
        RobotomyRequestForm robot("Bender");
        
        std::cout << alice << std::endl;
        std::cout << robot << std::endl << std::endl;
        
        alice.signForm(robot);
        
        std::cout << "\nExecuting 3 times to see randomness:" << std::endl;
        alice.executeForm(robot);
        alice.executeForm(robot);
        alice.executeForm(robot);
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    

    // TEST 5: RobotomyRequestForm - Grade Too Low

    printSeparator("TEST 5: RobotomyRequestForm - GRADE TOO LOW");

    try {
        Bureaucrat signer("Signer", 72);    // Peut signer
        Bureaucrat executor("Executor", 100); // Ne peut PAS exécuter (45)
        RobotomyRequestForm robot2("R2D2");
        
        signer.signForm(robot2);
        executor.executeForm(robot2);  // Devrait échouer
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // TEST 6: PresidentialPardonForm - Success

    printSeparator("TEST 6: PresidentialPardonForm - SUCCESS");

    try {
        Bureaucrat president("President", 5);
        PresidentialPardonForm pardon("Arthur Dent");
        
        std::cout << president << std::endl;
        std::cout << pardon << std::endl << std::endl;
        
        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // TEST 7: PresidentialPardonForm - Grade Too Low to Sign

    printSeparator("TEST 7: PresidentialPardonForm - TOO LOW TO SIGN");

    try {
        Bureaucrat lowBureaucrat("LowBureaucrat", 50);
        PresidentialPardonForm pardon2("Zaphod");
        
        lowBureaucrat.signForm(pardon2);  // Devrait échouer (besoin 25)
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // TEST 8: PresidentialPardonForm - Grade Too Low to Execute

    printSeparator("TEST 8: PresidentialPardonForm - TOO LOW TO EXECUTE");

    try {
        Bureaucrat signer("HighSigner", 25);   // Peut signer
        Bureaucrat executor("MidExecutor", 10); // Ne peut PAS exécuter (5)
        PresidentialPardonForm pardon3("Ford Prefect");
        
        signer.signForm(pardon3);
        executor.executeForm(pardon3);  // Devrait échouer
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // TEST 9: Tous les formulaires avec un super bureaucrate

    printSeparator("TEST 9: SUPER BUREAUCRAT - ALL FORMS");

    try {
        Bureaucrat superBureaucrat("SuperBoss", 1);
        ShrubberyCreationForm shrub("park");
        RobotomyRequestForm robot("C3PO");
        PresidentialPardonForm pardon("Marvin");
        
        std::cout << superBureaucrat << std::endl << std::endl;
        
        // Shrubbery
        std::cout << "--- Shrubbery ---" << std::endl;
        superBureaucrat.signForm(shrub);
        superBureaucrat.executeForm(shrub);
        
        // Robotomy
        std::cout << "\n--- Robotomy ---" << std::endl;
        superBureaucrat.signForm(robot);
        superBureaucrat.executeForm(robot);
        
        //presidential
        std::cout << "\n--- Presidential Pardon ---" << std::endl;
        superBureaucrat.signForm(pardon);
        superBureaucrat.executeForm(pardon);
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "\n========================================" << std::endl;
    std::cout << "  ALL TESTS COMPLETED!" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    return 0;
}

