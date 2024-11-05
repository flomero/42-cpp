/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:18:18 by flfische          #+#    #+#             */
/*   Updated: 2024/11/05 15:18:12 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include "Bureaucrat.hpp"

#pragma region Constructors etc
AForm::AForm(std::string const name, int gradeToSign, int gradeToExecute)
	: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	_signed = false;
}

AForm::AForm(AForm const &other)
	: _name(other._name),
	  _gradeToSign(other._gradeToSign),
	  _gradeToExecute(other._gradeToExecute)
{
	_signed = other._signed;
	_target = other._target;
}

AForm &AForm::operator=(AForm const &other)
{
	if (this == &other)
		return *this;
	_signed = other._signed;
	_target = other._target;
	return *this;
}
#pragma endregion

#pragma region Getters
bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

std::string const &AForm::getName() const
{
	return _name;
}

std::string const &AForm::getTarget() const
{
	return _target;
}
#pragma endregion

#pragma region Setters
void AForm::setTarget(std::string const &target)
{
	_target = target;
}
#pragma endregion

#pragma region Member functions
void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!_signed)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw AForm::GradeTooLowException();
	executeAction(executor);
}
#pragma endregion

#pragma region Exceptions
const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high.";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed.";
}
#pragma endregion

#pragma region Ostream
std::ostream &operator<<(std::ostream &out, AForm const &form)
{
	out << "Form " << form.getName()
		<< " (S: " << (form.getSigned() ? "✅" : "❌")
		<< ", GS: " << form.getGradeToSign()
		<< ", GE: " << form.getGradeToExecute()
		<< ", T: " << (form.getTarget().empty() ? "none" : form.getTarget())
		<< ")";
	return out;
}
#pragma endregion