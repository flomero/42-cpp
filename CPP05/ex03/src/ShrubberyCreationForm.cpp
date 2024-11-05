/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:46:48 by flfische          #+#    #+#             */
/*   Updated: 2024/11/05 14:41:07 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <fstream>

#pragma region Constructors etc.
ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
	: AForm("ShrubberyCreationForm", 145, 137)
{
	setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
	: AForm(other)
{
	setTarget(other.getTarget());
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
	ShrubberyCreationForm const &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}
#pragma endregion

#pragma region Member functions
void ShrubberyCreationForm::executeAction(Bureaucrat const &executor) const
{
	(void)executor;
	std::ofstream file(getTarget() + "_shrubbery");
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