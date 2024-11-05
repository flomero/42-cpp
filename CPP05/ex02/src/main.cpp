/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 22:56:08 by flfische          #+#    #+#             */
/*   Updated: 2024/11/05 12:56:11 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat bureaucrat("Bureaucrat", 1);
	ShrubberyCreationForm shrubberyCreationForm("home");
	RobotomyRequestForm robotomyRequestForm("R2D2");

	robotomyRequestForm.beSigned(bureaucrat);
	robotomyRequestForm.execute(bureaucrat);

	return 0;
}