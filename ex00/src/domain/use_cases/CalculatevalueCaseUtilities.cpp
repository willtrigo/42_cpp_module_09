/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CalculatevalueCaseUtilities.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:59:37 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/03 20:22:51 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/use_cases/CalculateValueCase.hpp"
#include <iomanip>
#include <string>
#include <sstream>
#include <utility>
#include <stdexcept>

std::string CalculateValueUseCase::parseAndProcessLine(const std::string& line) const {
  std::pair<std::string, double> parsed = parseLine(line);
  double result = this->m_service.calculateExchangeValue(parsed.first, parsed.second);
  std::ostringstream str;

  str << parsed.first << " => " << parsed.second << " = ";
  str << std::fixed << std::setprecision(2) << result;

  return str.str();
}

std::pair<std::string, double> CalculateValueUseCase::parseLine(const std::string& line) const {
  std::size_t pipePos = line.find('|');
  if (pipePos == std::string::npos) {
    throw std::invalid_argument("bad input => ", line);
  }

  std::string dateStr = line.substr(0, pipePos);
  std::string valueStr = line.substr(pipePos + 1);

  strTrim(dateStr);
  strTrim(valueStr);
}

void CalculateValueUseCase::strTrim(std::string& str) {
  std::size_t firstNonSpace = str.find_first_not_of(" \t");
  if (firstNonSpace != std::string::npos) {
    str.erase(0, firstNonSpace);
  }

  std::size_t lastNonSpace = str.find_last_not_of(" \t");
  if (lastNonSpace != std::string::npos) {
    str.erase(lastNonSpace + 1);
  }
}
