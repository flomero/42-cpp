/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:18:12 by flfische          #+#    #+#             */
/*   Updated: 2024/11/05 15:24:33 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat;

class Form
{
	private:
		Form() = delete;
		std::string const _name;
		bool _signed = false;
		int const _gradeToSign;
		int const _gradeToExecute;

	public:
		Form(std::string const name, int gradeToSign, int gradeToExecute);
		Form(Form const &other);
		~Form() = default;
		Form &operator=(Form const &other);

		[[nodiscard]] std::string const &getName() const;
		[[nodiscard]] bool getSigned() const;
		[[nodiscard]] int getGradeToSign() const;
		[[nodiscard]] int getGradeToExecute() const;

		void beSigned(Bureaucrat const &bureaucrat);

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

std::ostream &operator<<(std::ostream &out, Form const &form);
