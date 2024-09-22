/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 22:56:08 by flfische          #+#    #+#             */
/*   Updated: 2024/09/22 10:40:44 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat bureaucrat("Bureaucrat", 150);
		std::cout << bureaucrat << std::endl;
		Form form("Form", 150, 150);
		std::cout << form << std::endl;
		form.beSigned(bureaucrat);
		std::cout << form << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}