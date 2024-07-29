/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:30:42 by flfische          #+#    #+#             */
/*   Updated: 2024/07/29 23:25:11 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
private:
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;
public:
	Contact();
	~Contact();
	bool set_first_name(const std::string first_name);
	std::string get_first_name();
	bool set_last_name(const std::string last_name);
	std::string get_last_name();
	bool set_nickname(const std::string nickname);
	std::string get_nickname();
	bool set_phone_number(const std::string phone_number);
	std::string get_phone_number();
	bool set_darkest_secret(const std::string darkest_secret);
	std::string get_darkest_secret();
	void print_contact();
};

#endif
