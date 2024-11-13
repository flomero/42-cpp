/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:18:54 by flfische          #+#    #+#             */
/*   Updated: 2024/11/13 22:43:14 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>

#include "MutantStack.tpp"

#define CYAN "\033[36m"
#define RESET "\033[0m"
#define HEADER(X) std::cout << CYAN << X << RESET << std::endl

void subjectTest()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void listTest()
{
	std::list<int> mstack;

	mstack.push_back(5);
	mstack.push_back(17);

	std::cout << mstack.back() << std::endl;

	mstack.pop_back();

	std::cout << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(mstack);
}

void testConstIterators()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	MutantStack<int>::const_iterator it = mstack.begin();
	MutantStack<int>::const_iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

int main()
{
	HEADER("MutantStack");
	subjectTest();
	HEADER("----------------");
	HEADER("std::list");
	listTest();
	HEADER("----------------");
	HEADER("Const iterators");
	testConstIterators();
	return 0;
}