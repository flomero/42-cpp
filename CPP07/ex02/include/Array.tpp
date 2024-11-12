/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:27:58 by flfische          #+#    #+#             */
/*   Updated: 2024/11/12 09:29:16 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _arr(nullptr), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]), _size(n)
{
}

template <typename T>
Array<T>::Array(const Array<T>& src) : _arr(new T[src._size]), _size(src._size)
{
	for (unsigned int i = 0; i < _size; i++) _arr[i] = src._arr[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] _arr;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& src)
{
	if (this == &src)
		return *this;

	delete[] _arr;
	_arr = new T[src._size];
	_size = src._size;

	for (unsigned int i = 0; i < _size; i++) _arr[i] = src._arr[i];

	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
	if (i >= _size)
		throw OutOfBoundsException();

	return _arr[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return "Array index out of bounds";
}