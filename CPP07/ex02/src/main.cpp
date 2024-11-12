/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:53:55 by flfische          #+#    #+#             */
/*   Updated: 2024/11/12 09:43:36 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Array.tpp"

#define CYAN "\033[36m"
#define RESET "\033[0m"
#define HEADER(X) std::cout << CYAN << X << RESET << std::endl

template <typename T>
void printArray(Array<T>& arr)
{
	std::cout << "Size:\t\t" << arr.size() << std::endl;
	std::cout << "Content:\t";
	for (unsigned int i = 0; i < arr.size(); i++) std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main()
{
	Array<int> arr(5);

	for (unsigned int i = 0; i < arr.size(); i++) arr[i] = i;

	HEADER("Array 1:");
	printArray(arr);

	Array<int> arr2(arr);

	HEADER("Array 2 - Copy Constructed of Array 1:");
	printArray(arr2);

	Array<int> arr3;
	arr3 = arr2;
	arr2[0] = 42;

	HEADER("Array 3 - Copy Assigned of Array 2:");
	printArray(arr3);

	HEADER("Array 2 - Modified:");
	printArray(arr2);

	HEADER("Exception:");
	try
	{
		std::cout << arr[10] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	Array<int> arr4;
	HEADER("Array 4 - Default Constructed (Size 0):");
	printArray(arr4);

	return 0;
}