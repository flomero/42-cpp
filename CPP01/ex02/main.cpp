/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 21:28:35 by flfische          #+#    #+#             */
/*   Updated: 2024/07/30 17:57:15 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	std::cout << "Adresses:\n"
			  << "	- String:	" << &str << "\n"
			  << "	- StringPTR:	" << stringPTR << "\n"
			  << "	- StringREF:	" << &stringREF << "\n"
			  << "Values:\n"
			  << "\t- String:\t" << str << "\n"
			  << "\t- StringPTR:\t" << *stringPTR << "\n"
			  << "\t- StringREF:\t" << stringREF << std::endl;
	return (0);
}
