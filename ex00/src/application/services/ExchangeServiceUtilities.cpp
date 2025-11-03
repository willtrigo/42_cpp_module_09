/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExchangeServiceUtilities.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:28:10 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/03 00:13:20 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "application/services/ExchangeService.hpp"
#include "domain/entities/BitcoinExchange.hpp"

#include <stdexcept>
#include <string>

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
