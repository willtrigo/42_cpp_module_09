/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExchangeService.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:18:23 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/02 22:27:26 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCHANGE_SERVICE_HPP
#define EXCHANGE_SERVICE_HPP

#include "domain/repositories/IBitcoinRepository.hpp"

#include <string>

class ExchangeService {
 public:
  ExchangeService(const IBitcoinRepository& repository);
  ExchangeService(const ExchangeService& other);
  ~ExchangeService();

  ExchangeService& operator=(const ExchangeService&);

  double calculateExchangeValue(const std::string& date, double value) const;

 private:
  const IBitcoinRepository& m_repository;
};

#endif  // EXCHANGE_SERVICE_HPP
