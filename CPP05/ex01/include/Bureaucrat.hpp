/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 22:55:59 by flfische          #+#    #+#             */
/*   Updated: 2024/11/05 15:24:43 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Form;

class Bureaucrat
{
	private:
		Bureaucrat() = delete;
		std::string const _name;
		int _grade;
		void setGrade(int grade);

	public:
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &other);
		~Bureaucrat() = default;
		Bureaucrat &operator=(Bureaucrat const &other);

		[[nodiscard]] std::string const &getName() const;
		[[nodiscard]] int getGrade() const;

		void incrementGrade();
		void decrementGrade();
		void signForm(Form &form) const;

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

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);
