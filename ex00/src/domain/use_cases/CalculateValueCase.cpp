/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CalculateValueCase.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:51:42 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/10 18:52:57 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "application/services/ExchangeService.hpp"
#include "domain/use_cases/CalculateValueCase.hpp"

#include <sstream>
#include <string>

const double CalculateValueUseCase::MAX_VALUE = 1000.0;

CalculateValueUseCase::CalculateValueUseCase(const ExchangeService& service)
    : m_service(service) {}

CalculateValueUseCase::CalculateValueUseCase(const CalculateValueUseCase& other)
    : m_service(other.m_service) {}

CalculateValueUseCase::~CalculateValueUseCase() {}

CalculateValueUseCase& CalculateValueUseCase::operator=(
    const CalculateValueUseCase& other) {
  if (this != &other) {
    const_cast<ExchangeService&>(this->m_service) = other.m_service;
  }
  return *this;
}

std::string CalculateValueUseCase::parseAndProcessLine(
    const std::string& line) const {
  std::pair<std::string, double> parsed = parseLine(line);
  double result =
      this->m_service.calculateExchangeValue(parsed.first, parsed.second);
  std::ostringstream str;

  str << parsed.first << " => " << parsed.second << " = " << result;

  return str.str();
}

std::pair<std::string, double> CalculateValueUseCase::parseLine(
    const std::string& line) {
  std::size_t pipePos = line.find('|');
  if (pipePos == std::string::npos) {
    throw std::invalid_argument("bad input => " + line);
  }

  std::string dateStr = line.substr(0, pipePos);
  std::string valueStr = line.substr(pipePos + 1);

  strTrim(dateStr);
  strTrim(valueStr);

  if (dateStr.empty() || valueStr.empty()) {
    throw std::invalid_argument("bad input => " + line);
  }

  std::istringstream iss(valueStr);
  double value;
  iss >> value;
  if (iss.fail() || !iss.eof()) {
    throw std::invalid_argument("bad input => " + line);
  }

  if (value > MAX_VALUE) {
    throw std::invalid_argument("too large a number.");
  }

  return std::make_pair(dateStr, value);
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
