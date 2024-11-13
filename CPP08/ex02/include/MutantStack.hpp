/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:18:44 by flfische          #+#    #+#             */
/*   Updated: 2024/11/13 22:39:53 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack &operator=(const MutantStack &other);
		virtual ~MutantStack();

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();

		typedef typename std::stack<T>::container_type::const_iterator
			const_iterator;
		const_iterator begin() const;
		const_iterator end() const;
};
