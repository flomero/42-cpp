/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:46:48 by flfische          #+#    #+#             */
/*   Updated: 2024/11/05 12:24:20 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <fstream>

#pragma region Constructors etc.
ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
	: AForm(other), _target(other._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
	ShrubberyCreationForm const &other)
{
	if (this != &other)
	{
		_target = other._target;
	}
	return (*this);
}
#pragma endregion

#pragma region Getters
std::string const &ShrubberyCreationForm::getTarget() const
{
	return _target;
}
#pragma endregion

#pragma region Member functions
void ShrubberyCreationForm::executeAction(Bureaucrat const &executor) const
{
	(void)executor;
	std::ofstream file(_target + "_shrubbery");
	if (!file.is_open())
		throw std::runtime_error("Could not open file for writing");
	file << "      /\\      " << std::endl;
	file << "     /\\*\\     " << std::endl;
	file << "    /\\O\\*\\    " << std::endl;
	file << "   /*/\\/\\/\\   " << std::endl;
	file << "  /\\O\\/\\*\\/\\  " << std::endl;
	file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	file << "/\\O\\/\\/*/\\/O/\\" << std ::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file << std::endl;
}
#pragma endregion