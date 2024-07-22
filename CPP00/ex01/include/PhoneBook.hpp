/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:41:31 by flfische          #+#    #+#             */
/*   Updated: 2024/07/22 15:12:57 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	size_t contact_count;
	void check_input(const std::string &prompt,
		bool (Contact::*setter)(const std::string), Contact &contact);
public:
	PhoneBook();
	void add_contact();
	void search_contact();
};
