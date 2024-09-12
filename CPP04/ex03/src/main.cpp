/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:36:57 by flfische          #+#    #+#             */
/*   Updated: 2024/09/12 16:10:13 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter *me = new Character("me");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	std::cout << "----- additional tests -----" << std::endl;
	IMateriaSource *src2 = new MateriaSource();
	src2->learnMateria(new Ice());
	src2->learnMateria(new Ice());
	src2->learnMateria(new Ice());
	src2->learnMateria(new Ice());
	ICharacter *tim = new Character("tim");
	ICharacter *tom = new Character("tom");
	AMateria *tmp2;
	tmp2 = src2->createMateria("cure");
	tim->equip(tmp2);
	tim->use(0, *tom);
	tmp2 = src2->createMateria("ice");
	tim->equip(tmp2);
	tim->use(0, *tom);
	delete tim;
	delete tom;
	delete src2;
	return 0;
}
