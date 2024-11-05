/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:18:18 by flfische          #+#    #+#             */
/*   Updated: 2024/11/05 15:19:13 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include "Bureaucrat.hpp"

#pragma region Constructors etc
Form::Form(std::string const name, int gradeToSign, int gradeToExecute)
	: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	_signed = false;
}

Form::Form(Form const &other)
	: _name(other._name),
	  _gradeToSign(other._gradeToSign),
	  _gradeToExecute(other._gradeToExecute)
{
	_signed = other._signed;
}

Form &Form::operator=(Form const &other)
{
	if (this == &other)
		return *this;
	_signed = other._signed;
	return *this;
}
#pragma endregion

#pragma region Getters
bool Form::getSigned() const
{
	return _signed;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

std::string const &Form::getName() const
{
	return _name;
}
#pragma endregion

#pragma region Member functions
void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}
#pragma endregion

#pragma region Exceptions
const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high.";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}
#pragma endregion

#pragma region Ostream
std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << "Form " << form.getName()
		<< " (S: " << (form.getSigned() ? "✅" : "❌")
		<< ", GS: " << form.getGradeToSign()
		<< ", GE: " << form.getGradeToExecute() << ")";
	return out;
}
#pragma endregion