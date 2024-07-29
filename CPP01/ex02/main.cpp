/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 21:28:35 by flfische          #+#    #+#             */
/*   Updated: 2024/07/29 21:35:21 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	std::cout << "Adresses:" << std::endl;
	std::cout << "\t- String:\t" << &str << std::endl;
	std::cout << "\t- StringPTR:\t" << stringPTR << std::endl;
	std::cout << "\t- StringREF:\t" << &stringREF << std::endl;
	std::cout << "Values:" << std::endl;
	std::cout << "\t- String:\t" << str << std::endl;
	std::cout << "\t- StringPTR:\t" << *stringPTR << std::endl;
	std::cout << "\t- StringREF:\t" << stringREF << std::endl;
	return (0);
}