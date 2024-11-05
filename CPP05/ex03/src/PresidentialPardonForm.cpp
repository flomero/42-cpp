/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:11:22 by flfische          #+#    #+#             */
/*   Updated: 2024/11/05 15:30:26 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#pragma region Constructors etc
PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5)
{
	AForm::setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm &copy)
	: AForm(copy)
{
	AForm::setTarget(copy.getTarget());
}

PresidentialPardonForm &PresidentialPardonForm::operator=(
	const PresidentialPardonForm &assign)
{
	if (this != &assign)
	{
		AForm::operator=(assign);
	}
	return (*this);
}
#pragma endregion

#pragma region Member functions
void PresidentialPardonForm::executeAction(Bureaucrat const &executor) const
{
	(void)executor;
	std::cout << AForm::getTarget() << " has been pardoned by Zaphod Beeblebrox"
			  << std::endl;
}
#pragma endregion