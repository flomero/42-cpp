/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 23:05:26 by flfische          #+#    #+#             */
/*   Updated: 2024/07/29 23:09:54 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>

class Replace
{
public:
	Replace(std::string filename, std::string str1, std::string str2);
	~Replace();
	void replace();

private:
	std::string _filename;
	std::string _str1;
	std::string _str2;
};
