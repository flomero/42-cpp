/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:41:31 by flfische          #+#    #+#             */
/*   Updated: 2024/07/31 15:12:28 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Contact.hpp"

#ifndef PHONEBOOK_SIZE
#define PHONEBOOK_SIZE 8
#endif

class PhoneBook
{
private:
	Contact *contacts[PHONEBOOK_SIZE];
	size_t contact_count;
	size_t index;
	void check_input(const std::string &prompt,
					 bool (Contact::*setter)(const std::string), Contact *contact);

public:
	PhoneBook();
	~PhoneBook();
	void add_contact();
	void search_contact();
	void free_and_exit();
};
