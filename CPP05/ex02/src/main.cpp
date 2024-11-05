/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 22:56:08 by flfische          #+#    #+#             */
/*   Updated: 2024/11/05 15:06:52 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat bureaucrat("Bureaucrat", 45);
		ShrubberyCreationForm shrubberyCreationForm("home");
		RobotomyRequestForm robotomyRequestForm("R2D2");

		bureaucrat.signForm(shrubberyCreationForm);
		std::cout << robotomyRequestForm;

		bureaucrat.executeForm(shrubberyCreationForm);
		std::cout << robotomyRequestForm;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}