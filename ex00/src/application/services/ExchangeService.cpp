/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExchangeService.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:24:34 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/10 18:53:02 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "application/services/ExchangeService.hpp"
#include "domain/entities/BitcoinExchange.hpp"
#include "domain/repositories/IBitcoinRepository.hpp"

#include <stdexcept>
#include <string>

ExchangeService::ExchangeService(const IBitcoinRepository& repository)
    : m_repository(repository) {}

ExchangeService::ExchangeService(const ExchangeService& other)
    : m_repository(other.m_repository) {}

ExchangeService::~ExchangeService() {}

ExchangeService& ExchangeService::operator=(const ExchangeService& /*unused*/) {
  return *this;
}

double ExchangeService::calculateExchangeValue(const std::string& date,
                                               double value) const {
  if (!BitcoinExchange::isValidDate(date)) {
    throw std::invalid_argument("bad input => " + date);
  }

  if (!BitcoinExchange::isValidValue(value)) {
    if (value < 0.0) {
      throw std::invalid_argument("not a positive number.");
    }
    throw std::invalid_argument("too large a number.");
  }

  double price = this->m_repository.getPrice(date);
  return value * price;
}
