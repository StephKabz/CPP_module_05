/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingstephane <kingstephane@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:32:56 by kingstephan       #+#    #+#             */
/*   Updated: 2026/03/07 18:10:57 by kingstephan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <ctime>
#include <cstdlib>

void printSeparator(std::string title) {
    std::cout << "\n========================================" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "========================================\n" << std::endl;
}

int main() {
    srand(time(NULL));
    
    // ========================================
    // TEST 1: TEST DU SUJET (exemple officiel)
    // ========================================
    printSeparator("TEST 1: Subject Example");
    {
        Intern someRandomIntern;
        AForm* rrf;
        
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        
        if (rrf) {
            std::cout << *rrf << std::endl << std::endl;
            
            Bureaucrat bob("Bob", 1);  // Super bureaucrat
            bob.signForm(*rrf);
            bob.executeForm(*rrf);
            
            delete rrf;
        }
    }
    
    // ========================================
    // TEST 2: Tous les formulaires valides
    // ========================================
    printSeparator("TEST 2: All Valid Forms");
    {
        Intern intern;
        Bureaucrat boss("Boss", 1);  // Can do everything
        
        std::cout << "--- Creating Shrubbery Form ---" << std::endl;
        AForm* shrub = intern.makeForm("shrubbery creation", "home");
        if (shrub) {
            boss.signForm(*shrub);
            boss.executeForm(*shrub);
            std::cout << "Check file: home_shrubbery" << std::endl;
            delete shrub;
        }
        
        std::cout << "\n--- Creating Robotomy Form ---" << std::endl;
        AForm* robot = intern.makeForm("robotomy request", "R2D2");
        if (robot) {
            boss.signForm(*robot);
            boss.executeForm(*robot);
            delete robot;
        }
        
        std::cout << "\n--- Creating Presidential Pardon Form ---" << std::endl;
        AForm* pardon = intern.makeForm("presidential pardon", "Arthur Dent");
        if (pardon) {
            boss.signForm(*pardon);
            boss.executeForm(*pardon);
            delete pardon;
        }
    }
    
    // ========================================
    // TEST 3: Formulaires invalides
    // ========================================
    printSeparator("TEST 3: Invalid Form Names");
    {
        Intern intern;
        AForm* form;
        
        std::cout << "Trying: 'unknown form'" << std::endl;
        form = intern.makeForm("unknown form", "target");
        if (form == NULL) {
            std::cout << "-> Form is NULL (correct behavior)\n" << std::endl;
        }
        
        std::cout << "Trying: 'Robotomy Request' (wrong case)" << std::endl;
        form = intern.makeForm("Robotomy Request", "target");
        if (form == NULL) {
            std::cout << "-> Form is NULL (correct behavior)\n" << std::endl;
        }
        
        std::cout << "Trying: 'robotomy' (incomplete name)" << std::endl;
        form = intern.makeForm("robotomy", "target");
        if (form == NULL) {
            std::cout << "-> Form is NULL (correct behavior)\n" << std::endl;
        }
        
        std::cout << "Trying: 'coffee making' (doesn't exist)" << std::endl;
        form = intern.makeForm("coffee making", "office");
        if (form == NULL) {
            std::cout << "-> Form is NULL (correct behavior)" << std::endl;
        }
    }
    
    std::cout << "\n========================================" << std::endl;
    std::cout << "  ALL TESTS COMPLETED!" << std::endl;
    std::cout << "  Run with valgrind to check leaks" << std::endl;
    std::cout << "========================================\n" << std::endl;
    
    return 0;
}

