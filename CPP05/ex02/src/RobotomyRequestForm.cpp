/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:41:58 by flfische          #+#    #+#             */
/*   Updated: 2024/11/05 13:09:13 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#pragma region Constructors etc
RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	: AForm(copy), _target(copy._target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(
	const RobotomyRequestForm &assign)
{
	if (this != &assign)
	{
		_target = assign._target;
	}
	return (*this);
}
#pragma endregion

#pragma region Getters
std::string const &RobotomyRequestForm::getTarget() const
{
	return _target;
}
#pragma endregion

#pragma region Member functions
void RobotomyRequestForm::executeAction(Bureaucrat const &executor) const
{
	(void)executor;
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::cout << "*drilling noises* ";
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully"
				  << std::endl;
	else
		std::cout << _target << " robotomization failed" << std::endl;
}
#pragma endregion
