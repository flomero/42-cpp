/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:54:07 by flfische          #+#    #+#             */
/*   Updated: 2024/11/05 20:20:31 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
	for (int i = 0; i < 3; i++)
	{
		if (formName == _formNames[i])
		{
			std::cout << "Intern creates " << formName << " form" << std::endl;
			return _formCreators[i](target);
		}
	}
	std::cerr << "Intern can't create " << formName << " form" << std::endl;
	return nullptr;
}

AForm *Intern::createPresidentialPardonForm(std::string const &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::createRobotomyRequestForm(std::string const &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createShrubberyCreationForm(std::string const &target)
{
	return new ShrubberyCreationForm(target);
}
