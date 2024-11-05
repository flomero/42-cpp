/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:53:58 by flfische          #+#    #+#             */
/*   Updated: 2024/11/05 20:18:07 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class AForm;
typedef AForm *(*FormCreator)(std::string const &);

class Intern
{
	private:
		static AForm *createPresidentialPardonForm(std::string const &target);
		static AForm *createRobotomyRequestForm(std::string const &target);
		static AForm *createShrubberyCreationForm(std::string const &target);

		FormCreator _formCreators[3] = {&Intern::createPresidentialPardonForm,
										&Intern::createRobotomyRequestForm,
										&Intern::createShrubberyCreationForm};

		std::string _formNames[3] = {"presidential pardon", "robotomy request",
									 "shrubbery creation"};

	public:
		Intern() = default;
		~Intern() = default;
		Intern(Intern const &other) = default;
		Intern &operator=(Intern const &other) = default;

		AForm *makeForm(std::string const &formName, std::string const &target);
};
