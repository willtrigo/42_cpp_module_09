/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CsvBitcoinRepository.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 16:03:16 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/10 18:52:55 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/adapters/CsvBitcoinRepository.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>

const std::string CsvBitcoinRepository::DEFAULT_DATABASE =
    "src/infrastructure/resources/data.csv";

CsvBitcoinRepository::CsvBitcoinRepository() { loadData(); }

CsvBitcoinRepository::CsvBitcoinRepository(const CsvBitcoinRepository& other)
    : m_price(other.m_price) {}

CsvBitcoinRepository::~CsvBitcoinRepository() {}

CsvBitcoinRepository& CsvBitcoinRepository::operator=(
    const CsvBitcoinRepository& other) {
  if (this != &other) {
    m_price = other.m_price;
  }
  return *this;
}

double CsvBitcoinRepository::getPrice(const std::string& date) const {
  if (this->m_price.empty()) {
    throw std::runtime_error("Database not loaded");
  }

  std::map<std::string, double>::const_iterator iter =
      this->m_price.upper_bound(date);
  if (iter == this->m_price.begin()) {
    throw std::runtime_error("No price available for date or earlier");
  }
  --iter;
  return iter->second;
}

void CsvBitcoinRepository::loadData() {
  std::ifstream csvFile(DEFAULT_DATABASE.c_str());
  if (!csvFile.is_open()) {
    throw std::runtime_error("Could not open data.csv");
  }

  std::string line;
  std::getline(csvFile, line);
  if (line != "date,exchange_rate") {
    csvFile.close();
    throw std::runtime_error("Invalid header of data.csv");
  }

  while (std::getline(csvFile, line) != 0) {
    if (line.empty()) {
      continue;
    }
    std::pair<std::string, double> parsed = parseCsvLine(line);
    this->m_price[parsed.first] = parsed.second;
  }

  csvFile.close();
}

std::pair<std::string, double> CsvBitcoinRepository::parseCsvLine(
    const std::string& line) {
  std::size_t commaPos = line.find(',');
  if (commaPos == std::string::npos) {
    throw std::invalid_argument("Invalid CSV line: " + line);
  }

  std::string dateStr = line.substr(0, commaPos);
  std::string rateStr = line.substr(commaPos + 1);

  strTrim(dateStr);
  strTrim(rateStr);

  std::istringstream iss(rateStr);
  double rate;
  iss >> rate;
  if (iss.fail() || !iss.eof()) {
    throw std::invalid_argument("Invalid rate in CSV: " + line);
  }

  return std::make_pair(dateStr, rate);
}

void CsvBitcoinRepository::strTrim(std::string& str) {
  std::size_t firstNonSpace = str.find_first_not_of(" \t");
  if (firstNonSpace != std::string::npos) {
    str.erase(0, firstNonSpace);
  }

  std::size_t lastNonSpace = str.find_last_not_of(" \t");
  if (lastNonSpace != std::string::npos) {
    str.erase(lastNonSpace + 1);
  }
}
