/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 22:56:08 by flfische          #+#    #+#             */
/*   Updated: 2024/09/21 14:13:02 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		std::cout << "-------------------" << std::endl;
		Bureaucrat bureaucrat("Bureaucrat", 1);
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
}