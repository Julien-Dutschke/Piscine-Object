/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutschk <jdutschk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:27:36 by jdutschk          #+#    #+#             */
/*   Updated: 2024/03/18 17:05:56 by jdutschk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bank.hpp"
#include "Account.hpp"

int main()
{
	Account accountA = Account(100);
	//! accountA.id = 0; && accountA.value = 100;

	Account accountB = Account(100);
	// ! accountB.id = 1; && accountB.value = 100;

	Bank bank = Bank();
	bank.setLiquidity(1000);
	bank.addAccount(&accountA);
	bank.addAccount(&accountB);
	
	bank.addAccountValue(&accountA, 100);



	std::cout << "Account : " << std::endl;
	std::cout << accountA << std::endl;
	std::cout << accountB << std::endl;

	std::cout << " ----- " << std::endl;

	std::cout << "Bank : " << std::endl;
	std::cout << bank << std::endl;

	return (0);
}
