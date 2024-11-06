/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 22:56:08 by flfische          #+#    #+#             */
/*   Updated: 2024/11/06 10:38:41 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		std::cout << "-------------------" << std::endl;
		Bureaucrat bureaucrat("Bureaucrat", 1);
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "-------------------" << std::endl;
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "-------------------" << std::endl;
		Bureaucrat bureaucrat("Bureaucrat", 150);
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "-------------------" << std::endl;
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "-------------------" << std::endl;
		Bureaucrat bureaucrat("Bureaucrat", 0);
		std::cout << bureaucrat << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "-------------------" << std::endl;
		std::cerr << e.what() << std::endl;
	}
}