/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 22:56:08 by flfische          #+#    #+#             */
/*   Updated: 2024/11/06 10:48:49 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		Bureaucrat bureaucrat("Bureaucrat", 1);
		bureaucrat.signForm(*rrf);
		bureaucrat.executeForm(*rrf);

		delete rrf;
	}
	std::cout << "_________________________" << std::endl;
	{
		Intern someRandomIntern;
		AForm* ppf;
		ppf = someRandomIntern.makeForm("presidential pardon", "Bender");

		Bureaucrat bureaucrat("Bureaucrat", 1);
		bureaucrat.signForm(*ppf);
		bureaucrat.executeForm(*ppf);

		delete ppf;
	}
	std::cout << "_________________________" << std::endl;
	{
		Intern someRandomIntern;
		AForm* scf;
		scf = someRandomIntern.makeForm("shrubbery creation", "Bender");

		Bureaucrat bureaucrat("Bureaucrat", 1);
		bureaucrat.signForm(*scf);
		bureaucrat.executeForm(*scf);

		delete scf;
	}
}