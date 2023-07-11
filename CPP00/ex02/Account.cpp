/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourdon <abourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 13:23:31 by abourdon          #+#    #+#             */
/*   Updated: 2023/06/30 15:11:07 by abourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*.hpp*/
#include "Account.hpp"

/*std::*/
#include <iostream>

/*void	Account::_displayTimestamp(void)*/
#include <ctime>


//init static int en private(obliger séparément des autres int car static)
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//tt les fonctions de "get"
int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

/*Contructeur Account, Permet d'afficher la partie "create"
init les int de la classe, incremente nbAccount, totalAmount et print le timestamp*/
Account::Account(int initial_deposit) : _accountIndex(Account::_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

/*Destructeur Account, permet d'afficher la partie "close"
Print le timestamp, et affiche les autres infos (fin de l'affichage)*/
Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
	return ;
}

/*Permet d'afficher le timestamp
https://cplusplus.com/reference/ctime/time/?kw=time
*/
void	Account::_displayTimestamp(void)
{
	time_t		t_ptr;//sert a stocker le nb de seconde depuis 1970
	struct tm	*y2k;//structure de type tm pour stocker les infos

	std::time(&t_ptr);//stock ds t_ptr le nb de secondes
	y2k = localtime(&t_ptr);//localtime permet de convertir le nombre de secondes ds la structure y2k
	std::cout << "[";
	std::cout << y2k->tm_year + 1900;//print l'annee donc 123 + 1900 pour 2023
	std::cout << y2k->tm_mon + 1;//print le moi (start a 0 donc + 1)
	std::cout << y2k->tm_mday << "_";//print le jour
	std::cout << y2k->tm_hour;//print l'heure
	std::cout << y2k->tm_min;//print minute
	std::cout << y2k->tm_sec;//print seconde
	std::cout <<"] ";
}

/*sers juste a check si la valeure est negative, const car on modifie par la variable*/
int Account::checkAmount(void) const
{
	if (this->_amount < 0)
		return (1);
	return (0);
}

/*Print amount, deposite et amount + le depot effectue + le nb de depot*/
void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";//print l'index
	std::cout << "p_amount:" << this->_amount << ";";//print p_amount

	this->_amount += deposit;//incremente amount avec le depot pour cette instance
	this->_nbDeposits++;//incremente le nb de depots pour cette instance
	Account::_totalAmount += deposit;//increment pour le total avec le depot
	Account::_totalNbDeposits++;//increment le nb total de depots

	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

/*calcule et print les retraits*/
bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";//print index
	std::cout << "p_amount:" << this->_amount << ";";//print p_amount

	this->_amount -= withdrawal;//decremente retraits pour l'instance
	if (Account::checkAmount() == 1)
	{
		this->_amount += withdrawal;//si amount nefatif ==> print refused et return
		std::cout << "withdrawal:refused" << std::endl;
		return (1);
	}
	Account::_totalAmount -= withdrawal;//decremente le total des retraits
	this->_nbWithdrawals++;//increment le nb de retrait pr l'instance
	Account::_totalNbWithdrawals++;//increment le nb de retraits total
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (0);
}

/*print le total des amount, le nb de deposits et le nb de withdrawals(retraits) grace aux fonctions get*/
void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

/*print le status*/
void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";  
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}
