/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:55:54 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/10 18:53:00 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/entities/BitcoinExchange.hpp"

#include <cstdio>
#include <stdexcept>
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

const std::string& BitcoinExchange::getDate() const { return this->m_date; }

double BitcoinExchange::getValue() const { return this->m_value; }

bool BitcoinExchange::isValidDate(const std::string& date) {
  if (date.length() != 10) {
    return false;
  }
  if (date.at(4) != '-' || date.at(7) != '-') {
    return false;
  }

  int year;
  int month;
  int day;
  if (std::sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3) {
    return false;
  }

  if (year < 2009 || year > 2025) {
    return false;
  }

  if (year == 2009 && month == 1 && day == 1) {
    return true;
  }

  if (month < 1 || month > 12) {
    return false;
  }

  if (day < 1 || day > 31) {
    return false;
  }

  bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

  int daysInMonth[] = {
      31, 28 + (isLeapYear ? 1 : 0), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  return day <= daysInMonth[month - 1];
}

bool BitcoinExchange::isValidValue(double value) {
  return value >= 0.0 && value <= 1000.0;
}

void BitcoinExchange::validateDate() {
  if (!isValidDate(this->m_date)) {
    throw std::invalid_argument("Invalid date format");
  }
}

void BitcoinExchange::validateValue() {
  if (!isValidValue(this->m_value)) {
    throw std::invalid_argument("Invalid value range");
  }
}
