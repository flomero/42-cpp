/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:18:12 by flfische          #+#    #+#             */
/*   Updated: 2024/09/22 10:29:06 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	Form() = default;
	std::string const _name;
	bool _signed = false;
	int const _gradeToSign;
	int const _gradeToExecute;

public:
	Form(std::string const name, int gradeToSign, int gradeToExecute);
	Form(Form const &other);
	~Form() = default;
	Form &operator=(Form const &other);

	std::string const &getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

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
