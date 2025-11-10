/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rpn.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:54:01 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/10 14:29:35 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/entities/Rpn.hpp"

#include <cstdlib>
#include <string>
#include <sstream>

Rpn::Rpn(const std::string& expression) {
  tokenize(expression);
  if (!isValid()) {
    throw std::runtime_error("Invalid expression");
  }
}

Rpn::Rpn(const Rpn& other)
    : m_tokens(other.m_tokens) {}

Rpn::~Rpn() {}

Rpn& Rpn::operator=(const Rpn& other) {
  if (this != &other) {
    this->m_tokens = other.m_tokens;
  }
  return *this;
}

const std::list<std::string>& Rpn::getTokens() const {
  return this->m_tokens;
}

bool Rpn::isValid() const {
  if (this->m_tokens.empty()) {
    return false;
  }

  int operandCount = 0;

  for (std::list<std::string>::const_iterator it = this->m_tokens.begin(); it != this->m_tokens.end(); ++it) {
    const std::string& token = *it;

    if (isNumber(token)) {
      int num = std::atoi(token.c_str());
      if (num < K_MIN_RANGE || num >= K_MAX_RANGE) {
        return false;
      }
      ++operandCount;
    } else if (isOperator(token)) {
      if (operandCount < K_MIN_OPERAND_COUNT) {
        return false;
      }
      --operandCount;
    } else {
      return false;
    }
  }

  return operandCount == K_VALID_OPERAND_COUNT;
}

void Rpn::tokenize(const std::string& expression) {
  std::istringstream iss(expression);
  std::string token;

  while ((iss >> token) != 0) {
    this->m_tokens.push_back(token);
  }
}

bool Rpn::isOperator(const std::string& token) {
  return token == "+" || token == "-" || token == "*" || token == "/";
}

bool Rpn::isNumber(const std::string& token) {
  if (token.empty()) {
    return false;
  }

  size_t index_start = 0;
  if (token.at(index_start) == '-' || token.at(index_start) == '+') {
    if (token.length() == 1) {
      return false;
    }
    index_start = 1;
  }

  for (size_t i = index_start; i < token.length(); ++i) {
    if (std::isdigit(token.at(i)) == 0) {
      return false;
    }
  }

  return true;
}
