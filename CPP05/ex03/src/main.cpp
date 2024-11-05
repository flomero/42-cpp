/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 22:56:08 by flfische          #+#    #+#             */
/*   Updated: 2024/11/05 15:29:53 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	{
		try
		{
			Bureaucrat bureaucrat("Bureaucrat", 45);
			ShrubberyCreationForm shrubberyCreationForm("home");

			bureaucrat.signForm(shrubberyCreationForm);

			bureaucrat.executeForm(shrubberyCreationForm);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat bureaucrat("Bureaucrat", 45);
			RobotomyRequestForm robotomyRequestForm("home");

			bureaucrat.signForm(robotomyRequestForm);

			bureaucrat.executeForm(robotomyRequestForm);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat bureaucrat("Bureaucrat", 150);
			RobotomyRequestForm robotomyRequestForm("home");

			bureaucrat.signForm(robotomyRequestForm);

			bureaucrat.executeForm(robotomyRequestForm);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat bureaucrat("Bureaucrat", 5);
			PresidentialPardonForm presidentialPardonForm("C3PO");

			bureaucrat.signForm(presidentialPardonForm);

			bureaucrat.executeForm(presidentialPardonForm);

			bureaucrat.incrementGrade();
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}