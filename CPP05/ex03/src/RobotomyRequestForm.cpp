/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:41:58 by flfische          #+#    #+#             */
/*   Updated: 2024/11/05 14:40:21 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#pragma region Constructors etc
RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45)
{
	setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	: AForm(copy)
{
	setTarget(copy.getTarget());
}

RobotomyRequestForm &RobotomyRequestForm::operator=(
	const RobotomyRequestForm &assign)
{
	if (this != &assign)
	{
		AForm::operator=(assign);
	}
	return (*this);
}
#pragma endregion

#pragma region Member functions
void RobotomyRequestForm::executeAction(Bureaucrat const &executor) const
{
	(void)executor;
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::cout << "*drilling noises* ";
	if (std::rand() % 2)
		std::cout << getTarget() << " has been robotomized successfully"
				  << std::endl;
	else
		std::cout << getTarget() << " robotomization failed" << std::endl;
}
#pragma endregion
