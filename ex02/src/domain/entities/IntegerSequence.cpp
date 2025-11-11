/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntegerSequence.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:30:19 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/11 20:42:14 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/entities/IntegerSequence.hpp"

#include <vector>

IntegerSequence::IntegerSequence() {}

IntegerSequence::IntegerSequence(const IntegerSequence& other)
    : m_data(other.m_data) {}

IntegerSequence::~IntegerSequence() {}

IntegerSequence& IntegerSequence::operator=(const IntegerSequence& other) {
  if (this != &other) {
    this->m_data = other.m_data;
  }
  return *this;
}

void IntegerSequence::add(int value) {
  if (value < 0) {
    throw InvalidValueException();
  }

  this->m_data.push_back(value);
}

const std::vector<int>& IntegerSequence::getData() const {
  return this->m_data;
}

size_t IntegerSequence::size() const {
  return this->m_data.size();
}

bool IntegerSequence::isEmpty() const {
  return this->m_data.empty();
}

const char* IntegerSequence::InvalidValueException::what() const throw() {
  return "negative values are not allowed";
}
