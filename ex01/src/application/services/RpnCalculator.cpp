/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RpnCalcaulator.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:28:46 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/10 16:45:35 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "application/services/RpnCalculator.hpp"
#include "domain/repository/IRpnStack.hpp"

#include <cstdlib>
#include <stdexcept>
#include <string>

RpnCalculator::RpnCalculator(IRpnStack& stack) : m_stack(stack) {}

RpnCalculator::RpnCalculator(const RpnCalculator& other)
    : m_stack(other.m_stack) {}

RpnCalculator::~RpnCalculator() {}

RpnCalculator& RpnCalculator::operator=(const RpnCalculator& other) {
  if (this != &other) {
    m_stack = other.m_stack;
  }
  return *this;
}

void RpnCalculator::processToken(const std::string& token){
  if (isOperator(token)) {
    if (this->m_stack.size() < K_MIN_STACK_SIZE) {
      throw std::runtime_error("insuficient operands");
    }

    double leftSide = this->m_stack.pop();
    double rightSide = this->m_stack.pop();
    double result = applyOperation(token, leftSide, rightSide);
    this->m_stack.push(result);
  } else {
    double value = stringToDouble(token);
    this->m_stack.push(value);
  }
}

double RpnCalculator::getResult() {
  if (this->m_stack.empty()) {
    throw std::runtime_error("empty stack");
  }
  if (this->m_stack.size() != 1) {
    throw std::runtime_error("malformed expression");
  }
  return this->m_stack.top();
}

bool RpnCalculator::isOperator(const std::string& token) {
  return token == "+" || token == "-" || token == "*" || token == "/";
}

double RpnCalculator::stringToDouble(const std::string& str) {
  return std::atof(str.c_str());
}

double RpnCalculator::applyOperation(const std::string& operation, double leftSide, double rightSide) {
  if (operation == "+") {
    return leftSide + rightSide;
  }
  if (operation == "-") {
    return leftSide - rightSide;
  }
  if (operation == "*") {
    return leftSide * rightSide;
  }
  if (operation == "/") {
    if (rightSide == 0) {
      throw std::runtime_error("division by zero");
    }
    return leftSide / rightSide;
  }
  throw std::runtime_error("unknow operator");
}
