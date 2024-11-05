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

class Bureaucrat;

class AForm
{
	private:
		AForm() = delete;
		std::string const _name;
		std::string _target;
		bool _signed = false;
		int const _gradeToSign;
		int const _gradeToExecute;

	public:
		AForm(std::string const name, int gradeToSign, int gradeToExecute);
		AForm(AForm const &other);
		virtual ~AForm() = default;
		AForm &operator=(AForm const &other);

		[[nodiscard]] std::string const &getName() const;
		[[nodiscard]] bool getSigned() const;
		[[nodiscard]] int getGradeToSign() const;
		[[nodiscard]] int getGradeToExecute() const;
		[[nodiscard]] std::string const &getTarget() const;

		void setTarget(std::string const &target);

		void beSigned(Bureaucrat const &bureaucrat);

		void execute(Bureaucrat const &executor) const;
		virtual void executeAction(Bureaucrat const &executor) const = 0;

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

		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw() override;
		};
};

std::ostream &operator<<(std::ostream &out, AForm const &form);
