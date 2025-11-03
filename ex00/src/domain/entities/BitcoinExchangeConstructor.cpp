/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchangeConstructor.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:55:54 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/02 23:08:25 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/entities/BitcoinExchange.hpp"

#include <string>

BitcoinExchange::BitcoinExchange(const std::string& date, double value)
    : m_date(date), m_value(value) {
  validateDate();
  validateValue();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : m_date(other.m_date), m_value(other.m_value) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
  if (this != &other) {
    this->m_date = other.m_date;
    this->m_value = other.m_value;
  }
  return *this;
}
