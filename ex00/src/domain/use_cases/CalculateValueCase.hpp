/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CalculateValueCase.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:44:29 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/03 11:48:46 by dande-je         ###   ########.fr       */
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

  void execute(const std::string& inputFilePath) const;

 private:
  const ExchangeService& m_service;

  void parseAndProcessLine(const std::string& line) const;
  std::pair<std::string, double> parseLine(const std::string& line) const;
};

#endif  // CALCULATE_VALUE_USE_CASE_HPP
