/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CalculateValueCase.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:44:29 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/03 20:55:23 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCULATE_VALUE_USE_CASE_HPP
#define CALCULATE_VALUE_USE_CASE_HPP

#include "application/services/ExchangeService.hpp"

#include <string>
#include <utility>

class CalculateValueUseCase {
 public:
  CalculateValueUseCase(const ExchangeService& service);
  CalculateValueUseCase(const CalculateValueUseCase& other);
  ~CalculateValueUseCase();

  CalculateValueUseCase& operator=(const CalculateValueUseCase& other);

  std::string parseAndProcessLine(const std::string& line) const;

 private:
  const ExchangeService& m_service;

  static std::pair<std::string, double> parseLine(const std::string& line);
  static void strTrim(std::string& str);

  static const double MAX_VALUE;
};

#endif  // CALCULATE_VALUE_USE_CASE_HPP
