/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:18:12 by flfische          #+#    #+#             */
/*   Updated: 2024/10/12 16:42:21 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		AForm() = default;
		std::string const _name;
		bool _signed = false;
		int const _gradeToSign;
		int const _gradeToExecute;

	public:
		AForm(std::string const name, int gradeToSign, int gradeToExecute);
		AForm(AForm const &other);
		~AForm() = default;
		AForm &operator=(AForm const &other);

		std::string const &getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(Bureaucrat const &bureaucrat);

		virtual void execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw() override;
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw() override;
		};
};

std::ostream &operator<<(std::ostream &out, AForm const &AForm);
