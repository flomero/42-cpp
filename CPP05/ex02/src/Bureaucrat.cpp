/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 22:56:04 by flfische          #+#    #+#             */
/*   Updated: 2024/11/05 15:16:45 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include "AForm.hpp"

#pragma region Constructors etc
Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	setGrade(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
	: _name(other._name), _grade(other._grade)
{
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this != &other)
		setGrade(other._grade);
	return *this;
}
#pragma endregion

#pragma region Setters
void Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}
#pragma endregion

#pragma region Getters
int Bureaucrat::getGrade() const
{
	return _grade;
}

std::string const &Bureaucrat::getName() const
{
	return _name;
}
#pragma endregion

#pragma region Member functions
void Bureaucrat::incrementGrade()
{
	setGrade(_grade - 1);
}

void Bureaucrat::decrementGrade()
{
	setGrade(_grade + 1);
}

void Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signed " << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << *this << " cannot sign " << form << " because " << e.what()
				  << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << *this << " executes " << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << *this << " cannot execute " << form << " because "
				  << e.what() << std::endl;
	}
}
#pragma endregion

#pragma region Ostream
std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade "
		<< bureaucrat.getGrade();
	return out;
}
#pragma endregion

#pragma region Exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}
#pragma endregion
